@echo off
setlocal enabledelayedexpansion

REM Satisfactory Calculator Build Script for Windows (qmake)
REM Usage: scripts\build.bat [debug|release] [clean]

echo.
echo 🏭 Satisfactory Calculator Build Script (qmake)
echo ==============================================

REM Configuration
set "PROJECT_ROOT=%~dp0\.."
set "BUILD_TYPE=%~1"
set "CLEAN=%~2"

REM Default to release if no build type specified
if "%BUILD_TYPE%"=="" set "BUILD_TYPE=release"

REM Validate build type
if /i "%BUILD_TYPE%"=="debug" set "BUILD_TYPE=debug"
if /i "%BUILD_TYPE%"=="release" set "BUILD_TYPE=release"

if not "%BUILD_TYPE%"=="debug" if not "%BUILD_TYPE%"=="release" (
    echo ❌ Invalid build type: %BUILD_TYPE%
    echo 💡 Usage: %0 [debug^|release] [clean]
    exit /b 1
)

echo 📋 Build Type: %BUILD_TYPE%

cd /d "%PROJECT_ROOT%"

REM Clean build files if requested
if /i "%CLEAN%"=="clean" (
    echo 🧹 Cleaning build files...
    nmake clean >nul 2>&1 || make clean >nul 2>&1 || echo Clean completed
    del /q Makefile Makefile.Debug Makefile.Release >nul 2>&1
    del /q *.o moc_*.cpp ui_*.h >nul 2>&1
    rmdir /s /q debug >nul 2>&1
    rmdir /s /q release >nul 2>&1
)

REM Detect number of CPU cores
for /f "tokens=2 delims==" %%i in ('wmic cpu get NumberOfLogicalProcessors /value ^| find "="') do set CORES=%%i
if "%CORES%"=="" set CORES=4

echo 🔧 Configuring with qmake...

REM Check if qmake is available
where qmake >nul 2>&1
if errorlevel 1 (
    echo ❌ qmake not found in PATH
    echo 💡 Please install Qt development tools and add them to PATH
    exit /b 1
)

REM Generate Makefile with qmake
if "%BUILD_TYPE%"=="debug" (
    qmake CONFIG+=debug satiscalculator.pro
) else (
    qmake CONFIG+=release satiscalculator.pro
)

if errorlevel 1 (
    echo ❌ qmake configuration failed
    exit /b 1
)

echo 🔨 Building with %CORES% cores...

REM Try nmake first (Visual Studio), then make (MinGW)
nmake -j%CORES% >nul 2>&1
if errorlevel 1 (
    make -j%CORES%
    if errorlevel 1 (
        echo ❌ Build failed
        exit /b 1
    )
)

echo ✅ Build completed successfully!

REM Check if executable was created
set "EXECUTABLE="
if "%BUILD_TYPE%"=="debug" (
    if exist "debug\satiscalculator.exe" set "EXECUTABLE=debug\satiscalculator.exe"
    if exist "satiscalculator.exe" if "%EXECUTABLE%"=="" set "EXECUTABLE=satiscalculator.exe"
) else (
    if exist "release\satiscalculator.exe" set "EXECUTABLE=release\satiscalculator.exe"
    if exist "satiscalculator.exe" if "%EXECUTABLE%"=="" set "EXECUTABLE=satiscalculator.exe"
)

if not "%EXECUTABLE%"=="" (
    echo 🎯 Executable created: %EXECUTABLE%
    
    REM Show file size
    for %%A in ("%EXECUTABLE%") do (
        set "SIZE=%%~zA"
        set /a "SIZE_MB=!SIZE! / 1048576"
        echo 📏 Size: !SIZE_MB! MB
    )
) else (
    echo ⚠️  Executable not found in expected location
)

echo.
echo 🚀 Build process completed!
echo 💡 To run the application:
if not "%EXECUTABLE%"=="" (
    echo    %EXECUTABLE%
) else (
    echo    satiscalculator.exe
)

endlocal
pause 