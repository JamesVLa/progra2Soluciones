//
// Created by james on 6/11/2025.
//

#ifndef PROYECTO_DRONEESTACIONAMIENTO_H
#define PROYECTO_DRONEESTACIONAMIENTO_H
#include "Drone.h"


class DroneEstacionamiento: public Drone{
    int zona_carga;
    public:
    //constructores destructores
    DroneEstacionamiento();
    DroneEstacionamiento(const DroneEstacionamiento &orig);
    ~DroneEstacionamiento() = default;
    DroneEstacionamiento &operator=(const DroneEstacionamiento &orig);
    //setters
    void setZonaCarga(int zona_carga);
    //getters
    int getZonaCarga()const;
    //METODOS
    void leer(ifstream &arch);
};


#endif //PROYECTO_DRONEESTACIONAMIENTO_H