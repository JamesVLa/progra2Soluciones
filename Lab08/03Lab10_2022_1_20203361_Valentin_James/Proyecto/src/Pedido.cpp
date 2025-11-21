//
// Created by james on 21/11/2025.
//

#include "Pedido.h"

Pedido::Pedido() {
    codigo=0;
    nombre=nullptr;
    cantidad=0;
    dni=0;
    fecha=0;
    total=0.0;
}

Pedido::~Pedido() {
    liberarCadena(nombre);
}
Pedido::Pedido(const Pedido &p):Pedido() {
    *this=p;
}
Pedido& Pedido::operator=(const Pedido &p) {
    if (this==&p) return *this;
    setCodigo(p.getCodigo());
    setNombre(p.getNombre());
    setCantidad(p.getCantidad());
    setDni(p.getDni());
    setFecha(p.getFecha());
    setTotal(p.getTotal());
    return *this;
}

//LECHE LALA SEMI DESLACTOSADA 1LT,0,0,46462527,18/10/2019
//CHURROMAIS CON LIMON 38GR,9,4.5,32821689,19/10/2021
//nombre, Cantidad, monto del pedido, DNI del cliente,Fecha del pedido.

void Pedido::lee(ifstream &arch) {
    int dd,mm,yyyy;
    char cad[100],c;
    arch.getline(cad,100,',');//LECHE LALA SEMI DESLACTOSADA 1LT,0,0,46462527,18/10/2019
    setNombre(cad);
    arch>>cantidad;//0,0,46462527,18/10/2019
    arch.ignore();//,0,46462527,18/10/2019
    arch>>total;//0,46462527,18/10/2019
    arch.ignore();//,46462527,18/10/2019
    arch>>dni;//46462527,18/10/2019
    arch.ignore();//,18/10/2019
    arch>>dd>>c>>mm>>c>>yyyy;//18/10/2019
    arch.get();
    setFecha(yyyy*10000+mm*100+dd);
}
void Pedido::imprime(ostream &arch) {
    int dd,mm,yyyy;
    sacarFecha(getFecha(),dd,mm,yyyy);
    arch<<dd<<'/'<<mm<<'/'<<yyyy<<endl;
    arch<<setw(10)<<left<<codigo<<nombre<<endl;
    arch<<"DNI: "<<right<<setw(10)<<dni<<endl;
    arch<<"Monto Total: "<<total<<endl;
}

bool Pedido::operator<(const Pedido &p) const {
    if (dni!=p.getDni()) return (dni<p.getDni());
    return (fecha<p.getFecha());
}
bool Pedido::operator>(const Pedido &p) const {
    return (fecha>p.getFecha());
}

void Pedido::setCodigo(int codigo) {
    this->codigo=codigo;
}
void Pedido::setNombre(const char* nombre) {
    liberarCadena(this->nombre);
    this->nombre=miString(nombre);
}
void Pedido::setCantidad(int cantidad) {
    this->cantidad=cantidad;
}
void Pedido::setDni(int dni) {
    this->dni=dni;
}

void Pedido::setFecha(int fecha) {
    this->fecha=fecha;
}

void Pedido::setTotal(double total) {
    this->total=total;
}

int Pedido::getCodigo() const {
    return codigo;
}
const char *Pedido::getNombre() const {
    return nombre;
}
int Pedido::getCantidad() const {
    return cantidad;
}
int Pedido::getDni() const {
    return dni;
}
int Pedido::getFecha() const {
    return fecha;
}
double Pedido::getTotal() const {
    return total;
}





