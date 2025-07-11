QT       += widgets core gui

TARGET = satiscalculator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code to new APIs.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only for a specific module:
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# C++17 support
CONFIG += c++17

# Include directories
INCLUDEPATH += include

# Optimization flags
CONFIG(release, debug|release) {
    QMAKE_CXXFLAGS_RELEASE += -O3 -march=native
    DEFINES += QT_NO_DEBUG_OUTPUT
}

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/game_data.cpp \
    src/game_data_ext.cpp \
    src/complete_alternates.cpp \
    src/calculator_engine.cpp \
    src/recipe_manager.cpp

HEADERS += \
    include/mainwindow.h \
    include/game_data.h \
    include/game_data_ext.h \
    include/complete_alternates.h \
    include/calculator_engine.h \
    include/recipe_manager.h

FORMS += \
    mainwindow.ui 