#ifndef COMPUTADORA_H
#define COMPUTADORA_H

#include <iostream>
#include <iomanip>


using namespace std;

class Computadora {
private:    
    std::string sistemaOperativo;
    int ram;
    std::string nombreEquipo;
    std::string procesador;
public:
    Computadora();
    Computadora(const std::string sistemaOperativo,
             const int ram,
             const std::string nombreEquipo,
             const std::string procesador);
    
    /* Getters */
    std::string getSistemaOperativo();
    int getRam();
    std::string getNombreEquipo();
    std::string getProcesador();

    /* Setters */
    void setSistemaOperativo(const std::string &so);
    void setRam(const int &r);
    void setNombreEquipo(const std::string &ne);
    void setProcesador(const std::string &p);

    /* Salida del Modelo */
    friend ostream& operator<<(ostream &out, const Computadora &c) {
        
        out << left;
        out << setw(20) << c.sistemaOperativo;
        out << setw(10) << c.ram;
        out << setw(20) << c.nombreEquipo;
        out << setw(16) << c.procesador;
        out << endl;
        
        return out;
    }

    /* Entrada del Modelo */
    friend istream& operator>>(istream &in, Computadora &c) {

        cout << "Sistema Operativo  : ";
        getline(cin, c.sistemaOperativo);

        cout << "RAM (GB)           : ";
        cin >> c.ram;

        cin.ignore();
        cout << "Nombre del Equipo  : ";
        getline(cin, c.nombreEquipo);

        cout << "Procesador         : ";
        getline(cin, c.procesador);

        return in;
    }

    /* Operadores Logicos */

    bool operator==(const Computadora& c) {
        return nombreEquipo == c.nombreEquipo;
    }

    bool operator==(const Computadora& c) const {
        return nombreEquipo == c.nombreEquipo;
    }

};

#endif