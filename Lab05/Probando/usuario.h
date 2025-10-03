//
// Created by james on 29/09/2025.
//

#ifndef PROBANDO_USUARIO_H
#define PROBANDO_USUARIO_H

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

class Usuario {
    char* cuenta;
    char* nombre;
    char* correo;
    char* facultad;
    int fechaRegistro;
    int edad;
public:
    Usuario();

    char* getCuenta() const;
    void setCuenta(char*);
    char* getNombre() const;
    void setNombre(char* nombre);
    char* getCorreo() const;
    void setCorreo(char* correo);
    char* getFacultad() const;
    void setFacultad(char* facultad);
    int getFechaRegistro() const;
    void setFechaRegistro(int fechaRegistro);
    int getEdad() const;
    void setEdad(int edad);

    char* leerCadena(istream&, char=',');

    Usuario& operator=(const Usuario&);

    ~Usuario();
};

istream& operator>>(istream&, Usuario&);
ostream& operator<<(ostream&, const Usuario&);


#endif //PROBANDO_USUARIO_H