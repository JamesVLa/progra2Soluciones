cmake_minimum_required(VERSION 4.0)
project(Proyecto)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto main.cpp
        src/Infraccion.cpp
        src/Infraccion.h
        src/Comunes.cpp
        src/Comunes.h
        src/Drone.cpp
        src/Drone.h
        src/DroneVelocidad.cpp
        src/DroneVelocidad.h
        src/DroneSemaforo.cpp
        src/DroneSemaforo.h
        src/DroneEstacionamiento.cpp
        src/DroneEstacionamiento.h
        src/Flota.cpp
        src/Flota.h
        src/CentralDeMonitoreo.cpp
        src/CentralDeMonitoreo.h
        src/MinisterioDeTransportes.cpp
        src/MinisterioDeTransportes.h)
