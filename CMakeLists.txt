cmake_minimum_required(VERSION 3.20)
project(Gizmo)

set(SOURCE_FILES src/main.cpp)
add_executable(Gizmo ${SOURCE_FILES})

# Add glad
add_subdirectory(lib/glad)
target_link_libraries(Gizmo glad)
include_directories(lib/glad/include)

# Add glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(lib/glfw)
include_directories(lib/glfw)
include_directories(lib/glfw/include)

target_link_libraries(Gizmo glfw ${GLFW_LIBRARIES})

# Add spdlog
add_subdirectory(lib/spdlog)
target_link_libraries(Gizmo spdlog::spdlog)