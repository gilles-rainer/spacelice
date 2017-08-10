cmake_minimum_required(VERSION 3.0) 

#set_property(TARGET tgt PROPERTY CXX_STANDARD 11)
#set(CMAKE_CXX_COMPILER /usr/bin/c++) 
add_compile_options(-std=c++11)  
set(CMAKE_BUILD_TYPE Release) 
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
 

# PROJECTS
project(spacelice)
 
# HEADERS AND SOURCE FILES
include_directories ( include ) 
file(GLOB SOURCES "src/*.cpp")
 
# EIGEN LIBRARY
include_directories ( lib/eigen )
  
# EXECUTABLE
add_executable(processing ${SOURCES})
  
# LINKING  
target_link_libraries (spacelice OpenMeshCore OpenMeshTools) 

