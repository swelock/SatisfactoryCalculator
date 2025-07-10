#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Starting application..." << std::endl;
    
    QApplication a(argc, argv);
    std::cout << "QApplication created" << std::endl;
    
    try {
        MainWindow w;
        std::cout << "MainWindow created" << std::endl;
        
        w.show();
        std::cout << "MainWindow shown" << std::endl;
        
        return a.exec();
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
        return -1;
    } catch (...) {
        std::cout << "Unknown exception caught!" << std::endl;
        return -1;
    }
} 