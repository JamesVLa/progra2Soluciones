//
// Created by james on 27/11/2025.
//

#include "Multa.h"

Multa::Multa() {
    fechaDePago=0;
    pagada=false;
}
Multa::Multa(const Multa &orig):Multa() {
    *this = orig;
}
Multa &Multa::operator=(const Multa &orig) {
    if (this==&orig)return *this;
    setFecha(orig.getFecha());
    setPlaca(orig.getPlaca());
    setCodMulta(orig.getCodMulta());
    setMulta(orig.getMulta());
    setPagada(orig.isPagada());
    setFechaDePago(orig.getFechaDePago());
    return *this;
}
// InfraccionesCometidas.csv
// 3/2/2022,M832-314,M1008,N
// 5/10/2024,M907-605,M1002,P,24/10/2024
// … … …
// Contenido: Fecha en que cometió la infracción, placa del vehículo,
// código de la infracción y una letra N o P que indica si pagó o
// no. Si pagó le siguen la fecha de pago.
void Multa::lee(ifstream &arch) {
    int dd,mm,yyyy;
    char c;
    arch>>dd;
    if (arch.eof())return;
    arch>>c>>mm>>c>>yyyy;
    arch.ignore();
    setFecha(yyyy*10000+mm*100+dd);
    getline(arch,placa,',');
    getline(arch,codMulta,',');
    arch.get(c);
    arch.get();
    if (c=='N')return;
    arch>>dd>>c>>mm>>c>>yyyy;
    arch.ignore();
    setFechaDePago(yyyy*10000+mm*100+dd);
    setPagada(true);
}
void Multa::imprime(ofstream &arch) const {

}


int Multa::getFecha() const {
    return fecha;
}

void Multa::setFecha(const int fecha) {
    this->fecha = fecha;
}

string Multa::getPlaca() const {
    return placa;
}

void Multa::setPlaca(const string &placa) {
    this->placa = placa;
}

string Multa::getCodMulta() const {
    return codMulta;
}

void Multa::setCodMulta(const string &codMulta) {
    this->codMulta = codMulta;
}

double Multa::getMulta() const {
    return multa;
}

void Multa::setMulta( double multa) {
    this->multa = multa;
}

bool Multa::isPagada() const {
    return pagada;
}

void Multa::setPagada( bool pagada) {
    this->pagada = pagada;
}

int Multa::getFechaDePago() const {
    return fechaDePago;
}

void Multa::setFechaDePago( int fechaDePago) {
    this->fechaDePago = fechaDePago;
}


ifstream& operator>>(ifstream &arch,Multa &Mult) {
    Mult.lee(arch);
    return arch;
}

ofstream& operator<<(ofstream &arch,Multa &Mult) {
    Mult.imprime(arch);
    return arch;
}
