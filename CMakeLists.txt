cmake_minimum_required(VERSION 3.16)

# ------------------------------------------------------------
#  Проект SatisCalculator (перенос с qmake на CMake)
# ------------------------------------------------------------
project(SatisCalculator 
    VERSION 1.0.0
    DESCRIPTION "Professional production chain calculator for Satisfactory game"
    LANGUAGES CXX)

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
set(SRC_FILES
    src/main.cpp
    src/mainwindow.cpp
    src/calculator_engine.cpp
    src/recipe_manager.cpp
    src/game_data.cpp
    src/game_data_ext.cpp
    src/complete_alternates.cpp
)

set(HEADER_FILES
    include/mainwindow.h
    include/calculator_engine.h
    include/recipe_manager.h
    include/game_data.h
    include/game_data_ext.h
    include/complete_alternates.h
)

# Файлы ресурсов и форм – CMake найдёт их автоматически через AUTOUIC/AUTORCC,
# но добавляем явный список для читабельности
file(GLOB UI_FILES CONFIGURE_DEPENDS "*.ui")
file(GLOB QRC_FILES CONFIGURE_DEPENDS "*.qrc")

# ------------------------------------------------------------
#  Исполняемый файл
# ------------------------------------------------------------
if (QT_MAJOR_VERSION EQUAL 6)
    qt_add_executable(SatisCalculator ${SRC_FILES} ${HEADER_FILES} ${UI_FILES} ${QRC_FILES})
    target_link_libraries(SatisCalculator PRIVATE Qt6::Widgets Qt6::Gui Qt6::Core)
else()
    add_executable(SatisCalculator ${SRC_FILES} ${HEADER_FILES} ${UI_FILES} ${QRC_FILES})
    target_link_libraries(SatisCalculator PRIVATE Qt5::Widgets Qt5::Gui Qt5::Core)
endif()

# ------------------------------------------------------------
#  Дополнительные include-директории
# ------------------------------------------------------------
target_include_directories(SatisCalculator PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# ------------------------------------------------------------
#  Установка исполняемого файла
# ------------------------------------------------------------
install(TARGETS SatisCalculator 
    RUNTIME DESTINATION bin
    COMPONENT Runtime)

# ------------------------------------------------------------
#  Qt развертывание для Windows
# ------------------------------------------------------------
if (WIN32 AND QT_MAJOR_VERSION EQUAL 6)
    # Генерируем скрипт развертывания Qt
    qt_generate_deploy_app_script(
        TARGET SatisCalculator
        OUTPUT_SCRIPT deploy_script
        NO_UNSUPPORTED_PLATFORM_ERROR
    )
    
    # Выполняем развертывание после установки
    install(SCRIPT ${deploy_script} COMPONENT Runtime)
endif()

# ------------------------------------------------------------
#  Настройка CPack для создания установщика
# ------------------------------------------------------------
set(CPACK_GENERATOR "IFW")
set(CPACK_PACKAGE_NAME "Satisfactory Calculator Pro")
set(CPACK_PACKAGE_VENDOR "SatisCalc Team")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Professional production chain calculator for Satisfactory game")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_PACKAGE_INSTALL_DIRECTORY "SatisfactoryCalculatorPro")

# Настройки Qt IFW
set(CPACK_IFW_PACKAGE_TITLE "Satisfactory Calculator Pro")
set(CPACK_IFW_PACKAGE_PUBLISHER "SatisCalc Team")
set(CPACK_IFW_PACKAGE_DESCRIPTION "Professional production chain calculator for Satisfactory game with modern UI and comprehensive recipe support.")
set(CPACK_IFW_PACKAGE_ICON "${CMAKE_CURRENT_SOURCE_DIR}/assets/icons/calculator.ico")
set(CPACK_IFW_PACKAGE_WINDOW_ICON "${CMAKE_CURRENT_SOURCE_DIR}/assets/icons/calculator.ico")
set(CPACK_IFW_PACKAGE_LOGO "${CMAKE_CURRENT_SOURCE_DIR}/assets/icons/calculator.png")
set(CPACK_IFW_PACKAGE_WIZARD_STYLE "Modern")
set(CPACK_IFW_PACKAGE_WIZARD_DEFAULT_WIDTH 600)
set(CPACK_IFW_PACKAGE_WIZARD_DEFAULT_HEIGHT 450)

# Компоненты установки
set(CPACK_IFW_COMPONENT_RUNTIME_DISPLAY_NAME "Satisfactory Calculator Pro")
set(CPACK_IFW_COMPONENT_RUNTIME_DESCRIPTION "Main application and required libraries")
set(CPACK_IFW_COMPONENT_RUNTIME_REQUIRED TRUE)

# Создание ярлыков
set(CPACK_IFW_SHORTCUTS_ENABLED TRUE)
set(CPACK_IFW_PACKAGE_START_MENU_DIRECTORY "Satisfactory Calculator Pro")

# Настройка скрипта развертывания Qt для Windows
if(WIN32)
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/deploy-qt-windows.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/deploy-qt-windows.cmake"
        @ONLY
    )
    set(CPACK_PRE_BUILD_SCRIPTS "${CMAKE_CURRENT_BINARY_DIR}/deploy-qt-windows.cmake")
endif()

# Подключаем CPack
include(CPack)
include(CPackIFW) 