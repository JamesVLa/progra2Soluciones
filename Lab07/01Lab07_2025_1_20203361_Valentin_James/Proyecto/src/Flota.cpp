//
// Created by james on 6/11/2025.
//

#include "Flota.h"
#include <cstring>
#include <iostream>
using namespace std;
Flota::Flota() {
    n_drones_estacionamiento=0;
    n_drones_semaforo=0;
    n_drones_velocidad=0;
}

int Flota::getNDronesEstacionamiento() {
    return this->n_drones_estacionamiento;
}
int Flota::getNDronesVelocidad() {
    return this->n_drones_velocidad;
}
int Flota::getNDronesSemaforo() {
    return this->n_drones_semaforo;
}

//------------------------------
// Velocidad,DV050,Avenida A,5,60
// Semaforo,DS253,Avenida B,10,true
// Estacionamiento,DE190,Avenida C,15,false
// Velocidad,DV419,Avenida D,5,60
// Semaforo,DS461,Avenida E,10,true
// Estacionamiento,DE686,Avenida F,15,false
void Flota::cargar_drone(ifstream &arch, const char *tipo_dron) {
    if (strcmp(tipo_dron, "Velocidad") == 0) {
        this->drones_velocidad[n_drones_velocidad++].leer(arch);
    } else if (strcmp(tipo_dron, "Semaforo") == 0) {
        this->drones_semaforo[n_drones_semaforo++].leer(arch);
    } else if (strcmp(tipo_dron, "Estacionamiento") == 0) {
        this->drones_estacionamiento[n_drones_estacionamiento++].leer(arch);
    }
}
int Flota::buscarDroneVelocidad(const char* id) {
    return 0;
}
int Flota::buscarDroneSemaforo(const char* id) {
    return 0;
}
int Flota::buscarDroneEstacionamiento(const char *id) {
    return 0;
}
void Flota::actualizarDronesInfracciones(ifstream &arch) {

}
void Flota::imprimir(ofstream &outpu) const {

}




