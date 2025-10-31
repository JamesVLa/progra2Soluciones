//
// Created by james on 30/10/2025.
//

#include "MinisterioDeTransporte.h"

MinisterioDeTransporte::MinisterioDeTransporte() {
    infracciones=nullptr;
    numInf=0;
    numEmp=0;
}
MinisterioDeTransporte::~MinisterioDeTransporte() {
    delete[] infracciones;
}
//Setters
void MinisterioDeTransporte::setNumEmp(int numEmp) {
    this->numEmp=numEmp;
}
void MinisterioDeTransporte::setNumInf(int numInf) {
    this->numInf=numInf;
}
//Getters
int MinisterioDeTransporte::getNumEmp() const {
    return numEmp;
}
int MinisterioDeTransporte::getNumInf() const {
    return numInf;
}
