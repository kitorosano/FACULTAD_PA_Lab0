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

TipoJuego Videojuego::getGenero() {
    return this->genero;
}

long Videojuego::getTotalHorasJuego() {
    return this->totalHorasJuego;
}

void Videojuego::setNombre(string nombre) {
    this->nombre = nombre;
}

void Videojuego::setGenero(TipoJuego genero) {
    this->genero = genero;
}

void Videojuego::setTotalHorasJuego(long totalHorasJuego) {
    this->totalHorasJuego = totalHorasJuego;
}
