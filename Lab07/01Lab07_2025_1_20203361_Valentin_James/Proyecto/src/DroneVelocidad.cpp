//
// Created by james on 6/11/2025.
//

#include "DroneVelocidad.h"

DroneVelocidad::DroneVelocidad() {
    velocidad_maxima_permitida=0;
}
DroneVelocidad::DroneVelocidad(const DroneVelocidad &orig):DroneVelocidad() {
    *this=orig;
}

DroneVelocidad &DroneVelocidad::operator=(const DroneVelocidad &orig) {
    if (this==&orig)return *this;

    Drone::operator=(orig);
    velocidad_maxima_permitida=orig.velocidad_maxima_permitida;
    return *this;
}

void DroneVelocidad::setVelocidadMaximaPermitida(int velocidad_maxima_permitida) {
    this->velocidad_maxima_permitida=velocidad_maxima_permitida;
}
int DroneVelocidad::getVelocidadMaximaPermitida() const {
    return this->velocidad_maxima_permitida;
}

void DroneVelocidad::leer(ifstream &arch) {
    Drone::leer(arch);
    arch>>velocidad_maxima_permitida;
    arch.get();
}
