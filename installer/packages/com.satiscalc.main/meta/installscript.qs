function Component()
{
    // Конструктор компонента
}

Component.prototype.createOperations = function()
{
    // Вызываем базовую операцию установки
    component.createOperations();

    // Создаем ярлык на рабочем столе
    if (systemInfo.productType === "windows") {
        component.addOperation("CreateShortcut", 
            "@TargetDir@/SatisCalculator.exe", 
            "@DesktopDir@/Satisfactory Calculator Pro.lnk",
            "workingDirectory=@TargetDir@",
            "iconPath=@TargetDir@/SatisCalculator.exe",
            "iconId=0",
            "description=Satisfactory Calculator Pro - Калькулятор производственных цепочек");

        // Создаем ярлык в меню "Пуск"
        component.addOperation("CreateShortcut", 
            "@TargetDir@/SatisCalculator.exe", 
            "@StartMenuDir@/Satisfactory Calculator Pro.lnk",
            "workingDirectory=@TargetDir@",
            "iconPath=@TargetDir@/SatisCalculator.exe",
            "iconId=0",
            "description=Satisfactory Calculator Pro - Калькулятор производственных цепочек");

        // Регистрируем программу в системе
        component.addOperation("RegisterFileType", 
            "satiscalc",
            "@TargetDir@/SatisCalculator.exe '%1'",
            "Satisfactory Calculator Pro Project File",
            "text/plain",
            "@TargetDir@/SatisCalculator.exe,0",
            "ProgId=SatisCalc.ProjectFile");

        // Добавляем в список установленных программ
        component.addOperation("GlobalConfig", 
            "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\SatisfactoryCalculatorPro",
            "DisplayName", "Satisfactory Calculator Pro");
        
        component.addOperation("GlobalConfig", 
            "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\SatisfactoryCalculatorPro",
            "DisplayVersion", "1.0.0");
            
        component.addOperation("GlobalConfig", 
            "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\SatisfactoryCalculatorPro",
            "Publisher", "SatisCalc Team");
            
        component.addOperation("GlobalConfig", 
            "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\SatisfactoryCalculatorPro",
            "InstallLocation", "@TargetDir@");
            
        component.addOperation("GlobalConfig", 
            "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\SatisfactoryCalculatorPro",
            "UninstallString", "@TargetDir@\\maintenancetool.exe");
    }
}

Component.prototype.isDefault = function()
{
    return true;
}

Component.prototype.createOperationsForArchive = function(archive)
{
    component.createOperationsForArchive(archive);
} 