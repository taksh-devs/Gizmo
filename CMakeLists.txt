cmake_minimum_required(VERSION 3.20)
project(gizmo)

set(SOURCE_FILES src/main.cpp)
add_executable(gizmo ${SOURCE_FILES})

# Add glad
add_subdirectory(lib/glad)
target_link_libraries(gizmo glad)
include_directories(lib/glad/include)

# Add glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(lib/glfw)
include_directories(lib/glfw)
include_directories(lib/glfw/include)

target_link_libraries(gizmo glfw ${GLFW_LIBRARIES})

# Add spdlog
add_subdirectory(lib/spdlog)
target_link_libraries(gizmo spdlog::spdlog)

# Add osdialog
add_subdirectory(lib/osdialog)
target_link_libraries(gizmo osdialog)
include_directories(lib/osdialog/src)