add_library(BeastLib STATIC beast.cpp beast_decor.cpp)
add_library(KnightLib STATIC knight.cpp)

target_link_libraries(BeastLib PRIVATE KnightLib)

target_include_directories(KnightLib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(BeastLib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")