//
// Created by james on 12/11/2025.
//

#ifndef PROYECTO_DRON_H
#define PROYECTO_DRON_H
#include "Comunes.h"
class Dron {
    char* id;
    char* ubicacion;
    int capacidad;
    public:
    Dron();
    Dron(const Dron &dron);
    virtual ~Dron();
    Dron& operator=(const Dron &dron);
    const char* getId()const;
    const char* getUbicacion()const;
    int getCapacidad()const;
    void setId(const char* id);
    void setUbicacion(const char* ubicacion);
    void setCapacidad(int capacidad);
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch)const;
    virtual void actualiza()=0;
    bool operator>(const Dron &dron)const;
};

#endif //PROYECTO_DRON_H