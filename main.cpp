#include <iostream>
#include "arreglo.h"

using namespace std;

int main() {

    Arreglo<string> arreglo; // declaramos un arreglo string
    
    /* Insertar al Inicio */
    arreglo.insertarInicio("Cuarto");
    arreglo.insertarInicio("Tercero");
    arreglo.insertarInicio("Segundo");
    arreglo.insertarInicio("Primero");

    /* Insertar al Final */
    arreglo.insertarFinal("Quinto");
    arreglo.insertarFinal("Sexto");
    arreglo.insertarFinal("Septimo");
    arreglo.insertarFinal("Octavo");

    /* Mostrar Arreglo */
    for(size_t i=0;i<8;i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    /* Insertar en posición 2 */
    arreglo.insertar("Insercion",2);

    /* Mostrar Arreglo */
    for(size_t i=0;i<9;i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    /* Eliminar con: eliminarInicio() y eliminarFinal() */
    arreglo.eliminarInicio();
    arreglo.eliminarFinal();

    /* Eliminar con: eliminar() en posición 1 */
    arreglo.eliminar(1);

    /* Mostrar Arreglo */
    for(size_t i=0;i<6;i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    return 0;
}