//
// Created by james on 12/11/2025.
//

#ifndef PROYECTO_DRONEESTACIONAMIENTO_H
#define PROYECTO_DRONEESTACIONAMIENTO_H
#include "Dron.h"


class DroneEstacionamiento :public Dron{
    int zona_carga;
    public:
    DroneEstacionamiento();
    DroneEstacionamiento(const DroneEstacionamiento& droneEstacionamiento);
    ~DroneEstacionamiento();
    DroneEstacionamiento& operator=(const DroneEstacionamiento& droneEstacionamiento);
    int get_zona_carga()const;
    void set_zona_carga(int zona_carga);
    void lee(ifstream& arch)override;
    void imprime(ofstream &arch)const override;
    void actualiza() override;
};


#endif //PROYECTO_DRONEESTACIONAMIENTO_H