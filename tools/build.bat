@echo off
echo =======================================
echo  Satisfactory Calculator - Сборка
echo =======================================

echo Поиск Qt Creator...
if exist "C:\Qt\Tools\QtCreator\bin\qtcreator.exe" (
    echo Найден Qt Creator в стандартной папке
    start "" "C:\Qt\Tools\QtCreator\bin\qtcreator.exe" "satiscalculator.pro"
    goto end
)

if exist "C:\Program Files\Qt\Tools\QtCreator\bin\qtcreator.exe" (
    echo Найден Qt Creator в Program Files
    start "" "C:\Program Files\Qt\Tools\QtCreator\bin\qtcreator.exe" "satiscalculator.pro"
    goto end
)

echo Qt Creator не найден в стандартных папках.
echo.
echo ИНСТРУКЦИЯ ПО СБОРКЕ:
echo 1. Откройте Qt Creator вручную
echo 2. Откройте файл: satiscalculator.pro
echo 3. Нажмите "Сборка" -> "Очистить проект"
echo 4. Нажмите "Сборка" -> "Пересобрать проект"
echo 5. Запустите проект (F5)
echo.
echo Исправленные проблемы:
echo - Удален конфликт UI файлов
echo - Исправлен порядок инициализации
echo - Добавлена отладочная информация
echo.
pause

:end 