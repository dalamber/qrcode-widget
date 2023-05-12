cmake_minimum_required(VERSION 3.20)
project(qtapp-template)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_configure(
        REQUIRES libqrencode/4.1.1
        GENERATORS cmake)
conan_cmake_autodetect(settings)
conan_cmake_install(
        PATH_OR_REFERENCE .
        BUILD missing
        SETTINGS ${settings}
)
include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS KEEP_RPATHS)


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
