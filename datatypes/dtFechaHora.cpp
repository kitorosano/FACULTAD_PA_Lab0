#include "dtFechaHora.h"

dtFechaHora::dtFechaHora() {}

dtFechaHora::dtFechaHora(int dd, int MM, int aaaa, int HH, int mm, int ss) {};

int dtFechaHora::getDia() {
    return this->dd;
};
int dtFechaHora::getMes() {
    return this->MM;
};
int dtFechaHora::getAnio() {
    return this->aaaa
};
int dtFechaHora::getHora() {
    return this->HH;
};
int dtFechaHora::getMinuto() {
    return this->mm;
};
int dtFechaHora::getSegundo() {
    return this->ss;
};

string dtFechaHora::toString() {};