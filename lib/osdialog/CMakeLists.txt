cmake_minimum_required(VERSION 3.20)
project(osdialog)

set(HEADER_FILES src/osdialog.h)
set(SOURCE_FILES src/osdialog.c src/osdialog_win.c src/osdialog_gtk2.c src/osdialog_gtk3.c)

add_library(osdialog ${HEADER_FILES} ${SOURCE_FILES})

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    SET(LINUX_OS)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    SET(WINDOWS_OS)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")