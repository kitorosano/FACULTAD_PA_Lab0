#include "Videojuego.h"

Videojuego::Videojuego() {}

Videojuego::Videojuego(string nombre, TipoJuego genero) {
    this->nombre = nombre;
    this->genero = genero;
    this->totalHorasJuego = 0;
}

Videojuego::~Videojuego() {}

string Videojuego::getNombre() {
    return this->nombre;
}

string Videojuego::getGenero() {
    return TipoJuego_str[this->genero]; //CONSIDERAR CAMBIARLO POR UN SWITCH
}

long Videojuego::getTotalHorasJuego() {
    return this->totalHorasJuego;
}

void Videojuego::setNombre(string nombre) {
    this->nombre = nombre;
}

void Videojuego::setGenero(string genero) {
    this->genero = genero;
}

void Videojuego::setTotalHorasJuego(long totalHorasJuego) {
    this->totalHorasJuego = totalHorasJuego;
}
