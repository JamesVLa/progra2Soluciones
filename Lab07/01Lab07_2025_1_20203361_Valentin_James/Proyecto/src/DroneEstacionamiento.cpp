//
// Created by james on 6/11/2025.
//

#include "DroneEstacionamiento.h"

#include "Drone.h"

DroneEstacionamiento::DroneEstacionamiento() {
    this->zona_carga=0;
}
DroneEstacionamiento::DroneEstacionamiento(const DroneEstacionamiento &orig):DroneEstacionamiento() {
    *this=orig;
}

DroneEstacionamiento &DroneEstacionamiento::operator=(const DroneEstacionamiento &orig) {
    if (this==&orig) return *this;
    Drone::operator=(orig);
    this->zona_carga=orig.zona_carga;
    return *this;
}

void DroneEstacionamiento::setZonaCarga(int zona_carga) {
    this->zona_carga=zona_carga;
}
int DroneEstacionamiento::getZonaCarga() const {
    return this->zona_carga;
}

void DroneEstacionamiento::leer(ifstream &arch) {
    Drone::leer(arch);
    char aux[100];
    arch.getline(aux, 100,'\n');
    if (strcmp(aux,"true")==0) {
        zona_carga=1;
    }else{zona_carga=0;}
}

