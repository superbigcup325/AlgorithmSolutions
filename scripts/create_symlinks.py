#!/usr/bin/env python3
"""在目标目录中为指定文件创建相对软链接（单文件）。

用法示例：
  python create_symlinks.py -s /path/to/source.txt -t /path/to/target/dir

说明：
- 仅支持单个文件（非目录）。
- 默认行为：若目标位置存在同名项则跳过并记录日志。
- 软链使用相对路径（从链接所在目录指向源文件）。
"""

from __future__ import annotations
import argparse
import logging
import os
import sys
from pathlib import Path

LOG_FILE = Path(__file__).with_name('create_symlinks.log')


def setup_logging():
    logging.basicConfig(
        filename=str(LOG_FILE),
        level=logging.INFO,
        format='%(asctime)s %(levelname)s: %(message)s',
    )


def create_relative_symlink(src: Path, dst_dir: Path, link_name: str | None = None, *, dry_run: bool = False) -> tuple[bool, str]:
    src = src.expanduser().resolve() if src.exists() else src.expanduser()
    dst_dir = dst_dir.expanduser()

    if not src.exists() or not src.is_file():
        return False, f"source_not_found: {src}"
    if not dst_dir.exists() or not dst_dir.is_dir():
        return False, f"target_dir_not_found: {dst_dir}"

    link_name = link_name or src.name
    link_path = dst_dir / link_name

    if link_path.exists() or link_path.is_symlink():
        logging.info(f"Skipped existing target: {link_path}")
        return False, "exists"

    # compute relative path from link location (dst_dir) to the source file
    rel_target = os.path.relpath(str(src), start=str(dst_dir))

    logging.info(f"Creating symlink: {link_path} -> {rel_target}")
    if dry_run:
        return True, "dry-run"

    try:
        os.symlink(rel_target, str(link_path), target_is_directory=False)
        logging.info(f"Created symlink {link_path} -> {rel_target}")
        return True, "created"
    except OSError as e:
        logging.error(f"Failed to create symlink {link_path} -> {rel_target}: {e}")
        return False, f"error: {e}"


def parse_args() -> argparse.Namespace:
    p = argparse.ArgumentParser(description="为单个文件在目标目录中创建相对软链接（跳过已存在项，并记录日志）")
    p.add_argument('-s', '--source', required=True, help='源文件路径')
    p.add_argument('-t', '--target-dir', required=True, help='目标目录（在此创建软链）')
    p.add_argument('-n', '--name', help='软链名称（可选，默认使用源文件名）')
    p.add_argument('--dry-run', action='store_true', help='仅模拟，不实际创建')
    return p.parse_args()


def main() -> int:
    args = parse_args()
    setup_logging()

    src = Path(args.source)
    dst_dir = Path(args.target_dir)

    ok, reason = create_relative_symlink(src, dst_dir, args.name, dry_run=args.dry_run)

    if ok:
        if reason == 'dry-run':
            print('Dry run: OK (no changes made).')
        else:
            print('Created symlink successfully.')
        return 0
    else:
        if reason == 'exists':
            print(f'Skipped: target already exists. See log: {LOG_FILE}')
            return 0
        elif reason.startswith('source_not_found') or reason.startswith('target_dir_not_found'):
            print(f'Error: {reason}')
            return 2
        else:
            print(f'Failed to create symlink: {reason} (see log: {LOG_FILE})')
            return 1


if __name__ == '__main__':
    raise SystemExit(main())
