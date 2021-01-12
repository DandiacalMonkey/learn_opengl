cmake_minimum_required(VERSION 3.19)

project(opengl_test)

find_package(OpenGL REQUIRED)
find_package(FreeGLUT REQUIRED)
find_package(GLEW REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}/third_party/GLTools/include")
link_directories("${CMAKE_SOURCE_DIR}/third_party/GLTools/lib")

add_executable(${PROJECT_NAME}
main.cc
triangle.h
triangle.cc
points.h
points.cc)
target_link_libraries(${PROJECT_NAME} OpenGL::GL OpenGL::GLU FreeGLUT::freeglut_static GLEW::glew_s gltools)
