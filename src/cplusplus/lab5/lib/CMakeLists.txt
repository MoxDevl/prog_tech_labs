add_subdirectory(profile)
add_subdirectory(hunter)
add_subdirectory(fight_manager)
add_subdirectory(companion)

target_link_libraries(FightManagerLib 
    PUBLIC ProfileLib
    PUBLIC HunterLib
)