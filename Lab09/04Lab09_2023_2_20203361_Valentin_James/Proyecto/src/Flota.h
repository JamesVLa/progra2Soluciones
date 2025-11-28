//
// Created by james on 28/11/2025.
//

#ifndef PROYECTO_FLOTA_H
#define PROYECTO_FLOTA_H
#include "NVehiculo.h"
#include "Utils.h"

class Flota {
private:
    vector<NVehiculo> vflota;
    public:
    Flota()=default;
    ~Flota()=default;
    void cargaflota();
    void cargapedidos();
    void muestracarga();
};


#endif //PROYECTO_FLOTA_H