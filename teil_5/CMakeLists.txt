cmake_minimum_required(VERSION 3.10)
project(teil_5)

set(CMAKE_CXX_STANDARD 11)

add_executable(teil_5
                main.cpp
                Zylinder.cpp
                Zylinder.h
                Wuerfel.h
                Wuerfel.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})