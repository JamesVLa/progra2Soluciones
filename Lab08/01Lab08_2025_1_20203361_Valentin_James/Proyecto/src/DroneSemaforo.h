//
// Created by james on 12/11/2025.
//

#ifndef PROYECTO_DRONESEMAFORO_H
#define PROYECTO_DRONESEMAFORO_H
#include "Dron.h"


class DroneSemaforo:public Dron{
    private:
    int luz_roja;
    public:
    DroneSemaforo();
    DroneSemaforo(const DroneSemaforo& droneSemaforo);
    ~DroneSemaforo();
    DroneSemaforo& operator=(const DroneSemaforo& droneSemaforo);

    int get_luz_roja()const;
    void set_luz_roja(int luz_roja);
    void lee(ifstream &arch) override;
    void imprime(ofstream &arch)const override;
    void actualiza() override;
};


#endif //PROYECTO_DRONESEMAFORO_H