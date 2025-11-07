//
// Created by james on 6/11/2025.
//

#ifndef PROYECTO_DRONESEMAFORO_H
#define PROYECTO_DRONESEMAFORO_H
#include "Drone.h"


class DroneSemaforo:public Drone{
private:
    int luz_roja;
    public:
    DroneSemaforo();
    DroneSemaforo(const DroneSemaforo &orig);
    ~DroneSemaforo() = default;
    DroneSemaforo &operator=(const DroneSemaforo &orig);
    //setters
    void setLuz_roja(int luz_roja);
    //getters
    int getLuz_roja()const;
    //METODOS
    void leer(ifstream &arch);
};


#endif //PROYECTO_DRONESEMAFORO_H