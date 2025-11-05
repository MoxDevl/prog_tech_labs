add_library(FightManagerLib fight_manager.cpp fight_member.cpp)

target_include_directories(FightManagerLib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")