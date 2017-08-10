cmake_minimum_required(VERSION 3.0) 
#set_property(TARGET tgt PROPERTY CXX_STANDARD 11)
#set(CMAKE_CXX_COMPILER /usr/bin/c++) 
add_compile_options(-std=c++11)  
set(CMAKE_BUILD_TYPE Release) 
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
#set(CMAKE_CXX_FLAGS_RELEASE "-O3")
 

# PROJECTS
project(spacelice)
 
# HEADERS AND SOURCE FILES
include_directories ( src ) 
file(GLOB SOURCES "src/*.cpp")
 
# EIGEN LIBRARY
include_directories ( lib/eigen )
  
# QT4
find_package(Qt4 REQUIRED) 
include_directories(Qt4 ${OPENGL_INCLUDE_DIRS} )

# OPENGL
find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} )

# GLUT
find_package(GLUT REQUIRED)
include_directories( ${GLUT_INCLUDE_DIRS} )

# EXECUTABLE
add_executable(spacelice ${SOURCES} )
  
# LINKING  
target_link_libraries (spacelice OpenMeshCore OpenMeshTools  ${QT_LIBRARIES}  ${OPENGL_LIBRARIES}  ${GLUT_LIBRARIES} ) 

