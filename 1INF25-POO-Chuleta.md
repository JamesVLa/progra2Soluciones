# ⚡ Chuleta rápida – Clases, Constructores, Sobrecarga y qsort (C++)

---

## 📄 Usuario.h

```cpp
#ifndef USUARIO_H
#define USUARIO_H

class Usuario {
public:
    // Constructores / Destructor
    Usuario();                            // por defecto
    Usuario(char* cuenta, char* nombre);  // propiamente dicho
    Usuario(const Usuario&);              // copia
    ~Usuario();                           // destructor

    // Setters / Getters
    void setCuenta(char* c);
    char* getCuenta() const;

    // Sobrecarga de asignación
    Usuario& operator=(const Usuario&);

    // Getter adicional para ejemplo qsort
    int getEdad() const { return edad; }

private:
    char* cuenta;
    char* nombre;
    int edad;
};

// Función de comparación para qsort
int compararUsuarios(const void* a, const void* b);

#endif
```

---

## ⚙️ Usuario.cpp

```cpp
#include "Usuario.h"
#include <cstring>
#include <cstdlib> // qsort

// ---------- Constructores / Destructor ----------

// Constructor por defecto
Usuario::Usuario() : cuenta(nullptr), nombre(nullptr), edad(0) {}

// Constructor propiamente dicho
Usuario::Usuario(char* cuenta_, char* nombre_)
    : Usuario() { // llama al constructor por defecto
    setCuenta(cuenta_);
    // setNombre(nombre_);
}

// Constructor de copia
Usuario::Usuario(const Usuario& origen) : Usuario() {
    *this = origen; // reutiliza operator=
}

// Destructor
Usuario::~Usuario() {
    delete[] cuenta;
    delete[] nombre;
}

// ---------- Operador = ----------
Usuario& Usuario::operator=(const Usuario& origen) {
    if (this == &origen) return *this;
    setCuenta(origen.getCuenta());
    // setNombre(origen.getNombre());
    edad = origen.edad;
    return *this;
}

// ---------- Getters ----------
char* Usuario::getCuenta() const { return cuenta; }

// ---------- Setters: 3 opciones para char* ----------

// 🟢 Opción 1: Versión básica
void Usuario::setCuenta(char* c) {
    delete[] this->cuenta;
    if (c) {
        this->cuenta = new char[strlen(c) + 1];
        strcpy(this->cuenta, c);
    } else this->cuenta = nullptr;
}

// 🟢 Opción 2: Genérica (usa función auxiliar)
void setCadenaGeneric(char*& destino, const char* origen) {
    delete[] destino;
    if (origen) {
        destino = new char[strlen(origen) + 1];
        strcpy(destino, origen);
    } else destino = nullptr;
}

void Usuario::setCuenta(char* c) {
    setCadenaGeneric(this->cuenta, c);
}

// 🟢 Opción 3: Con mi_strdup
char* mi_strdup(const char* s) {
    if (!s) return nullptr;
    char* copia = new char[strlen(s) + 1];
    strcpy(copia, s);
    return copia;
}

void Usuario::setCuenta(char* c) {
    delete[] this->cuenta;
    this->cuenta = mi_strdup(c);
}
```

---

## 🧩 Utilidades comunes

Estas funciones son útiles para liberar o duplicar cadenas sin repetir código.

```cpp
// Copia cadena (versión genérica)
void setCadenaGeneric(char*& destino, const char* origen);

// Duplica una cadena nueva
char* mi_strdup(const char* s);

// Libera memoria de cadena y pone puntero en nullptr
void libera_cadena(char *&cadena) {
    if (cadena != nullptr) {
        delete[] cadena; // usar delete[] si fue asignado con new[]
        cadena = nullptr;
    }
}
```

💡 _Recuerda usar `delete[]` en lugar de `delete` simple cuando hayas hecho `new[]`._

---

## 🔢 qsort

```cpp
int compararUsuarios(const void* a, const void* b) {
    const Usuario* ua = (const Usuario*)a;
    const Usuario* ub = (const Usuario*)b;
    return ua->getEdad() - ub->getEdad();
}

// Uso:
qsort(usuarios, cantUsuarios, sizeof(Usuario), compararUsuarios);
```

---
## 🔢 Sobrecarga operator[] (indexador)

### En el `.h`

```cpp
Usuario& operator[](int);
const Usuario& operator[](int) const;

Usuario& operator[](const char*);
const Usuario& operator[](const char*) const;

Usuario& at(int);
const Usuario& at(int) const;
```

### En el `.cpp`

```cpp
Usuario& RedSocial::operator[](int i) {
    if (i < 0 || i >= cantUsuarios) exit(1);
    return usuarios[i];
}

Usuario& RedSocial::operator[](const char* cuenta) {
    for (int i = 0; i < cantUsuarios; i++)
        if (strcmp(usuarios[i].getCuenta(), cuenta) == 0)
            return usuarios[i];
    cerr << "No existe la cuenta: " << cuenta << endl;
    exit(1);
}

Usuario& RedSocial::at(int i) {
    if (i < 0 || i >= cantUsuarios) exit(1);
    return (*this)[i];
}
```

### Ejemplo de uso

```cpp
Usuario u = redSocial[3];
Usuario x = redSocial.at(3);
Usuario& ref = (*this)["juan23"]; // ¡IMPORTANTE!
```

> `(*this)[cuenta]` → el paréntesis es necesario porque `this` es puntero; sin él harías aritmética de punteros (`this[cuenta]` ❌).

### Ejemplo real (profesor)

```cpp
void RedSocial::cargarPublicaciones(const char* arch) {
    Publicacion p;
    ifstream f(arch, ios::in);
    while (f >> p) {
        const char* cuenta = p.getCuenta();
        Usuario& u = (*this)[cuenta];
        u += p;
    }
}
```

---

## 💡 Recordatorios rápidos

|Concepto|Sintaxis / Uso|
|---|---|
|Constructor copia|`Clase(const Clase&);`|
|Destructor|`~Clase();`|
|Asignación|`Clase& operator=(const Clase&);`|
|Crear objeto|`Clase obj;`|
|Crear puntero|`Clase* p = new Clase; delete p;`|
|delete seguro|`delete[] nullptr;` ✅|
|Evitar duplicar código|Usa `setCadenaGeneric()` o `mi_strdup()`|
|Liberar cadena|`libera_cadena(ptr);`|
|Ordenar con qsort|`qsort(arr, n, sizeof(T), comparar);`|

## 🧰 Tipos de clases

- **Entidad:** datos (`Usuario`, `Curso`, `Publicacion`).
- **Controladora:** agrupa/gestiona (`RedSocial`).
- **Servicio/Helper:** auxiliares (`Registro`, `Archivo`).

---

## 📋 Requisitos mínimos de clase completa

- Constructor por defecto
- Constructor de copia
- Destructor
- Setters / Getters
- Sobrecarga de:
    - `=` (asignación)
    - `>>` (lectura)
    - `<<` (escritura)
    - `[]` (indexador)
    - `+=` (agregar elemento)
- Implementar `qsort` si necesita ordenamiento

# 🧾 **Chuleta Herencia C++**

## 🔹 Definición básica

```cpp
class Derivada : public Base {
    // nuevos atributos y métodos
};
```

- **public:** hereda lo público y protegido como público/protegido.
    
- **protected:** hereda lo público y protegido como protegido.
    
- **private:** todo se vuelve privado en la derivada.
    

---

## 🔸 Accesos en herencia

|Miembro base|Herencia pública|Herencia protegida|Herencia privada|
|---|---|---|---|
|`public`|`public`|`protected`|`private`|
|`protected`|`protected`|`protected`|`private`|
|`private`|❌ no accesible|❌ no accesible|❌ no accesible|

📘 _La derivada puede acceder a `protected`, pero no a `private`._

---

## 🧩 **Constructores y destructores**

**Orden de construcción y destrucción:**

🧠 Construcción: **Base → Derivada**  
🧹 Destrucción: **Derivada → Base**

---

### 1️⃣ Constructor por defecto

Si no lo declaras, la derivada **llama automáticamente** al **constructor por defecto** de la base.

```cpp
class Base {
public:
    Base() { cout << "Base()\n"; }
};

class Derivada : public Base {
public:
    Derivada() { cout << "Derivada()\n"; }
};
```

🧾 Salida:

```
Base()
Derivada()
```

---

### 2️⃣ Constructor con parámetros

Para inicializar la base con parámetros, se debe llamar **explícitamente**:

```cpp
Derivada(char* nombre, char* dni, int codigo, char* fac, int ciclo)
    : Base(nombre, dni, codigo), facultad(nullptr), ciclo(0) {
    setFacultad(fac);
    this->ciclo = ciclo;
}
```

Si **no llamas al constructor base con parámetros**, se usa su **constructor por defecto**, lo cual puede causar valores erróneos.

---

### 3️⃣ Constructor copia

Hay dos formas válidas:

**Forma A (recomendada, usa operador = para evitar duplicar código):**

```cpp
Derivada(const Derivada& orig)
    : facultad(nullptr), ciclo(0) {
    *this = orig;
}
```

**Forma B (llamando constructor copia de base directamente):**

```cpp
Derivada(const Derivada& orig)
    : Base(orig), facultad(nullptr), ciclo(0) {
    setFacultad(orig.facultad);
    ciclo = orig.ciclo;
}
```

---

## 🔁 **Operador = en herencia**

Debe llamar al `operator=` de la base para copiar sus partes.

```cpp
Derivada& Derivada::operator=(const Derivada& orig) {
    if (this == &orig) return *this;

    Base::operator=(orig); // importante!
    setFacultad(orig.facultad);
    ciclo = orig.ciclo;

    return *this;
}
```

---

## 💣 **Destructor**

Siempre destructor **virtual** si la clase se usará con polimorfismo (aunque aún no lo estés usando).

```cpp
virtual ~Base();
```

Orden de destrucción:

```
~Derivada()
~Base()
```

---

## 🧱 **Ocultamiento y sobreescritura**

- Si **no hay virtual**, el método de la derivada **oculta** el de la base.
    
- Puedes seguir accediendo al de la base con `Base::metodo()`.
    

```cpp
void Derivada::imprimir() {
    Base::imprimir();
    cout << "Facultad: " << facultad << endl;
}
```

---

## 🧰 **Zona protegida (`protected`)**

- Accesible **solo dentro de la clase y sus derivadas**.
    
- No accesible para objetos externos.
    
- Útil para heredar atributos sin exponerlos al público.
    

```cpp
class Base {
protected:
    int edad;
};
class Derivada : public Base {
    void mostrar() { cout << edad; }
};
```

---

## 🏗️ **Tipos de herencia**

|Tipo|Descripción|
|---|---|
|**Simple**|Una clase hereda de una sola base.|
|**Múltiple**|Hereda de varias bases. Ej: `class D : public A, public B {}`|
|**Jerárquica**|Una clase base tiene varias derivadas.|
|**Multinivel**|Derivada de derivada. Ej: `A → B → C`.|

---

## 💎 **Herencia múltiple y virtual**

Evita duplicar la clase base cuando hay un “diamante”.

```cpp
class Persona { };
class Alumno : virtual public Persona { };
class Profesor : virtual public Persona { };
class Ayudante : public Alumno, public Profesor { };
```

- 🔸 Sin `virtual`: 2 instancias de `Persona`.
    
- 🔹 Con `virtual`: solo **1 instancia compartida**.
    
- 🧠 El constructor de la **más derivada** (Ayudante) llama al de la base virtual.
    

---

## ⚙️ **Buenas prácticas en herencia**

✅ Usa **public** para relaciones “es-un”.  
✅ Declara destructores virtuales en clases base con métodos virtuales.  
✅ Inicializa la **base** siempre en la lista de inicialización.  
✅ Usa `protected` con cuidado: puede romper el encapsulamiento.  
✅ Evita la herencia múltiple si no es necesaria.  
✅ Si ocultas métodos, acláralo con `using Base::metodo;` si quieres reexponerlos.

---

## ⚡ **Mini ejemplo completo**

```cpp
class Alumno {
protected:
    char* nombre;
    char* dni;
    int codigo;
public:
    Alumno(char* n = nullptr, char* d = nullptr, int c = 0);
    Alumno(const Alumno&);
    Alumno& operator=(const Alumno&);
    virtual ~Alumno();
    virtual void imprimir() const;
};

class AlumnoUniversitario : public Alumno {
    char* facultad;
    int ciclo;
public:
    AlumnoUniversitario(char*, char*, int, char*, int);
    AlumnoUniversitario(const AlumnoUniversitario&);
    AlumnoUniversitario& operator=(const AlumnoUniversitario&);
    void imprimir() const override;
    ~AlumnoUniversitario();
};
```

---

## 🧠 **Resumen ultra corto**

|Concepto|Clave|
|---|---|
|Orden construcción|Base → Derivada|
|Orden destrucción|Derivada → Base|
|Herencia pública|Mantiene visibilidad|
|Constructor copia|Llama a base o usa `=`|
|Destructor|Debe ser virtual si hay polimorfismo|
|Ocultamiento|`Base::metodo()` para acceder|
|Protected|Acceso solo derivadas|
|Virtual base|Evita duplicar en herencia múltiple|
