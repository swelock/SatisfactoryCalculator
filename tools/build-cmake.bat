@echo off
echo ====================================
echo  Satisfactory Calculator - CMake Build
echo ====================================
echo.

REM Очистка старых файлов сборки
if exist "build-cmake" rmdir /s /q "build-cmake" 2>nul

echo [1/3] Создание папки сборки...
mkdir build-cmake
cd build-cmake

echo [2/3] Настройка проекта с CMake...
cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
if errorlevel 1 (
    echo ОШИБКА: CMake завершился с ошибкой
    cd ..
    pause
    exit /b 1
)

echo [3/3] Сборка проекта...
mingw32-make
if errorlevel 1 (
    echo ОШИБКА: Сборка завершилась с ошибкой
    cd ..
    pause
    exit /b 1
)

echo [4/4] Проверка результата...
if exist "SatisCalculator.exe" (
    echo ✓ CMake сборка завершена успешно!
    echo ✓ Исполняемый файл: build-cmake\SatisCalculator.exe
    echo.
    echo Запустить приложение? (y/n)
    choice /c yn /n
    if errorlevel 2 goto :end
    if errorlevel 1 start "" "SatisCalculator.exe"
) else (
    echo ✗ Исполняемый файл не найден
    cd ..
    pause
    exit /b 1
)

:end
cd ..
echo.
echo Готово!
pause 