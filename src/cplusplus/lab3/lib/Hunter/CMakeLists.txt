add_library(HunterTypes STATIC hunter.cpp)
add_library(HunterUtils STATIC hunter_builder.cpp hunter_selector.cpp)

target_link_libraries(HunterUtils PRIVATE HunterTypes)

target_include_directories(HunterTypes INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(HunterUtils INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")