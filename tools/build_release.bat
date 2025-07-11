@echo off
set "PATH=C:\msys64\mingw64\bin;%PATH%"
echo --- Running qmake ---
C:\msys64\mingw64\bin\qmake.exe
if %errorlevel% neq 0 (
    echo QMake failed
    pause
    exit /b %errorlevel%
)

echo.
echo --- Running mingw32-make ---
C:\msys64\mingw64\bin\mingw32-make.exe -f Makefile.Release
if %errorlevel% neq 0 (
    echo Make failed
    pause
    exit /b %errorlevel%
)

echo.
echo --- Build successful! ---
pause 