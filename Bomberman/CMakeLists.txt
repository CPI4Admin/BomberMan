set( CMAKE_SH "" )
cmake_minimum_required(VERSION 2.8.12)

set(CMAKE_PREFIX_PATH $ENV{QTDIR} ${CMAKE_PREFIX_PATH})

project(Bomberman)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Widgets REQUIRED)

file(GLOB_RECURSE BOMBERMAN_HEADERS *.h)
file(GLOB_RECURSE BOMBERMAN_SOURCES *.cpp)

qt5_wrap_ui(UIS launchmultigame.ui launchsologame.ui mainwindow.ui paramwindows.ui widgetchat.ui windowserveur.ui windowstatistics.ui)

add_executable( Bomberman ${BOMBERMAN_SOURCES} ${BOMBERMAN_HEADERS} ${UIS})
qt5_use_modules(Bomberman Core Network Widgets)
