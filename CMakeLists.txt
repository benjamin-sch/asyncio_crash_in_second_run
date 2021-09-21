cmake_minimum_required(VERSION 3.18)
 
project(asyncio_crash_in_second_run DESCRIPTION "asyncio_crash_in_second_run" LANGUAGES C CXX)

add_executable(asyncio_crash_in_second_run
   main.cpp
)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

target_link_libraries("asyncio_crash_in_second_run" ${PYTHON_LIBRARIES})
