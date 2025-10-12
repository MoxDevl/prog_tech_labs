cmake_minimum_required(VERSION 3.20.0)

project(lab3)

add_subdirectory(lib)

add_executable(Main main.cpp)

target_link_libraries(Main 
                        PRIVATE SingleLib 
                        PRIVATE HunterTypes
                        PRIVATE HunterUtils
                        PRIVATE NonPlayCharsTypes
                        PRIVATE NonPlayCharsUtils)