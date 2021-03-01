cmake_minimum_required( VERSION 3.13 )
project( unite )

set( SOURCE_FILES main.cpp )

find_package( PythonInterp 3 REQUIRED ) 
find_package( PythonLibs 3 REQUIRED ) 
include_directories( ${PYTHON_INCLUDE_DIRS} )

add_executable( unite ${SOURCE_FILES} )

target_link_libraries( unite ${PYTHON_LIBRARIES} )
