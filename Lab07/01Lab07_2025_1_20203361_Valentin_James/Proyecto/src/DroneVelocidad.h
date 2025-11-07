//
// Created by james on 6/11/2025.
//

#ifndef PROYECTO_DRONEVELOCIDAD_H
#define PROYECTO_DRONEVELOCIDAD_H
#include "Drone.h"


class DroneVelocidad:public Drone{
    int velocidad_maxima_permitida;
public:
    //CONSTRUCTORES-DESTRUCTORES
    DroneVelocidad();
    DroneVelocidad(const DroneVelocidad& orig);
    ~DroneVelocidad()=default;
    DroneVelocidad &operator=(const DroneVelocidad &orig);
    //SETTERS
    void setVelocidadMaximaPermitida(int velocidad_maxima_permitida);
    //GETTERS
    int getVelocidadMaximaPermitida()const;
    //METODOS
    void leer(ifstream &arch);
};


#endif //PROYECTO_DRONEVELOCIDAD_H