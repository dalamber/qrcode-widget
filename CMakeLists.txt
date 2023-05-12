cmake_minimum_required(VERSION 3.20)
project(qtapp-template)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_COMPONENTS
        Core
        Gui
        Widgets
        )

find_package(Qt6 COMPONENTS ${QT_COMPONENTS} QUIET)
if (NOT Qt6_FOUND)
    find_package(Qt5 COMPONENTS ${QT_COMPONENTS} REQUIRED)
endif()

add_subdirectory(src)
