add_library(HunterLib STATIC hunter.cpp)

target_include_directories(HunterLib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")