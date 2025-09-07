cmake_minimum_required(VERSION 4.0)
project(Parte1_CrearBiblioteca)

set(CMAKE_CXX_STANDARD 20)

add_executable(Parte1_CrearBiblioteca main.cpp
        funcionesAux/CadenaDeCaracteres.h
        funcionesAux/operacionesSobrecargadas.cpp
        funcionesAux/operacionesSobrecargadas.h)
