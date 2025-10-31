//
// Created by james on 30/10/2025.
//

#ifndef INC_20203361_LABORATORIO06_2025_1_MINISTERIODETRANSPORTE_H
#define INC_20203361_LABORATORIO06_2025_1_MINISTERIODETRANSPORTE_H

#include "Infraccion.h"
#include "Empresa.h"
class MinisterioDeTransporte {
    Infraccion *infracciones;
    int numInf;
    Empresa empresas[50];
    int numEmp;
    public:
    MinisterioDeTransporte();
    ~MinisterioDeTransporte();
    //Setters
    void setNumInf(int numInf);
    void setNumEmp(int numEmp);
    //Getters
    int getNumInf() const;
    int getNumEmp() const;
};


#endif //INC_20203361_LABORATORIO06_2025_1_MINISTERIODETRANSPORTE_H