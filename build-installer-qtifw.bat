@echo off
echo ========================================
echo  Создание установщика Satisfactory Calculator Pro
echo  Используется Qt Installer Framework
echo ========================================

:: Проверяем наличие binarycreator
set BINARYCREATOR_PATH=C:\Qt\QtIFW-4.4.0\bin\binarycreator.exe
if exist "%BINARYCREATOR_PATH%" (
    goto :found_binarycreator
)

where binarycreator >nul 2>nul
if %ERRORLEVEL% EQU 0 (
    set BINARYCREATOR_PATH=binarycreator
    goto :found_binarycreator
)

echo ОШИБКА: binarycreator не найден!
echo Проверьте установку Qt Installer Framework:
echo - Путь: C:\Qt\QtIFW-4.4.0\bin\binarycreator.exe
echo - Или убедитесь, что он добавлен в PATH
echo Скачать можно здесь: https://download.qt.io/official_releases/qt-installer-framework/
pause
exit /b 1

:found_binarycreator

:: Проверяем наличие структуры installer
if not exist "installer\config\config.xml" (
    echo ОШИБКА: Не найден файл installer\config\config.xml
    echo Убедитесь, что структура установщика создана правильно.
    pause
    exit /b 1
)

if not exist "installer\packages\com.satiscalc.main\data\SatisCalculator.exe" (
    echo ОШИБКА: Не найден файл SatisCalculator.exe в папке data
    echo Убедитесь, что все файлы скопированы в installer\packages\com.satiscalc.main\data\
    pause
    exit /b 1
)

:: Создаем папку output если её нет
if not exist "output" mkdir output

:: Удаляем старый установщик если он есть
if exist "output\SatisfactoryCalculatorPro-Setup.exe" (
    echo Удаляем старый установщик...
    del "output\SatisfactoryCalculatorPro-Setup.exe"
)

echo.
echo Создание установщика...
echo Это может занять несколько минут...

:: Создаем установщик
"%BINARYCREATOR_PATH%" --offline-only -c installer\config\config.xml -p installer\packages output\SatisfactoryCalculatorPro-Setup.exe

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ========================================
    echo  УСПЕШНО! Установщик создан:
    echo  output\SatisfactoryCalculatorPro-Setup.exe
    echo ========================================
    
    :: Проверяем размер файла
    for %%I in (output\SatisfactoryCalculatorPro-Setup.exe) do echo Размер файла: %%~zI байт
    
    echo.
    echo Установщик готов к распространению!
    echo Протестируйте его перед публикацией.
) else (
    echo.
    echo ========================================
    echo  ОШИБКА! Не удалось создать установщик
    echo  Код ошибки: %ERRORLEVEL%
    echo ========================================
    echo.
    echo Возможные причины:
    echo - Отсутствуют необходимые файлы в папке data
    echo - Ошибки в конфигурационных XML файлах
    echo - Недостаточно места на диске
    echo - Проблемы с Qt Installer Framework
)

echo.
pause 