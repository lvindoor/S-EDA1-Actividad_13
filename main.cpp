#include <iostream>
#include "arreglo.h"
#include "computadora.h"

using namespace std;

int main() {

    Arreglo<Computadora> computadoras; // declaramos un arreglo de computadoras

    /* Agregar 5 Computadoras */
    Computadora c_01("Windows 10", 8, "Alejandro Garcia", "Core i7");
    Computadora c_02("Ubuntu 18.04", 4, "Ivindoor", "Ryzen Pro 7");
    Computadora c_03("Debian 10", 1, "Frecks", "Cortex-A53");

    /* Agregamos arreglo */
    computadoras << c_01 << c_02 << c_03;
    /* Añadimos 2 copias al arreglo */
    computadoras << c_03 << c_03;

    /* Buscamos coincidencias */
    Arreglo<Computadora*> ptrsC = computadoras.buscarTodos(c_03);

    if(ptrsC.size()>0) { // Recorremos puntero
        for(size_t i=0;i<ptrsC.size();i++) { // recorremos arreglo de punteros
            Computadora *c = ptrsC[i];
            cout << *c << endl; // imprimimos el elemento
        }
    } else {
        cout << "No existen coincidencias" << endl;
    }

    /* Buscar una computadora existente */
    Computadora *puntero = computadoras.buscar(c_01);

    if(puntero!=nullptr) { // ¿Esta vacia?
        cout << *puntero << endl; // Imprimimos elemento
    } else {
        cout << "No existe" << endl; // No se encontro
    }

    return 0;
}
