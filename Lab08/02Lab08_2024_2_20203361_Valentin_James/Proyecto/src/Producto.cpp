//
// Created by james on 13/11/2025.
//

#include "Producto.h"

Producto::Producto() {
    this->nombre=nullptr;
    this->precio=0.0;
}
Producto::~Producto() {
    liberarCadena(nombre);
}
Producto::Producto(const Producto &producto):Producto() {
    *this=producto;
}

Producto& Producto::operator=(const Producto& origen) {
    if (this==&origen) {
        return *this;
    }
    char aux[100];
    origen.getNombre(aux);
    setNombre(aux);
    setPrecio(origen.getPrecio());
    return *this;
}
// Comandas2.csv
// 142,B,Cafe,2,grande
// 142,B,Agua Mineral,2.5,pequeno
// 142,E,Quesadillas,5.5,sin picante
// 142,E,Bruschetta,4,picante
// 142,P,Pasta Alfredo,10,4
// 142,P,Pollo a la Brasa,15,1

// ID, tipo, nombre, precio, tamaño/picante/proteina.
void Producto::lee(ifstream &arch) {
    char nombre[50];
    arch.getline(nombre, 50,',');
    setNombre(nombre);
    arch>>precio;
    arch.ignore();
}
void Producto::imprime(ostream& arch){
    arch<<"Nombre: "<<nombre<<endl;
    arch<<"Precio: "<<precio<<endl;
}
void Producto::getNombre(char *nom) const {
    if (nombre==nullptr) {
        nom[0]=0;
    }else {
        strcpy(nom,nombre);
    }
}

void Producto::setNombre(const char * nombre) {
    liberarCadena(this->nombre);
    this->nombre = miString(nombre);
}

double Producto::getPrecio() const {
    return precio;
}

void Producto::setPrecio(const double precio) {
    this->precio = precio;
}

