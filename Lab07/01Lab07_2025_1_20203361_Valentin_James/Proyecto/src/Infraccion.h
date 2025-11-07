//
// Created by james on 6/11/2025.
//

#ifndef PROYECTO_INFRACCION_H
#define PROYECTO_INFRACCION_H
#include <fstream>
using namespace std;

class Infraccion {
    int fecha_evento;
    char* tipo_infraccion;
    double monto;
    int fecha_pago_limite;
    char* placa;
public:
    // ---------- Constructores / Destructor ----------
    Infraccion();//Defecto
    Infraccion(const Infraccion& infraccion);//Copia
    ~Infraccion();//Destructor
    Infraccion& operator=(const Infraccion& infraccion);
    //-------------Setters------------
    void setFechaEvento(int fecha_evento);
    void setTipoInfraccion(char* tipo_infraccion);
    void setMonto(double monto);
    void setFechaPagoLimite(int fecha_pago_limite);
    void setPlaca(char* placa);
    //-------------Getters------------
    int getFechaEvento()const;
    char* getTipoInfraccion()const;
    double getMonto()const;
    int getFechaPagoLimite()const;
    char* getPlaca()const;
    //-------------Métodos------------ FALTANTES
    void leer(ifstream& arch);
    void imprimir(ofstream& arch)const;
};


#endif //PROYECTO_INFRACCION_H