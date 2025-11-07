//
// Created by james on 6/11/2025.
//

#include "Drone.h"
#include "Comunes.h"
// ---------- Constructores / Destructor ----------
//Constructor por defecto
Drone::Drone() {
    id=nullptr;
    ubicacion=nullptr;
    capacidad=0;
    cantidad_infracciones=0;
}

// Constructor copia
Drone::Drone(const Drone &drone):Drone() {
    *this=drone;
}

// Destructor
Drone::~Drone() {
    liberarCadena(id);
    liberarCadena(ubicacion);
}
// ---------- Operador = ----------
Drone &Drone::operator=(const Drone &origen) {
    if (this==&origen)return *this;
    setId(origen.getId());
    setUbicacion(origen.getUbicacion());
    capacidad=origen.capacidad;
    cantidad_infracciones=origen.cantidad_infracciones;
    for (int i=0;i<cantidad_infracciones;i++)
        infracciones[i]=origen.infracciones[i];
    return *this;
}
//-------------Setters------------
void Drone::setId(char *id) {
    liberarCadena(this->id);
    this->id=miString(id);
}
void Drone::setUbicacion(char *ubicacion) {
    liberarCadena(this->ubicacion);
    this->ubicacion=miString(ubicacion);
}
void Drone::setCapacidad(int capacidad) {
    this->capacidad=capacidad;
}
void Drone::setCantidadInfracciones(int cantidad_infracciones) {
    this->cantidad_infracciones=cantidad_infracciones;
}
//-------------Getters------------
char *Drone::getId() const {
    return this->id;
}
char *Drone::getUbicacion() const {
    return this->ubicacion;
}
int Drone::getCapacidad() const {
    return this->capacidad;
}
int Drone::getCantidadInfracciones() const {
    return this->cantidad_infracciones;
}

//-----------METODOS--------
void Drone::leer(ifstream &arch) {
    char buffer[100];
    arch.getline(buffer, 100,',');
    setId(buffer);
    arch.getline(buffer, 100,',');
    setUbicacion(buffer);
    arch>>capacidad;
    arch.get();
}
