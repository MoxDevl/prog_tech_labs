add_subdirectory(profile)
add_subdirectory(beast)
add_subdirectory(equipment)
add_subdirectory(chest)
add_subdirectory(hunter)

target_link_libraries(HunterLib PUBLIC EquipLib)
target_link_libraries(ChestLib PRIVATE EquipLib)