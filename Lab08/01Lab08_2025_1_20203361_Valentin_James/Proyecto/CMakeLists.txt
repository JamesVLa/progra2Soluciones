cmake_minimum_required(VERSION 4.0)
project(Proyecto)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto main.cpp
        src/Dron.cpp
        src/Dron.h
        src/DroneSemaforo.cpp
        src/DroneSemaforo.h
        src/DroneEstacionamiento.cpp
        src/DroneEstacionamiento.h
        src/DroneVelocidad.cpp
        src/DroneVelocidad.h
        tad/Nodo.cpp
        tad/Nodo.h
        tad/Arbol.cpp
        tad/Arbol.h
        src/Central.cpp
        src/Central.h
        src/Comunes.cpp
        src/Comunes.h
)
