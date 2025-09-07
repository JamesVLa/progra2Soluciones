cmake_minimum_required(VERSION 4.0)
project(Parte1_CrearBiblioteca)

set(CMAKE_CXX_STANDARD 20)

add_library(operadores STATIC funciones/sobrecargaOp.cpp)

add_executable(Parte1_CrearBiblioteca main.cpp)

target_link_libraries(Parte1_CrearBiblioteca operadores)
