cmake_minimum_required(VERSION 3.20.0)

project(lab4)

add_subdirectory(lib)

add_executable(main main.cpp)

target_link_libraries(main 
    PRIVATE BeastLib 
    PRIVATE ProfileLib
    PRIVATE HunterLib
    PRIVATE ChestLib
)