function Controller()
{
    installer.autoRejectMessageBoxes();
    installer.installationFinished.connect(function() {
        gui.clickButton(buttons.NextButton);
    })
}

Controller.prototype.WelcomePageCallback = function()
{
    // Проверяем системные требования
    if (systemInfo.productType === "windows") {
        var page = gui.currentPageWidget();
        page.title = "Добро пожаловать в установщик Satisfactory Calculator Pro";
        page.subTitle = "Этот мастер поможет вам установить Satisfactory Calculator Pro v1.0.0";
    }
    
    gui.clickButton(buttons.NextButton);
}

Controller.prototype.CredentialsPageCallback = function()
{
    gui.clickButton(buttons.NextButton);
}

Controller.prototype.IntroductionPageCallback = function()
{
    gui.clickButton(buttons.NextButton);
}

Controller.prototype.TargetDirectoryPageCallback = function()
{
    // Устанавливаем папку по умолчанию
    var widget = gui.currentPageWidget();
    
    if (systemInfo.productType === "windows") {
        widget.TargetDirectoryLineEdit.setText("C:\\Program Files\\SatisfactoryCalculatorPro");
    }
    
    gui.clickButton(buttons.NextButton);
}

Controller.prototype.ComponentSelectionPageCallback = function()
{
    var widget = gui.currentPageWidget();
    widget.selectAll();
    gui.clickButton(buttons.NextButton);
}

Controller.prototype.LicenseAgreementPageCallback = function()
{
    var widget = gui.currentPageWidget();
    if (widget.AcceptLicenseRadioButton) {
        widget.AcceptLicenseRadioButton.setChecked(true);
    }
    gui.clickButton(buttons.NextButton);
}

Controller.prototype.StartMenuDirectoryPageCallback = function()
{
    gui.clickButton(buttons.NextButton);
}

Controller.prototype.ReadyForInstallationPageCallback = function()
{
    gui.clickButton(buttons.NextButton);
}

Controller.prototype.PerformInstallationPageCallback = function()
{
    gui.clickButton(buttons.NextButton);
}

Controller.prototype.FinishedPageCallback = function()
{
    var checkBoxForm = gui.currentPageWidget().LaunchCheckBoxForm;
    if (checkBoxForm && checkBoxForm.launchCheckBox) {
        checkBoxForm.launchCheckBox.checked = true;
    }
    gui.clickButton(buttons.FinishButton);
} 