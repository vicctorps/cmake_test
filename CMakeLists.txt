
cmake_minimum_required(VERSION 3.10)

# set the project name
project(mylib VERSION 1.0 DESCRIPTION "mylib test")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(mylib SHARED
	src/Myclass.cxx
	)

target_include_directories(mylib PRIVATE inc)
target_link_libraries(mylib ${ROOT_LIBRARIES})



find_package(ROOT REQUIRED)
message(STATUS "ROOT libraries: ${ROOT_LIBRARIES}")
include_directories(${ROOT_INCLUDE_DIRS} inc)

# add the executable
add_executable(victor victor.cxx)

target_link_libraries(victor -lmpfr mylib ${ROOT_LIBRARIES})

install(TARGETS victor  DESTINATION bin)
install(TARGETS mylib  DESTINATION lib)
