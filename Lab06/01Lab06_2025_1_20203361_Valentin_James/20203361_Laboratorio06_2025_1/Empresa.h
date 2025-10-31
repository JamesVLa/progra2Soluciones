//
// Created by james on 30/10/2025.
//

#ifndef INC_20203361_LABORATORIO06_2025_1_EMPRESA_H
#define INC_20203361_LABORATORIO06_2025_1_EMPRESA_H

#include "Multa.h"
class Empresa {
private:
    int dni;
    char* nombre;
    char *placas[10];
    int numPlacas;
    Multa multas[100];
    int numMultas;

public:
    Empresa();
    Empresa(const Empresa&);
    ~Empresa();
    Empresa& operator=(const Empresa&);
    //Setters
    void setDni(int);
    void setNombre(const char*);
    void setPlacaI(const char*,int);
    void setNumPlacas(int);
    void setNumMultas(int);
    //Getters
    int getDni()const;
    char* getNombre()const;
    char* getPlacaI(int)const;
    int getNumPlacas()const;
    int getNumMultas()const;
};

istream &operator>>(istream &arch, Empresa &empresa);
ostream &operator<<(ostream &arch, const Empresa &empresa);

#endif //INC_20203361_LABORATORIO06_2025_1_EMPRESA_H