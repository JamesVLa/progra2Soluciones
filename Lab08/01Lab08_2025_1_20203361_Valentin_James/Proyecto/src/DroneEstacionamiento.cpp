//
// Created by james on 12/11/2025.
//

#include "DroneEstacionamiento.h"

DroneEstacionamiento::DroneEstacionamiento() {
    this->zona_carga=0;
}
int DroneEstacionamiento::get_zona_carga()const {
    return this->zona_carga;
}
void DroneEstacionamiento::set_zona_carga(int zona_carga) {
    this->zona_carga=zona_carga;
}
DroneEstacionamiento::~DroneEstacionamiento() {

}
DroneEstacionamiento::DroneEstacionamiento(const DroneEstacionamiento &droneEstacionamiento) {
    *this=droneEstacionamiento;
}
DroneEstacionamiento &DroneEstacionamiento::operator=(const DroneEstacionamiento &droneEstacionamiento) {
    if (this==&droneEstacionamiento) return *this;
    Dron::operator=(droneEstacionamiento);
    this->set_zona_carga(droneEstacionamiento.get_zona_carga());
    return *this;
}

// Estacionamiento,DE467,Avenida C,15,false
void DroneEstacionamiento::lee(ifstream &arch) {
    Dron::lee(arch);
    char valorBool[10];
    arch.getline(valorBool, 10);
    if (strcmp(valorBool, "true")==0) {
        this->set_zona_carga(1);
    }else {
        this->set_zona_carga(0);
    }
}

void DroneEstacionamiento::imprime(ofstream &arch) const {
    Dron::imprime(arch);
    arch<<this->get_zona_carga()<<endl;
}

void DroneEstacionamiento::actualiza() {
    set_zona_carga(1);
}
