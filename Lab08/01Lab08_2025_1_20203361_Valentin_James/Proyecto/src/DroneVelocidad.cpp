//
// Created by james on 12/11/2025.
//

#include "DroneVelocidad.h"

DroneVelocidad::DroneVelocidad() {
    velocidad_maxima_permitida=0;
}
DroneVelocidad::DroneVelocidad(const DroneVelocidad &origen) {
    *this=origen;
}
DroneVelocidad &DroneVelocidad::operator=(const DroneVelocidad &origen) {
    if (this==&origen)return *this;
    Dron::operator=(origen);
    this->set_velocidad_maxima_permitida(origen.get_velocidad_maxima_permitida());
    return *this;
}

void DroneVelocidad::set_velocidad_maxima_permitida(double velocidad_maxima_permitida) {
    this->velocidad_maxima_permitida=velocidad_maxima_permitida;
}
double DroneVelocidad::get_velocidad_maxima_permitida() const {
    return this->velocidad_maxima_permitida;
}
DroneVelocidad::~DroneVelocidad() {

}
//     Velocidad,DV001,Avenida A,5,60
void DroneVelocidad::lee(ifstream &arch) {
    Dron::lee(arch);
    arch>>velocidad_maxima_permitida;
    arch.get();
}


void DroneVelocidad::imprime(ofstream &arch) const {
    Dron::imprime(arch);
    arch<<this->velocidad_maxima_permitida<<endl;
}

void DroneVelocidad::actualiza() {

}
