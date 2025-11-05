add_subdirectory(equipment)

add_library(HunterLib STATIC hunter.cpp)
target_link_libraries(HunterLib PUBLIC EquipLib)

target_include_directories(HunterLib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")