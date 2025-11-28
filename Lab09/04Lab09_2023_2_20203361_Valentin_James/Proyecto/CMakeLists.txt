cmake_minimum_required(VERSION 4.0)
project(Proyecto)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto main.cpp
        src/NPedido.cpp
        src/NPedido.h
        src/Utils.cpp
        src/Utils.h
        src/Vehiculo.cpp
        src/Vehiculo.h
        src/Camion.cpp
        src/Camion.h
        src/Furgon.cpp
        src/Furgon.h
        src/NVehiculo.cpp
        src/NVehiculo.h
        src/Flota.cpp
        src/Flota.h)
