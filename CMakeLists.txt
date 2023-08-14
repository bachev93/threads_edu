cmake_minimum_required(VERSION 3.22.0)
project(threads_edu)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)

add_subdirectory(fork_exec)
add_subdirectory(daemon)
add_subdirectory(pthreads_example)
add_subdirectory(std_thread)
add_subdirectory(async)
