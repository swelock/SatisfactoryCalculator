@echo off
echo ================================
echo  Satisfactory Calculator - Build
echo ================================
echo.

REM Очистка старых файлов сборки
if exist "build" rmdir /s /q "build" 2>nul
if exist "release" rmdir /s /q "release" 2>nul
if exist "debug" rmdir /s /q "debug" 2>nul

echo [1/3] Настройка проекта с qmake...
qmake satiscalculator.pro
if errorlevel 1 (
    echo ОШИБКА: qmake завершился с ошибкой
    pause
    exit /b 1
)

echo [2/3] Сборка проекта...
mingw32-make
if errorlevel 1 (
    echo ОШИБКА: Сборка завершилась с ошибкой
    pause
    exit /b 1
)

echo [3/3] Проверка результата...
if exist "release\satiscalculator.exe" (
    echo ✓ Сборка завершена успешно!
    echo ✓ Исполняемый файл: release\satiscalculator.exe
    echo.
    echo Запустить приложение? (y/n)
    choice /c yn /n
    if errorlevel 2 goto :end
    if errorlevel 1 start "" "release\satiscalculator.exe"
) else (
    echo ✗ Исполняемый файл не найден
    pause
    exit /b 1
)

:end
echo.
echo Готово!
pause 