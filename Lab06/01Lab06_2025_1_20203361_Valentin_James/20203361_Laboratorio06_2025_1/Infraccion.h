//
// Created by james on 30/10/2025.
//

#ifndef INC_20203361_LABORATORIO06_2025_1_INFRACCION_H
#define INC_20203361_LABORATORIO06_2025_1_INFRACCION_H
#include <iostream>
#include <fstream>
using namespace std;

class Infraccion {
private:
    int codigo;
    char* descripcion;
    char* gravedad;
    double multa;
    public:
    Infraccion();
    Infraccion(const Infraccion&);
    ~Infraccion();
    Infraccion& operator=(const Infraccion&);
    //Setters
    void setCodigo(int);
    void setDescripcion(char*);
    void setGravedad(char*);
    void setMulta(double);
    //Getters
    int getCodigo()const;
    char* getDescripcion()const;
    char* getGravedad()const;
    double getMulta()const;

};
istream& operator>>(istream&, Infraccion&);
ostream& operator<<(ostream&, const Infraccion&);

#endif //INC_20203361_LABORATORIO06_2025_1_INFRACCION_H