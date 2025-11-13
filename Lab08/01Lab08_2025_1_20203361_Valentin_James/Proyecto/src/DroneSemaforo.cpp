//
// Created by james on 12/11/2025.
//

#include "DroneSemaforo.h"

DroneSemaforo::DroneSemaforo() {
    luz_roja = 0;
}
int DroneSemaforo::get_luz_roja() const {
    return luz_roja;
}
void DroneSemaforo::set_luz_roja(int luz_roja) {
    this->luz_roja=luz_roja;
}
DroneSemaforo::~DroneSemaforo() {

}
DroneSemaforo::DroneSemaforo(const DroneSemaforo &droneSemaforo):DroneSemaforo() {
    *this = droneSemaforo;
}
DroneSemaforo &DroneSemaforo::operator=(const DroneSemaforo &droneSemaforo) {
    if (this == &droneSemaforo) return *this;
    Dron::operator=(droneSemaforo);
    this->set_luz_roja(droneSemaforo.get_luz_roja());
    return *this;
}
// Semaforo,DS473,Avenida B,10,true
void DroneSemaforo::lee(ifstream &arch) {
    Dron::lee(arch);
    char valorBool[10];
    arch.getline(valorBool, 10);
    if (strcmp(valorBool, "true")==0) {
        this->set_luz_roja(1);
    }else {
        this->set_luz_roja(0);
    }
}
void DroneSemaforo::imprime(ofstream &arch) const {
    Dron::imprime(arch);
    arch<<this->get_luz_roja()<<endl;
}
void DroneSemaforo::actualiza() {
    set_luz_roja(0);
}
