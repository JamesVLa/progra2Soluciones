//
// Created by james on 27/11/2025.
//

#include "Empresa.h"

#include <algorithm>

Empresa::Empresa() {

}

Empresa::~Empresa() {

}

Empresa::Empresa(const Empresa &emp) {
    *this = emp;
}
Empresa& Empresa::operator=(const Empresa &emp) {
    if (this == &emp)return *this;
    dni=emp.dni;
    nombre=emp.nombre;
    distrito=emp.distrito;
    vehiculos=emp.vehiculos;
    multasRecibidas=emp.multasRecibidas;
    return *this;
}
// 48528209,ZAVALETA CORONADO FELICITA ELOISA,Villa Maria del Triunfo
// 88167677,PRADO VERA JUAN,San Miguel
// Contenido: DNI y nombre del dueño de la empresa y distrito donde se ubica la empresa.
void Empresa::leer(ifstream &arch) {
    arch >> dni;
    if (arch.eof())return;
    arch.ignore();
    getline(arch, nombre,',');
    getline(arch, distrito);
}
bool Empresa::operator<(const Empresa &emp) const {
    return dni<emp.dni;
}

void Empresa::imprime(ofstream &arch) const {

}
void Empresa::ordenarMultas() {
    sort(multasRecibidas.begin(), multasRecibidas.end(),
        [](const Multa &m1, const Multa &m2) {
            return m1.getFecha()>m2.getFecha();
        });
}

void Empresa::insertar_vehiculo(class Vehiculo v) {
    vehiculos[v.getPlaca()]=v;
}
void Empresa::buscarEmpresaPlacaAsigna(const Multa &mult) {
    //FORMA MAMADOR
    // if (vehiculos.find(mult.getPlaca())!=vehiculos.end()) {
    //     multasRecibidas.push_back(mult);
    // }
    //FORMA ESTA SI ME ACUERDO
    for (auto& orig:vehiculos) {
        if (orig.first==mult.getPlaca()) {
            multasRecibidas.push_back(mult);
        }
    }
}
void Empresa::eliminarInfraccionPagada() {
    //FORMA MAMADOR
    // multasRecibidas.erase(remove_if(multasRecibidas.begin(), multasRecibidas.end(),[](const Multa &m) {
    //     return m.isPagada();
    // }),multasRecibidas.end());
    //FORMA ESTA SI ME ACUERDO
    for (auto it=multasRecibidas.begin();it!=multasRecibidas.end();++it) {
        if (it->isPagada()) {
            multasRecibidas.erase(it);
            --it;;
        }
    }
}

ifstream &operator>>(ifstream& arch, Empresa& emp) {
    emp.leer(arch);
    return arch;
}
ofstream &operator<<(ofstream& arch, const Empresa& emp) {
    emp.imprime(arch);
    return arch;
}

int Empresa::getDni() const {
    return dni;
}

string Empresa::getNombre() const {
    return nombre;
}

string Empresa::getDistrito() const {
    return distrito;
}

