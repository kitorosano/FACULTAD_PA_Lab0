//
// Created by Mathi on 7/4/2022.
//

#include "Videojuego.h"
Videojuego::Videojuego(string nombre, TipoGenero genero) {
    this->nombre = nombre;
    this->genero = genero;
}

Videojuego::~Videojuego() {}

string Videojuego::getNombre() {
    return this->nombre;
}

TipoGenero Videojuego::getGenero() {
    return this->genero;
}

void Videojuego::setNombre(string nombre) {
    this->nombre = nombre;
}

void Videojuego::setGenero(TipoGenero genero) {
    this->genero = genero;
}
