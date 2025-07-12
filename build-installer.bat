@echo off
echo ================================================
echo  Satisfactory Calculator Pro - Windows Installer
echo ================================================
echo.

REM Проверяем наличие Qt IFW
echo [1/6] Проверка Qt Installer Framework...
where /q binarycreator
if errorlevel 1 (
    echo ОШИБКА: Qt Installer Framework не найден!
    echo Скачайте и установите Qt IFW с https://doc.qt.io/qtinstallerframework/
    echo Или убедитесь, что путь к Qt IFW добавлен в PATH
    pause
    exit /b 1
)

REM Очистка старых файлов
echo [2/6] Очистка старых файлов сборки...
if exist "build" rmdir /s /q "build" 2>nul
if exist "_CPack_Packages" rmdir /s /q "_CPack_Packages" 2>nul
if exist "*.exe" del /q "*.exe" 2>nul

REM Настройка проекта
echo [3/6] Настройка проекта с CMake...
cmake -B build -DCMAKE_BUILD_TYPE=Release -G "MinGW Makefiles"
if errorlevel 1 (
    echo ОШИБКА: CMake конфигурация завершилась с ошибкой
    pause
    exit /b 1
)

REM Сборка проекта
echo [4/6] Сборка проекта...
cmake --build build --config Release
if errorlevel 1 (
    echo ОШИБКА: Сборка завершилась с ошибкой
    pause
    exit /b 1
)

REM Установка в временную директорию
echo [5/6] Установка в временную директорию...
cmake --install build --prefix build/_install
if errorlevel 1 (
    echo ОШИБКА: Установка завершилась с ошибкой
    pause
    exit /b 1
)

REM Создание установщика
echo [6/6] Создание Windows установщика...
cd build
cpack -G IFW
if errorlevel 1 (
    echo ОШИБКА: Создание установщика завершилось с ошибкой
    cd ..
    pause
    exit /b 1
)

cd ..

REM Поиск созданного установщика
echo.
echo ============================================
echo  Установщик создан успешно!
echo ============================================

for %%f in (build\*.exe) do (
    echo ✓ Файл установщика: %%f
    echo ✓ Размер: 
    dir "%%f" | find "%%~nxf"
    echo.
    echo Установщик готов к использованию!
    echo Для подписания кода используйте: signtool sign /f certificate.pfx "%%f"
    echo.
    set INSTALLER_PATH=%%f
)

if defined INSTALLER_PATH (
    echo Запустить установщик для тестирования? (y/n)
    choice /c yn /n
    if errorlevel 2 goto :end
    if errorlevel 1 start "" "%INSTALLER_PATH%"
)

:end
echo.
echo Готово!
pause 