@echo off
REM 用法: run_as_admin.bat <source> <target_dir> [link_name]
REM 在管理员权限下调用同目录下的 create_symlinks.py
setlocal enabledelayedexpansion
if "%1"=="" (
  echo Usage: run_as_admin.bat ^"path\\to\\source^" ^"path\\to\\target_dir^" [link_name]
  exit /b 1
)
set PY=python
set SCRIPT=%~dp0create_symlinks.py
powershell -Command "Start-Process -FilePath '%PY%' -ArgumentList ('''%SCRIPT%''','''%~1''','''%~2''','''%~3''') -Verb runAs"
