add_library(CompanionLib STATIC companion.cpp companion_strat.cpp)

target_include_directories(CompanionLib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")