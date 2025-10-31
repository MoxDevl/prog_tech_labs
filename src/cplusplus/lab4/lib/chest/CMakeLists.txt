add_library(ChestLib STATIC chest.cpp)

target_include_directories(ChestLib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")