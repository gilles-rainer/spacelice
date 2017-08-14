cmake_minimum_required(VERSION 3.0) 
#set_property(TARGET tgt PROPERTY CXX_STANDARD 11)
#set(CMAKE_CXX_COMPILER /usr/bin/c++) 
add_compile_options(-std=c++11)  
set(CMAKE_BUILD_TYPE Release) 
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
#set(CMAKE_CXX_FLAGS_RELEASE "-O3") 
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTORCC ON) 
set(CMAKE_INCLUDE_CURRENT_DIR ON)
 
# PROJECTS
project(spacelice)
  
# HEADERS AND SOURCE FILES  
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} src)
file(GLOB SOURCES "src/*.cpp") 
file(GLOB HEADERS "src/*.h") 
  
# OPENGL
find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} )

# GLUT
find_package(GLUT REQUIRED)
include_directories( ${GLUT_INCLUDE_DIRS} )

# QT4
set( QT_QMAKE_EXECUTABLE /usr/bin/qmake)
find_package(Qt4 COMPONENTS QTCORE QTGUI QTOPENGL REQUIRED) 
include(${QT_USE_FILE})
include_directories( ${QT_INCLUDE_DIR} ) 
add_definitions( ${QT_DEFINITIONS} ) 
SET(QT_USE_QTOPENGL TRUE)
#QT4_WRAP_UI(UISrcs *.ui)
QT4_WRAP_CPP(MOC_SOURCES ${HEADERS})

# OPENMESH
find_package(OPENMESH REQUIRED)
include_directories( ${OPENMESH_INCLUDE_DIR} )
MESSAGE(STATUS "Found OpenMesh at : ${OPENMESH_INCLUDE_DIR}")

# EXECUTABLE
add_executable(spacelice ${SOURCES} ${MOC_SOURCES} )  
  
# LINKING  
target_link_libraries (spacelice ${OPENMESH_LIBRARIES} ${QT_LIBRARIES} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY}       ) 
