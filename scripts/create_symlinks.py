#!/usr/bin/env python3
"""在目标目录中为指定文件创建相对软链接（单文件）。"""

from __future__ import annotations
import argparse
import logging
import os
import sys
import platform
from pathlib import Path
from typing import Optional

LOG_FILE = Path(__file__).with_name('create_symlinks.log')


def setup_logging(verbose: bool = False) -> None:
    """設置日誌，可選控制台輸出"""
    level = logging.DEBUG if verbose else logging.INFO
    handlers = [logging.FileHandler(LOG_FILE)]
    
    if verbose:
        handlers.append(logging.StreamHandler(sys.stdout))
    
    logging.basicConfig(
        level=level,
        format='%(asctime)s [%(levelname)s] %(message)s',
        handlers=handlers
    )


def check_windows_symlink_permission() -> bool:
    """檢查 Windows 下是否有創建軟連接的權限"""
    if platform.system() != "Windows":
        return True
    
    # Windows 需要管理員權限或開發者模式
    try:
        # 檢查是否為管理員
        import ctypes
        is_admin = ctypes.windll.shell32.IsUserAnAdmin() != 0
        
        # 檢查開發者模式（Windows 10+）
        dev_mode = False
        try:
            import winreg
            key = winreg.OpenKey(winreg.HKEY_LOCAL_MACHINE, 
                                r"SOFTWARE\Microsoft\Windows\CurrentVersion\AppModelUnlock")
            value, _ = winreg.QueryValueEx(key, "AllowDevelopmentWithoutDevLicense")
            dev_mode = value == 1
        except:
            pass
        
        return is_admin or dev_mode
    except:
        return False


def create_relative_symlink(
    src: Path,
    dst_dir: Path,
    link_name: Optional[str] = None,
    *,
    dry_run: bool = False,
    force: bool = False
) -> tuple[bool, str]:
    """創建相對軟連接"""
    try:
        src = src.expanduser().resolve(strict=True)
    except FileNotFoundError:
        return False, f"source_not_found: {src}"
    
    if not src.is_file():
        return False, f"not_a_file: {src}"
    
    dst_dir = dst_dir.expanduser()
    try:
        dst_dir = dst_dir.resolve(strict=True)
    except FileNotFoundError:
        return False, f"target_dir_not_found: {dst_dir}"
    
    if not dst_dir.is_dir():
        return False, f"not_a_directory: {dst_dir}"
    
    link_name = link_name or src.name
    link_path = dst_dir / link_name
    
    # 檢查目標是否存在
    if link_path.exists() or link_path.is_symlink():
        if force:
            try:
                if link_path.is_symlink() or link_path.is_file():
                    link_path.unlink()
                else:
                    return False, f"cannot_replace: {link_path}"
            except OSError as e:
                return False, f"unlink_failed: {e}"
        else:
            logging.info(f"Skipped existing: {link_path}")
            return False, "exists"
    
    # 計算相對路徑
    try:
        rel_target = src.relative_to(dst_dir)
    except ValueError:
        # 如果 src 不在 dst_dir 的目錄樹中，使用絕對路徑
        rel_target = src
    
    # Windows 權限檢查
    if platform.system() == "Windows" and not check_windows_symlink_permission():
        return False, "windows_permission_denied"
    
    logging.info(f"Creating symlink: {link_path} -> {rel_target}")
    
    if dry_run:
        return True, "dry-run"
    
    try:
        link_path.symlink_to(rel_target, target_is_directory=False)
        logging.info(f"Created symlink {link_path} -> {rel_target}")
        return True, "created"
    except OSError as e:
        logging.error(f"Failed to create symlink: {e}")
        
        # 如果是權限錯誤，提供建議
        if platform.system() == "Windows" and e.winerror == 1314:
            return False, "windows_admin_required"
        return False, f"os_error: {e}"


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="为单个文件在目标目录中创建相对软链接",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
示例:
  %(prog)s -s /path/to/source.txt -t /path/to/target/dir
  %(prog)s -s config.yml -t ./scripts --name myconfig.yml --force
        """
    )
    parser.add_argument('-s', '--source', required=True, help='源文件路径')
    parser.add_argument('-t', '--target-dir', required=True, help='目标目录')
    parser.add_argument('-n', '--name', help='软链名称（默认使用源文件名）')
    parser.add_argument('--dry-run', action='store_true', help='模拟运行，不实际创建')
    parser.add_argument('--force', action='store_true', help='强制替换已存在的文件')
    parser.add_argument('-v', '--verbose', action='store_true', help='详细输出')
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    setup_logging(args.verbose)
    
    logging.info(f"Script started with args: {vars(args)}")
    
    src = Path(args.source)
    dst_dir = Path(args.target_dir)
    
    ok, reason = create_relative_symlink(
        src, dst_dir, args.name,
        dry_run=args.dry_run,
        force=args.force
    )
    
    if ok:
        if reason == 'dry-run':
            print('✅ 模拟完成：可以创建软链接')
        else:
            print('✅ 软链接创建成功')
        return 0
    else:
        error_messages = {
            'exists': '目标已存在（使用 --force 强制替换）',
            'windows_admin_required': 'Windows 需要管理员权限或启用开发者模式',
            'windows_permission_denied': 'Windows 权限不足',
        }
        
        msg = error_messages.get(reason, f'错误: {reason}')
        print(f'❌ {msg}')
        
        if args.verbose:
            print(f'详细信息请查看日志: {LOG_FILE}')
        
        return 1


if __name__ == '__main__':
    sys.exit(main())