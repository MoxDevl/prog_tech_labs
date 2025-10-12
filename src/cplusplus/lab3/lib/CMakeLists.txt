add_subdirectory(Hunter)
add_subdirectory(NonPlayChars)

add_library(SingleLib STATIC singleton.cpp)

target_include_directories(SingleLib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")