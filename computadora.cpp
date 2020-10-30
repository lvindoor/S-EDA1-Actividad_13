#include "computadora.h"

Computadora::Computadora() { }

Computadora::Computadora
(const string sistemaOperativo, const int ram,
const string nombreEquipo, const string procesador) {
    this->sistemaOperativo = sistemaOperativo;
    this->ram = ram;
    this->nombreEquipo = nombreEquipo;
    this->procesador = procesador;
}

/* Getters */

string Computadora::getSistemaOperativo() {
    return sistemaOperativo;
}

int Computadora::getRam() {
    return ram;
}

string Computadora::getNombreEquipo() {
    return nombreEquipo;
}

string Computadora::getProcesador() {
    return procesador;
}

/* Setters */

void Computadora::setSistemaOperativo(const string &so) {
    sistemaOperativo = so;
}

void Computadora::setRam(const int &r) {
    ram = r;
}

void Computadora::setNombreEquipo(const string &ne) {
    nombreEquipo = ne;
}

void Computadora::setProcesador(const string &p) {
    procesador = p;
}
