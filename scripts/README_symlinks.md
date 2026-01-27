# create_symlinks.py 使用说明

用途：在目标目录中为指定的单个文件创建相对软链接（单文件，优先使用相对路径）。

文件：
- create_symlinks.py：脚本（Python 3.x），在 Windows/macOS/Linux 下可用；Windows 上可能需要管理员权限或启用开发者模式。
- run_as_admin.bat：在 Windows 下以管理员权限运行脚本的快捷批处理（通过提升 PowerShell 权限执行带参数的 Python 命令）。

快速示例：

直接运行（Linux / macOS / Windows 已启用开发者模式 或 已有管理员 PowerShell）：

```bash
python scripts/create_symlinks.py -s /path/to/source/file.txt -t /path/to/target/dir
```

Windows（使用随仓库提供的批处理提升权限并执行）：

```bat
scripts\run_as_admin.bat "C:\path\to\source\file.txt" "C:\path\to\target\dir"
```

命令行选项：
- `-s, --source`：源文件路径（必需）。
- `-t, --target-dir`：目标目录（必需）。
- `-n, --name`：软链名称（可选，默认使用源文件名）。
- `--dry-run`：模拟运行（不实际创建），用于检查行为。
- `--force`：如果目标已存在则强制替换。
- `-v, --verbose`：详细输出（同时在控制台打印并写日志）。

日志：
- 脚本会把运行日志写入与脚本同目录下的 `create_symlinks.log`。

常见返回/错误说明：
- `exists`：目标已存在（可用 `--force` 覆盖）。
- `windows_admin_required`：Windows 上需要管理员权限来创建符号链接（可用 `run_as_admin.bat` 提升）。
- `windows_permission_denied`：Windows 权限不足或未启用开发者模式。

注意事项：
- 本脚本只为单个文件创建软链接，不用于目录。
- 优先尝试使用相对路径作为软链目标；如果源文件不在目标目录树中，会使用绝对路径。
- 在 Windows 上创建符号链接可能受限：可以使用 `run_as_admin.bat` 提升权限，或在系统设置中启用开发者模式以绕过 UAC 要求。

示例（带自定义名称与强制替换）：

```bash
python scripts/create_symlinks.py -s config.yml -t ./scripts -n myconfig.yml --force
```

更多：如需调试或查看详细错误，请使用 `-v` 或查看日志文件。
