//
// Created by james on 6/11/2025.
//

#ifndef PROYECTO_CENTRALDEMONITOREO_H
#define PROYECTO_CENTRALDEMONITOREO_H
#include "Flota.h"

class CentralDeMonitoreo {
    Flota flota;
    int cantidad_multas_registradas;
    double total_multas_acumuladas;
    public:
    CentralDeMonitoreo();
    ~CentralDeMonitoreo()=default;
    //--------------METODOS FALTANTES----------
    void leer(ifstream& arch, const char*tipo);
    void cargar_infracciones(ifstream& arch);
    void imprimir(ofstream& arch);
};


#endif //PROYECTO_CENTRALDEMONITOREO_H