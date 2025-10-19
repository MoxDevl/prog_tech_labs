add_library(ProfileLib STATIC profileDB.cpp profile.cpp)

target_include_directories(ProfileLib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")