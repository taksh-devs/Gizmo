cmake_minimum_required(VERSION 3.20)
project(glad)

set(HEADER_FILES include/glad/glad.h include/KHR/khrplatform.h)
set(SOURCE_FILES src/glad.c)

add_library(glad ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(glad PUBLIC include/)