//
// Created by james on 27/11/2025.
//

#ifndef PROYECTO_MINISTERIODETRANSPORTE_H
#define PROYECTO_MINISTERIODETRANSPORTE_H

#include "Utils.h"
#include "Infraccion.h"
#include "Empresa.h"
// JAMES VALENTIN 20203361
class MinisterioDeTransporte {
    list<class Infraccion> tablaInfracciones;
    list<class Empresa> listaEmpresas;
    public:
    MinisterioDeTransporte()=default;
    ~MinisterioDeTransporte()=default;
    void cargaDeInfracciones(const char*);
    void cargaDeEmpresas(const char*);
    void cargaVehiculos(const char*);
    void cargaInfraccionesCometidas(const char*);
    void reporteDeEmpresasConInfracciones(const char*);
    void eliminaInfraccionesPagadas();

};


#endif //PROYECTO_MINISTERIODETRANSPORTE_H