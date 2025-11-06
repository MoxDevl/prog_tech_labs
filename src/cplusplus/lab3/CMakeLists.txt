cmake_minimum_required(VERSION 3.20.0)

project(lab3)

add_subdirectory(lib)

add_executable(main main.cpp)

target_compile_features(main PUBLIC cxx_std_11)

target_link_libraries(main 
                        PRIVATE SingleLib 
                        PRIVATE HunterTypes
                        PRIVATE HunterUtils
                        PRIVATE NonPlayCharsTypes
                        PRIVATE NonPlayCharsUtils)