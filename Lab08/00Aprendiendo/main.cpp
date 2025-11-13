#include <iostream>
using namespace std;
class Nodo {
public:
    virtual void procesar() = 0;
    virtual ~Nodo() = default;
};

class NodoEntero : public Nodo {
    int valor;
public:
    NodoEntero(int v) : valor(v) {}
    void procesar() override { cout << "Nodo entero: " << valor << endl; }
};

class NodoTexto : public Nodo {
    string texto;
public:
    NodoTexto(string t) : texto(t) {}
    void procesar() override { cout << "Nodo texto: " << texto << endl; }
};

class NodoArbol {
public:
    Nodo* dato;
    NodoArbol* izquierda;
    NodoArbol* derecha;

    NodoArbol(Nodo* d) : dato(d), izquierda(nullptr), derecha(nullptr) {}

    void recorrer() {
        if (izquierda) izquierda->recorrer();
        dato->procesar();
        if (derecha) derecha->recorrer();
    }

    ~NodoArbol() {
        delete dato;        // llama al destructor correcto (por virtual)
        delete izquierda;
        delete derecha;
    }
};

int main() {
    NodoArbol nodo_arbol;

}
