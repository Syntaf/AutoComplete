cmake_minimum_required(VERSION 2.6)
project(autoComplete)

#set version number
set (MAJOR 0)
set (MINOR 0)
#configure header file to be placed in binary
configure_file(
	"${PROJECT_SOURCE_DIR}/autoCompleteConfig.h.in"
	"${PROJECT_BINARY_DIR}/autoCompleteConfig.h"
)

# add binary tree to search path for include files
# so we can find config
include_directories("${PROJECT_BINARY_DIR}")

# add the executable to bin
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# add exe
add_executable( auto auto.cpp)

