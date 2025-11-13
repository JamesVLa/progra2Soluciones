//
// Created by james on 12/11/2025.
//

#ifndef PROYECTO_DRONEVELOCIDAD_H
#define PROYECTO_DRONEVELOCIDAD_H
#include "Dron.h"


class DroneVelocidad:public Dron{
    double velocidad_maxima_permitida;
    public:
    DroneVelocidad();
    DroneVelocidad(const DroneVelocidad& origen);
    ~DroneVelocidad();
    DroneVelocidad& operator=(const DroneVelocidad& origen);
    double get_velocidad_maxima_permitida()const;
    void set_velocidad_maxima_permitida(double velocidad_maxima_permitida);
    void lee(ifstream &arch) override;
    void imprime(ofstream &arch)const override;
    void actualiza() override;
};


#endif //PROYECTO_DRONEVELOCIDAD_H