# create_symlinks.py 使用说明

用途：在目标目录中为指定的单个文件创建相对软链接（如果目标已存在则跳过并记录日志）。

文件：
- `create_symlinks.py`：脚本，支持 Python 3.14。
- `run_as_admin.bat`：在 Windows 下以管理员权限运行该脚本的快捷方式（会提示 UAC）。

示例用法：

直接运行（Linux / macOS / 已启用开发者模式的 Windows）：

```bash
python scripts/create_symlinks.py -s /path/to/source/file.txt -t /path/to/target/dir
```

Windows（以管理员身份）使用 BAT：

```bat
scripts\run_as_admin.bat "C:\path\to\source\file.txt" "C:\path\to\target\dir"
```

选项：
- `-s/--source`：要创建软链的源文件（必需）。
- `-t/--target-dir`：软链要放置的目标目录（必需）。
- `-n/--name`：可选，自定义软链名称（默认使用源文件名）。
- `--dry-run`：仅模拟，不实际创建。

日志：
- 脚本会在 `scripts/create_symlinks.log` 中记录操作结果和错误信息。

注意事项：
- 仅支持单个文件（不为目录创建软链）。
- 软链使用相对路径，便于仓库迁移或移动。
- 在 Windows 上创建符号链接可能需要管理员权限或开启开发者模式；请用 `run_as_admin.bat` 提升权限。
