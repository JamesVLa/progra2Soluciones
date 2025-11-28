cmake_minimum_required(VERSION 4.0)
project(Proyecto)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto main.cpp
        src/Infraccion.cpp
        src/Infraccion.h
        src/Utils.cpp
        src/Utils.h
        src/Vehiculo.cpp
        src/Vehiculo.h
        src/Multa.cpp
        src/Multa.h
        src/Empresa.cpp
        src/Empresa.h
        src/MinisterioDeTransporte.cpp
        src/MinisterioDeTransporte.h)
