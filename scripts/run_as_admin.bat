@echo off
REM Usage: run_as_admin.bat <source> <target_dir> [additional args]
REM 以管理员权限在新的 PowerShell 窗口中运行 create_symlinks.py，并将参数透传给脚本

if "%~1"=="" (
  echo Usage: %~nx0 ^"path\to\source^" ^"path\to\target_dir^" [--name NAME] [--force] [--dry-run] [-v]
  exit /b 1
)

set "SCRIPT=%~dp0create_symlinks.py"
set "PY=python"

REM 构造要在提升的 PowerShell 中执行的命令行（将所有参数透传）
set "CMD=python "%SCRIPT%" -s "%~1" -t "%~2" %*"

REM 启动提升的 PowerShell 并执行命令
powershell -NoProfile -Command "Start-Process powershell -ArgumentList '-NoProfile -Command "%CMD%"' -Verb runAs"

exit /b 0
