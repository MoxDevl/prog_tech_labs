add_library(NonPlayCharsTypes STATIC beast.cpp trader.cpp)
add_library(NonPlayCharsUtils STATIC location.cpp)

target_link_libraries(NonPlayCharsUtils PRIVATE NonPlayCharsTypes)

target_include_directories(NonPlayCharsTypes INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(NonPlayCharsUtils INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")