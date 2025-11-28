//
// Created by james on 28/11/2025.
//

#include "NVehiculo.h"

#include "Camion.h"
#include "Furgon.h"

NVehiculo::NVehiculo() {
    unidad=nullptr;
}
NVehiculo::NVehiculo(const NVehiculo &other):NVehiculo() {
    *this=other;
}
NVehiculo &NVehiculo::operator=(const NVehiculo &other) {
    if (this==&other)return *this;
    unidad=other.unidad;
    return *this;
}
// F,79464412,K0D-676,300,1,3
// F,16552775,S7E-946,300,2,3
// C,20864087,O5L-856,1000,2,6
// C,94326707,U3F-754,1000,2,8
// …
// Tipo de Vehículo, Cliente, Placa, Máxima carga, Filas/Ejes, Puertas/Llantas.
void NVehiculo::lee(ifstream &arch) {
    char c;
    arch>>c;
    if (arch.eof())return;
    if (c=='F') {
        unidad=new Furgon();
    }else if (c=='C') {
        unidad=new Camion();
    }
    arch.ignore();
    unidad->lee(arch);
}
void NVehiculo::imprime(ofstream &arch) const {
    arch<<fixed<<setprecision(2);
    unidad->imprime(arch);
}
bool NVehiculo::esCliente(int cod) const {
    return unidad->getCliente()==cod;
}
void NVehiculo::ingresaPed(ifstream& arch) {
    unidad->ingresaPedido(arch);
}

ifstream &operator>>(ifstream &arch, NVehiculo &flota) {
    flota.lee(arch);
    return arch;
}
ofstream &operator<<(ofstream &arch, const NVehiculo &flota) {
    flota.imprime(arch);
    return arch;
}