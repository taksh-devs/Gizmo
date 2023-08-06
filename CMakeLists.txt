cmake_minimum_required(VERSION 3.20)
project(gizmo)

set(SOURCE_FILES
    src/sdltest.cpp
    #src/main.cpp
    src/utils.cpp
    src/common.cpp
    src/display/display.cpp
    src/display/oam.cpp
    src/display/virt_ram.cpp
    src/memory_map/memory_map.cpp
    )
add_executable(gizmo ${SOURCE_FILES})

# Add spdlog
add_subdirectory(lib/spdlog)
target_link_libraries(gizmo spdlog::spdlog)

# Add SDL
add_subdirectory(lib/sdl)
include_directories(lib/sdl/include/SDL3)
target_link_libraries(gizmo sdl)
