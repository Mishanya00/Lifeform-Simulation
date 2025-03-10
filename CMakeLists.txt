cmake_minimum_required(VERSION 3.16)

project(LifeForm_Simulation VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/lifeforms)

set(PROJECT_SOURCES
        main.cpp
        simplewindow.cpp
        simplewindow.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(LifeForm_Simulation
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        canvas.h
        canvas.cpp
        simulation.h simulation.cpp

        random.cpp
        random.h
        lifeforms/bacteria.h lifeforms/bacteria.cpp
        lifeforms/lifeform.h lifeforms/lifeform.cpp
        lifeforms/photobacteria.h lifeforms/photobacteria.cpp
        lifeforms/magicbacteria.h lifeforms/magicbacteria.cpp
        lifeforms/virus.h lifeforms/virus.cpp
        lifeforms/nanorobot.h lifeforms/nanorobot.cpp
        lifeforms/lifeformcollection.h lifeforms/lifeformcollection.cpp
        selectwindow.h selectwindow.cpp


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET LifeForm_Simulation APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(LifeForm_Simulation SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(LifeForm_Simulation
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(LifeForm_Simulation PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.LifeForm_Simulation)
endif()
set_target_properties(LifeForm_Simulation PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS LifeForm_Simulation
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(LifeForm_Simulation)
endif()
