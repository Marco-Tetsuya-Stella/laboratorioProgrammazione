cmake_minimum_required(VERSION 3.28)
project(elaborato_laboratorio_di_programmazione)

set(CMAKE_CXX_STANDARD 17)
find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

add_executable(elaborato_laboratorio_di_programmazione main.cpp
        Date.cpp
        Date.h
        Activity.cpp
        Activity.h
        Time.cpp
        Time.h
        Register.cpp
        Register.h
        MainFrame.cpp
        MainFrame.h
        App.cpp
        App.h

)

target_link_libraries(elaborato_laboratorio_di_programmazione ${wxWidgets_LIBRARIES})

