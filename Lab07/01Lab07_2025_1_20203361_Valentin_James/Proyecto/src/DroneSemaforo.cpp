//
// Created by james on 6/11/2025.
//

#include "DroneSemaforo.h"

DroneSemaforo::DroneSemaforo() {
    luz_roja=0;
}
DroneSemaforo::DroneSemaforo(const DroneSemaforo &orig):DroneSemaforo() {
    *this=orig;
}

DroneSemaforo &DroneSemaforo::operator=(const DroneSemaforo &orig) {
    if (this==&orig) return *this;
    Drone::operator=(orig);
    luz_roja=orig.luz_roja;
    return *this;
}

void DroneSemaforo::setLuz_roja(int luz_roja) {
    this->luz_roja=luz_roja;
}
int DroneSemaforo::getLuz_roja() const {
    return this->luz_roja;
}


void DroneSemaforo::leer(ifstream &arch) {
    Drone::leer(arch);
    char aux[100];
    arch.getline(aux, 100,'\n');
    if (strcmp(aux,"true")==0) this->setLuz_roja(1);
    else if (strcmp(aux,"false")==0) this->setLuz_roja(0);
}


