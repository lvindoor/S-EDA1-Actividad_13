#ifndef ARREGLO_H
#define ARREGLO_H

/** Declaración **/

#include <iostream>

template <class T> // Declaramos la plantilla
class Arreglo {
private:
    T *arreglo; // arreglo de tipo plantilla
    size_t tam; // tamaño
    size_t cont; // contador
    const static size_t TAM_MAX = 100; // total arreglo

    void expandir(); // expande arreglo

public:
    Arreglo(); // constructor
    ~Arreglo(); // destructor
    size_t size(); // trae tamaño arreglo

    /* Inserciones al arreglo */
    void insertar(const T&, size_t);
    void insertarInicio(const T&);
    void insertarFinal(const T&);

    /* Eliminaciones al arreglo */
    void eliminar(size_t);
    void eliminarInicio();
    void eliminarFinal();

    /* Operadores logicos */
    T operator[](size_t p) {
        return arreglo[p];
    }

};

/** Implementación **/

using namespace std;

template <class T>
void Arreglo<T>::expandir() {
    T *nuevo = new T[tam+TAM_MAX];
    /* Respaldamos al nuevo arreglo */
    for(size_t i=0;i<cont;i++) {
        nuevo[i] = arreglo[i];
    }
    delete[] arreglo; // borramos el arreglo viejo
    arreglo = nuevo; // copia direcciones de memoria
    tam+=TAM_MAX; // duplicamos tamaño
}

template <class T>
Arreglo<T>::Arreglo() {
    arreglo = new T[TAM_MAX];
    cont = 0;
    tam = TAM_MAX; 
}

template <class T>
Arreglo<T>::~Arreglo() {
    delete[] arreglo;
}

template <class T>
void Arreglo<T>::insertar(const T &s, size_t p) {
    if(p>=cont) { // ¿Posición valida?
        cout << "Posicion ivalida" << endl;
        return; // terminamos la función
    }
    
    if(cont==tam) { // ¿Esta lleno?
       expandir(); // expandimos arreglo 
    }

    for(size_t i=cont;i>p;i--) { // movemos arreglo
        arreglo[i] = arreglo[i-1]; // movemos el elemento para liberar pos
    }

    arreglo[p] = s; // asignamos el elemento
    cont++;
}
template <class T>
void Arreglo<T>::insertarInicio(const T &s) {
    if(cont==tam) { // ¿Esta lleno?
       expandir(); // expandimos arreglo 
    }

    /* Insertamos al inicio */
    for(size_t i=cont;i>0;i--) { // movemos arreglo
        arreglo[i] = arreglo[i-1]; // hacia derecha
    }
    arreglo[0] = s;
    cont++;
}

template <class T>
void Arreglo<T>::insertarFinal(const T &s) {
    if(cont==tam) { // ¿Esta lleno?
       expandir(); // expandimos arreglo 
    }
    /* Insertamos al final */
    arreglo[cont] = s; 
    cont++;
}

template <class T>
void Arreglo<T>::eliminar(size_t p) {
    if(cont==0) { // ¿Esta vacio?
        cout << "Arreglo vacio" << endl;
        return; // terminamos la funcion
    }

    for(size_t i=p;i<cont-1;i++) { // movemos el arreglo
        arreglo[i] = arreglo[i+1]; // copiamos la la posicion a la derecha
    }

    cont--; // reducimos contador
}

template <class T>
void Arreglo<T>::eliminarInicio() {
    if(cont==0) { // ¿Esta vacio?
        cout << "Arreglo vacio" << endl;
        return; // terminamos la funcion
    }

    for(size_t i=0;i<cont-1;i++) { // movemos arreglo
        arreglo[i] = arreglo[i+1]; // limpiamos pos a la izquierda
    }

    cont --; // reducimos contador
}

template <class T>
void Arreglo<T>::eliminarFinal() {
    if(cont==0) { // ¿Esta vacio?
        cout << "Arreglo vacio" << endl;
        return; // terminamos la funcion
    }

    cont--; // reducimos el contador
}

template <class T>
size_t Arreglo<T>::size() {
    return cont; // Elementos del arreglo
}

#endif