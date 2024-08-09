cmake_minimum_required(VERSION 3.28)
project(elaborato_laboratorio_di_programmazione)

set(CMAKE_CXX_STANDARD 17)
find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

add_subdirectory(test)

set(SOURCE_FILES Date.cpp
        Date.h
        Activity.cpp
        Activity.h
        Time.cpp
        Time.h
        Register.cpp
        Register.h
        App.h
        MainFrame.cpp
        MainFrame.h)

add_executable(elaborato_laboratorio_di_programmazione App.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(elaborato_laboratorio_di_programmazione core)

target_link_libraries(elaborato_laboratorio_di_programmazione ${wxWidgets_LIBRARIES})

