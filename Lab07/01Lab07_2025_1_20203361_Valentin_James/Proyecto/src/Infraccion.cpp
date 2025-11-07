//
// Created by james on 6/11/2025.
//

#include "Infraccion.h"
#include "Comunes.h"
// ---------- Constructores / Destructor ----------

//Constructor por defecto
Infraccion::Infraccion() {
    fecha_evento=0;
    tipo_infraccion=nullptr;
    monto=0.0;
    fecha_pago_limite=0;
    placa=nullptr;
}
// Constructor copia
Infraccion::Infraccion(const Infraccion &infraccion):Infraccion() {
    *this=infraccion;
}
// Destructor
Infraccion::~Infraccion() {
    liberarCadena(tipo_infraccion);
    liberarCadena(placa);
}

// ---------- Operador = ----------
Infraccion &Infraccion::operator=(const Infraccion &origen) {
    if (this==&origen) return *this;
    fecha_evento=origen.fecha_evento;
    setTipoInfraccion(origen.getTipoInfraccion());
    monto=origen.monto;
    fecha_pago_limite=origen.fecha_pago_limite;
    setPlaca(origen.getPlaca());
    return *this;
}

//-------------Setters------------
void Infraccion::setFechaEvento(int fecha_evento) {
    this->fecha_evento=fecha_evento;
}
void Infraccion::setTipoInfraccion(char *tipo_infraccion) {
    liberarCadena(this->tipo_infraccion);
    this->tipo_infraccion=miString(tipo_infraccion);
}
void Infraccion::setMonto(double monto) {
    this->monto=monto;
}
void Infraccion::setFechaPagoLimite(int fecha_pago_limite) {
    this->fecha_pago_limite=fecha_pago_limite;
}
void Infraccion::setPlaca(char *placa) {
    liberarCadena(this->placa);
    this->placa=miString(placa);
}
//-------------Getters------------
int Infraccion::getFechaEvento() const {
    return fecha_evento;
}
char* Infraccion::getTipoInfraccion() const {
    return tipo_infraccion;
}
double Infraccion::getMonto() const {
    return monto;
}
int Infraccion::getFechaPagoLimite() const {
    return fecha_pago_limite;
}
char* Infraccion::getPlaca() const {
    return placa;
}
//-------------Métodos------------
void Infraccion::leer(ifstream &arch) {

}

void Infraccion::imprimir(ofstream &arch) const{

}