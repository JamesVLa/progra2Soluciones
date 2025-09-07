cmake_minimum_required(VERSION 4.0)
project(Apertura_de_Archivos)

set(CMAKE_CXX_STANDARD 20)

add_executable(Apertura_de_Archivos main.cpp
        Biblioteca/AperturaDeArchivos.h
        Biblioteca/AperturaDeArchivos.cpp)
