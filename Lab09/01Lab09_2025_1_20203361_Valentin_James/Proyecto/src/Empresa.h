//
// Created by james on 27/11/2025.
//

#ifndef PROYECTO_EMPRESA_H
#define PROYECTO_EMPRESA_H
#include "Vehiculo.h"
#include "Multa.h"
#include "Utils.h"
// JAMES VALENTIN 20203361
class Empresa {
private:
    int dni;
    string nombre;
    string distrito;
    map<string,class Vehiculo> vehiculos;
    vector<class Multa>multasRecibidas;
    public:
    Empresa();
    Empresa(const Empresa& emp);
    Empresa& operator=(const Empresa& emp);
    ~Empresa();
    void ordenarMultas();
    void insertar_vehiculo( class Vehiculo v);
    void buscarEmpresaPlacaAsigna(const Multa &mult);
    void eliminarInfraccionPagada();
    void leer(ifstream& arch);
    void imprime(ofstream& arch) const;
    int getDni() const;
    string getNombre() const;
    string getDistrito() const;
    bool operator<(const Empresa& emp) const;
};
ifstream &operator>>(ifstream& arch, Empresa& emp);
ofstream &operator<<(ofstream& arch, const Empresa& emp);
#endif //PROYECTO_EMPRESA_H