//
// Created by james on 28/11/2025.
//

#ifndef PROYECTO_NVEHICULO_H
#define PROYECTO_NVEHICULO_H
#include "Vehiculo.h"


class NVehiculo {
    Vehiculo* unidad;
    public:
    NVehiculo();
    NVehiculo(const NVehiculo& other);
    void lee(ifstream &arch);
    void imprime(ofstream &arch)const;
    bool esCliente(int cod)const;
    void ingresaPed(ifstream &arch);
    NVehiculo& operator=(const NVehiculo& other);
    ~NVehiculo()=default;
};
ifstream &operator>>(ifstream &arch, NVehiculo &flota);
ofstream &operator<<(ofstream &arch, const NVehiculo &flota);

#endif //PROYECTO_NVEHICULO_H