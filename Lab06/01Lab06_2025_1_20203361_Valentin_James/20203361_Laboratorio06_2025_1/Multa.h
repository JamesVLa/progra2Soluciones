//
// Created by james on 30/10/2025.
//

#ifndef INC_20203361_LABORATORIO06_2025_1_MULTA_H
#define INC_20203361_LABORATORIO06_2025_1_MULTA_H

#include <iostream>
#include <fstream>
using namespace std;
class Multa {
    char* placa;
    int fechaDeInfraccion;
    int fechaDePago;
    int codigoInfraccion;
    double multa;
    public:
    Multa();
    Multa(const Multa&);
    ~Multa();
    Multa& operator=(const Multa&);
    //Setters
    void setPlaca(char*);
    void setFechaDeInfraccion(int);
    void setFechaDePago(int);
    void setCodigoInfraccion(int);
    void setMulta(double);
    //Getters
    char* getPlaca()const;
    int getFechaDeInfraccion()const;
    int getFechaDePago()const;
    int getCodigoInfraccion()const;
    double getMulta()const;

};
istream& operator>>(istream&, Multa&);
ostream& operator<<(ostream&, Multa&);
#endif //INC_20203361_LABORATORIO06_2025_1_MULTA_H