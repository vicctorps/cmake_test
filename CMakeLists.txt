
cmake_minimum_required(VERSION 3.10)

# set the project name
project(victor)

find_package(ROOT REQUIRED)
message(status "root libraries: ${ROOT_LIBRARIES}")
include_directories(${ROOT_INCLUDE_DIRS})

# add the executable
add_executable(victor victor.cxx)

target_link_libraries(victor -lmpfr)

install(TARGETS victor  DESTINATION bin)
