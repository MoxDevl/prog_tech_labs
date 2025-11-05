add_subdirectory(profile)
add_subdirectory(hunter)
add_subdirectory(fight_manager)

target_link_libraries(FightManagerLib 
    PUBLIC ProfileLib
    PUBLIC HunterLib
)