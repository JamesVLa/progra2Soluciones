cmake_minimum_required(VERSION 4.0)
project(Parte2_UsarBiblioteca)

set(CMAKE_CXX_STANDARD 20)

add_executable(Parte2_UsarBiblioteca main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/funcionesSobrecargadas")

target_link_libraries(Parte2_UsarBiblioteca PRIVATE operadores)

