
cmake_minimum_required(VERSION 3.10)

# set the project name
project(cmake_test)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(ROOT REQUIRED)
message(STATUS "ROOT libraries: ${ROOT_LIBRARIES}")
include_directories(${ROOT_INCLUDE_DIRS})

# add the executable
add_executable(victor victor.cxx)

target_link_libraries(victor -lmpfr ${ROOT_LIBRARIES})

install(TARGETS victor  DESTINATION bin)
