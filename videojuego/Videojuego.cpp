#include "Videojuego.h"
Videojuego::Videojuego(string nombre, TipoJuego genero) {
    this->nombre = nombre;
    this->genero = genero;
}

Videojuego::~Videojuego() {}

string Videojuego::getNombre() {
    return this->nombre;
}

TipoJuego Videojuego::getGenero() {
    return this->genero;
}

void Videojuego::setNombre(string nombre) {
    this->nombre = nombre;
}

void Videojuego::setGenero(TipoJuego genero) {
    this->genero = genero;
}
