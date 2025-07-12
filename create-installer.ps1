# ================================================
# Satisfactory Calculator Pro - Installer Creator
# ================================================

Write-Host "================================================" -ForegroundColor Cyan
Write-Host " Satisfactory Calculator Pro - Installer Creator" -ForegroundColor Cyan
Write-Host "================================================" -ForegroundColor Cyan
Write-Host ""

# Проверка наличия портативной версии
if (-not (Test-Path "portable\SatisCalculator.exe")) {
    Write-Host "ОШИБКА: Портативная версия не найдена!" -ForegroundColor Red
    Write-Host "Запустите сначала: .\build-portable.bat" -ForegroundColor Yellow
    exit 1
}

# Создание самораспаковывающегося архива
Write-Host "[1/3] Создание самораспаковывающегося установщика..." -ForegroundColor Green

# Создание установочного скрипта
$installScript = @"
@echo off
echo ================================================
echo  Satisfactory Calculator Pro - Установка
echo ================================================
echo.

REM Определяем папку установки
set "INSTALL_DIR=%PROGRAMFILES%\SatisfactoryCalculatorPro"
if not exist "%INSTALL_DIR%" mkdir "%INSTALL_DIR%"

echo Установка в: %INSTALL_DIR%
echo.

REM Копируем файлы
echo Копирование файлов...
xcopy /E /Y /Q "%~dp0portable\*" "%INSTALL_DIR%\"

REM Создаем ярлык на рабочем столе
echo Создание ярлыка на рабочем столе...
powershell -Command "& {`$ws = New-Object -ComObject WScript.Shell; `$s = `$ws.CreateShortcut('%USERPROFILE%\Desktop\Satisfactory Calculator Pro.lnk'); `$s.TargetPath = '%INSTALL_DIR%\SatisCalculator.exe'; `$s.WorkingDirectory = '%INSTALL_DIR%'; `$s.Description = 'Professional production chain calculator for Satisfactory'; `$s.Save()}"

REM Создаем ярлык в меню Пуск
echo Создание ярлыка в меню Пуск...
if not exist "%APPDATA%\Microsoft\Windows\Start Menu\Programs\Satisfactory Calculator Pro" mkdir "%APPDATA%\Microsoft\Windows\Start Menu\Programs\Satisfactory Calculator Pro"
powershell -Command "& {`$ws = New-Object -ComObject WScript.Shell; `$s = `$ws.CreateShortcut('%APPDATA%\Microsoft\Windows\Start Menu\Programs\Satisfactory Calculator Pro\Satisfactory Calculator Pro.lnk'); `$s.TargetPath = '%INSTALL_DIR%\SatisCalculator.exe'; `$s.WorkingDirectory = '%INSTALL_DIR%'; `$s.Description = 'Professional production chain calculator for Satisfactory'; `$s.Save()}"

REM Создаем деинсталлятор
echo Создание деинсталлятора...
echo @echo off > "%INSTALL_DIR%\Uninstall.bat"
echo echo Удаление Satisfactory Calculator Pro... >> "%INSTALL_DIR%\Uninstall.bat"
echo rmdir /s /q "%INSTALL_DIR%" >> "%INSTALL_DIR%\Uninstall.bat"
echo del "%USERPROFILE%\Desktop\Satisfactory Calculator Pro.lnk" 2^>nul >> "%INSTALL_DIR%\Uninstall.bat"
echo rmdir /s /q "%APPDATA%\Microsoft\Windows\Start Menu\Programs\Satisfactory Calculator Pro" 2^>nul >> "%INSTALL_DIR%\Uninstall.bat"
echo echo Удаление завершено! >> "%INSTALL_DIR%\Uninstall.bat"
echo pause >> "%INSTALL_DIR%\Uninstall.bat"

REM Регистрируем в Programs and Features
echo Регистрация в Programs and Features...
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\SatisfactoryCalculatorPro" /v DisplayName /t REG_SZ /d "Satisfactory Calculator Pro" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\SatisfactoryCalculatorPro" /v DisplayVersion /t REG_SZ /d "1.0.0" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\SatisfactoryCalculatorPro" /v Publisher /t REG_SZ /d "SatisCalc Team" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\SatisfactoryCalculatorPro" /v InstallLocation /t REG_SZ /d "%INSTALL_DIR%" /f
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\SatisfactoryCalculatorPro" /v UninstallString /t REG_SZ /d "%INSTALL_DIR%\Uninstall.bat" /f

echo.
echo ================================================
echo  Установка завершена успешно!
echo ================================================
echo.
echo Приложение установлено в: %INSTALL_DIR%
echo Ярлыки созданы на рабочем столе и в меню Пуск
echo.
echo Запустить приложение сейчас? (y/n)
choice /c yn /n
if errorlevel 2 goto :end
if errorlevel 1 start "" "%INSTALL_DIR%\SatisCalculator.exe"

:end
echo.
echo Готово!
pause
"@

# Сохраняем установочный скрипт
$installScript | Out-File -FilePath "install.bat" -Encoding ASCII

Write-Host "[2/3] Создание самораспаковывающегося архива..." -ForegroundColor Green

# Создание SFX архива с помощью PowerShell
$sfxScript = @"
# Самораспаковывающийся установщик
Add-Type -AssemblyName System.IO.Compression.FileSystem

`$tempDir = [System.IO.Path]::GetTempPath() + "SatisCalc_" + [System.Guid]::NewGuid().ToString()
New-Item -ItemType Directory -Path `$tempDir -Force | Out-Null

try {
    # Извлекаем архив
    `$archiveData = [System.Convert]::FromBase64String('$(Get-Content "SatisfactoryCalculatorPro-v1.0-Portable.zip" -Encoding Byte | ForEach-Object { [System.Convert]::ToBase64String($_) })')
    [System.IO.File]::WriteAllBytes("`$tempDir\portable.zip", `$archiveData)
    
    [System.IO.Compression.ZipFile]::ExtractToDirectory("`$tempDir\portable.zip", `$tempDir)
    
    # Запускаем установку
    & "`$tempDir\install.bat"
}
finally {
    # Очистка
    Remove-Item -Path `$tempDir -Recurse -Force -ErrorAction SilentlyContinue
}
"@

Write-Host "[3/3] Создание итогового установщика..." -ForegroundColor Green

# Создаем финальный установщик
$finalInstaller = @"
@echo off
title Satisfactory Calculator Pro - Installer

REM Проверка прав администратора
net session >nul 2>&1
if %errorLevel% neq 0 (
    echo Для установки требуются права администратора!
    echo Перезапустите от имени администратора.
    pause
    exit /b 1
)

echo ================================================
echo  Satisfactory Calculator Pro v1.0 - Installer
echo ================================================
echo.
echo Этот установщик установит Satisfactory Calculator Pro
echo на ваш компьютер.
echo.
echo Нажмите любую клавишу для продолжения...
pause >nul

REM Создаем временную папку
set "TEMP_DIR=%TEMP%\SatisCalc_%RANDOM%"
mkdir "%TEMP_DIR%"

REM Извлекаем портативную версию
echo Извлечение файлов...
powershell -Command "Expand-Archive -Path '%~dp0SatisfactoryCalculatorPro-v1.0-Portable.zip' -DestinationPath '%TEMP_DIR%' -Force"

REM Запускаем установку
call "%~dp0install.bat"

REM Очистка
rmdir /s /q "%TEMP_DIR%" 2>nul
"@

# Сохраняем финальный установщик
$finalInstaller | Out-File -FilePath "SatisfactoryCalculatorPro-Setup.bat" -Encoding ASCII

Write-Host ""
Write-Host "================================================" -ForegroundColor Green
Write-Host " Установщик создан успешно!" -ForegroundColor Green
Write-Host "================================================" -ForegroundColor Green
Write-Host ""
Write-Host "Файлы:" -ForegroundColor Yellow
Write-Host "- SatisfactoryCalculatorPro-Setup.bat (Установщик)" -ForegroundColor White
Write-Host "- SatisfactoryCalculatorPro-v1.0-Portable.zip (Портативная версия)" -ForegroundColor White
Write-Host ""
Write-Host "Для установки:" -ForegroundColor Yellow
Write-Host "1. Запустите SatisfactoryCalculatorPro-Setup.bat от имени администратора" -ForegroundColor White
Write-Host "2. Следуйте инструкциям" -ForegroundColor White
Write-Host ""
Write-Host "Готово!" -ForegroundColor Green 