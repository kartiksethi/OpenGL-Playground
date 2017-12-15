cmake_minimum_required(VERSION 3.8)
project(Scenery)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES *.h *.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)


file(GLOB SOURCE_FILES
        *.cpp
        *.h
        )

add_executable(Scenery ${SOURCE_FILES})
add_executable(main.cpp ${SOURCE_FILES} camera.h props.h camera.cpp)
target_link_libraries (Scenery ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${GLEW_LIBRARIES} ${OPENGL_glu_LIBRARY})
target_link_libraries (main.cpp ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${GLEW_LIBRARIES} ${OPENGL_glu_LIBRARY})