cmake_minimum_required(VERSION 3.16)

# ------------------------------------------------------------
#  Проект SatisCalculator (перенос с qmake на CMake)
# ------------------------------------------------------------
project(SatisCalculator LANGUAGES CXX)

# ------------------------------------------------------------
#  Поиск Qt – пробуем сначала Qt6, затем Qt5
# ------------------------------------------------------------
set(QT_MIN_VERSION 5.15)

find_package(Qt6 ${QT_MIN_VERSION} COMPONENTS Widgets Gui Core QUIET)
if(Qt6_FOUND)
    set(QT_MAJOR_VERSION 6)
    set(QT_PACKAGE Qt6)
else()
    find_package(Qt5 ${QT_MIN_VERSION} COMPONENTS Widgets Gui Core REQUIRED)
    set(QT_MAJOR_VERSION 5)
    set(QT_PACKAGE Qt5)
endif()

# ------------------------------------------------------------
#  Настройки компилятора
# ------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включаем автоматические MOC / UIC / RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Разрешаем большие объектные файлы (MSVC/MinGW bigobj)
if (MSVC OR MINGW)
    add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-Wa,-mbig-obj>)
endif()

# ------------------------------------------------------------
#  Сбор исходников проекта
# ------------------------------------------------------------
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    "*.cpp"
    "*.h"
)

# Файлы ресурсов и форм – CMake найдёт их автоматически через AUTOUIC/AUTORCC,
# но добавляем явный список для читабельности
file(GLOB UI_FILES CONFIGURE_DEPENDS "*.ui")
file(GLOB QRC_FILES CONFIGURE_DEPENDS "*.qrc")

# ------------------------------------------------------------
#  Исполняемый файл
# ------------------------------------------------------------
if (QT_MAJOR_VERSION EQUAL 6)
    qt_add_executable(SatisCalculator ${SRC_FILES} ${UI_FILES} ${QRC_FILES})
    target_link_libraries(SatisCalculator PRIVATE Qt6::Widgets Qt6::Gui Qt6::Core)
else()
    add_executable(SatisCalculator ${SRC_FILES} ${UI_FILES} ${QRC_FILES})
    target_link_libraries(SatisCalculator PRIVATE Qt5::Widgets Qt5::Gui Qt5::Core)
endif()

# ------------------------------------------------------------
#  Дополнительные include-директории (если есть папка include/)
# ------------------------------------------------------------
if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/include)
    target_include_directories(SatisCalculator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
endif()

# ------------------------------------------------------------
#  Устанавливаем файл и его зависимости (install target)
# ------------------------------------------------------------
install(TARGETS SatisCalculator DESTINATION bin)

# ------------------------------------------------------------
#  Удобная цель для запуска windeployqt после сборки (Windows)
# ------------------------------------------------------------
if (WIN32)
    add_custom_command(TARGET SatisCalculator POST_BUILD
        COMMAND ${QT_PACKAGE}::windeployqt --no-angle --no-opengl-sw --no-translations $<TARGET_FILE_DIR:SatisCalculator>
        COMMENT "Running windeployqt ...")
endif() 