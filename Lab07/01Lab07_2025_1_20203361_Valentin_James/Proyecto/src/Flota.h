//
// Created by james on 6/11/2025.
//

#ifndef PROYECTO_FLOTA_H
#define PROYECTO_FLOTA_H
#include "DroneEstacionamiento.h"
#include "DroneSemaforo.h"
#include "DroneVelocidad.h"
#define MAX_DRONES
#include <fstream>

class Flota {
    DroneVelocidad drones_velocidad[20];
    DroneSemaforo drones_semaforo[20];
    DroneEstacionamiento drones_estacionamiento[20];

    int n_drones_velocidad;
    int n_drones_semaforo;
    int n_drones_estacionamiento;
public:
    Flota();
    ~Flota() = default;
    int getNDronesVelocidad();
    int getNDronesSemaforo();
    int getNDronesEstacionamiento();
    //MÉTODOS FALTANTES
    void cargar_drone(ifstream &input, const char*tipo);
    int buscarDroneVelocidad(const char* id);
    int buscarDroneSemaforo(const char* id);
    int buscarDroneEstacionamiento(const char* id);
    void actualizarDronesInfracciones(ifstream &arch);
    void imprimir(ofstream &outpu) const;

};


#endif //PROYECTO_FLOTA_H