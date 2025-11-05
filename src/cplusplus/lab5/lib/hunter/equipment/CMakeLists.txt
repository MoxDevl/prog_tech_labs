add_library(EquipLib STATIC weapon.cpp garments.cpp)

target_include_directories(EquipLib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")