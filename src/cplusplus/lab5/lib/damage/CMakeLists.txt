add_library(DamageLib STATIC
    damage_link.cpp
)

target_include_directories(DamageLib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")