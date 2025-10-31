//
// Created by james on 30/10/2025.
//

#include "Multa.h"

#include <cstring>
Multa::Multa() {
    placa=nullptr;
    fechaDeInfraccion=0;
    fechaDePago=0;
    codigoInfraccion=0;
    multa=0.0;
}
Multa::Multa(const Multa &origen):Multa() {
    *this=origen;
}
Multa &Multa::operator=(const Multa &origen){
    this->setPlaca(origen.getPlaca());
    this->setFechaDeInfraccion(origen.getFechaDeInfraccion());
    this->setFechaDePago(origen.getFechaDePago());
    this->setCodigoInfraccion(origen.getCodigoInfraccion());
    this->setMulta(origen.getMulta());
    return *this;
}
Multa::~Multa() {
    delete[] placa;
}

//Setters
void Multa::setPlaca(char *placa) {
    delete[]this->placa;
    if (placa) {
        this->placa = new char[strlen(placa)+1];
        strcpy(this->placa, placa);
    }else {
        this->placa = nullptr;
    }
}
void Multa::setFechaDeInfraccion(int fechaDeInfraccion) {
    this->fechaDeInfraccion=fechaDeInfraccion;
}
void Multa::setFechaDePago(int fechaDePago) {
    this->fechaDePago=fechaDePago;
}
void Multa::setCodigoInfraccion(int codigoInfraccion) {
    this->codigoInfraccion=codigoInfraccion;
}
void Multa::setMulta(double multa) {
    this->multa=multa;
}
//Getters
char *Multa::getPlaca() const {
    return this->placa;
}
int Multa::getFechaDeInfraccion() const {
    return this->fechaDeInfraccion;
}
int Multa::getFechaDePago() const {
    return this->fechaDePago;
}
int Multa::getCodigoInfraccion() const {
    return this->codigoInfraccion;
}
double Multa::getMulta() const {
    return this->multa;
}
// fechaDeInfraccion, placa, codigoInfraccion, caracter, fechaPagoMulta
// 18/12/2024,G938-342,2061,P,26/1/2025
// 6/8/2021,P863-768,2025
istream &operator>>(istream &arch, Multa &multa) {
    char buff[20],c;
    int dd,mm,yyyy;
    int codInfraccion;
    arch>>dd;
    if (arch.eof())return arch;
    arch>>c>>mm>>c>>yyyy>>c;
    multa.setFechaDeInfraccion(dd+mm*100+yyyy*10000);
    arch.getline(buff,20,',');
    multa.setPlaca(buff);
    arch>>codInfraccion;
    multa.setCodigoInfraccion(codInfraccion);
    if (arch.get()!=',')return arch;
    arch>>c>>c>>dd>>c>>mm>>c>>yyyy;
    multa.setFechaDePago(dd+mm*100+yyyy*10000);
    arch.get();
    return arch;
}
ostream &operator<<(ostream &arch, const Multa &multa) {
    return arch;
}