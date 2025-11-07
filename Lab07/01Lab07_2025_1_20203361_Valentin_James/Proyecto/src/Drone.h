//
// Created by james on 6/11/2025.
//

#ifndef PROYECTO_DRONE_H
#define PROYECTO_DRONE_H
#include "Infraccion.h"
#include <cstring>
using namespace std;
#define  MAX_INFRACCIONES 20
class Drone {
    char* id;
    char* ubicacion;
    int capacidad;
    int cantidad_infracciones;
    Infraccion infracciones[MAX_INFRACCIONES];
    public:
    // ---------- Constructores / Destructor ----------
    Drone();
    Drone(const Drone &drone);

    Drone& operator=(const Drone &origen);
    ~Drone();
    //-------------Setters------------
    void setId(char* id);
    void setUbicacion(char* ubicacion);
    void setCapacidad(int capacidad);
    void setCantidadInfracciones(int cantidad_infracciones);
    //-------------Getters------------
    char* getId() const;
    char* getUbicacion() const;
    int getCapacidad() const;
    int getCantidadInfracciones() const;
    //------------------Metodos---------------
    void leer(ifstream &arch);
};


#endif //PROYECTO_DRONE_H