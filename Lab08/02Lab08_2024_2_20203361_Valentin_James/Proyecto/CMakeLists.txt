cmake_minimum_required(VERSION 4.0)
project(Proyecto)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto main.cpp
        src/Comunes.cpp
        src/Comunes.h
        src/Producto.cpp
        src/Producto.h
        src/Bebida.cpp
        src/Bebida.h
        src/Entrada.cpp
        src/Entrada.h
        src/PlatoFondo.cpp
        src/PlatoFondo.h
        src/DetalleComanda.cpp
        src/DetalleComanda.h
        tad/Nodo.cpp
        tad/Nodo.h
        tad/Cola.cpp
        tad/Cola.h
        src/Restaurante.cpp
        src/Restaurante.h)
