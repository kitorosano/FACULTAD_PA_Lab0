#include <sstream>
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

vector<Partida*> Videojuego::getPartidas() {
    return this->partidas;
}

int Videojuego::getCantidadPartidas() {
    return this->partidas.size();
}

void Videojuego::setNombre(string nombre) {
    this->nombre = nombre;
}

void Videojuego::setGenero(TipoJuego genero) {
    this->genero = genero;
}

void Videojuego::guardarPartida(Partida* partida) {
  //seteo las horas
  this->partidas.push_back(partida);
}

void Videojuego::setTotalHorasJuego(long totalHorasJuego) {
    this->totalHorasJuego = totalHorasJuego;
}

string Videojuego::toString() {
    stringstream ss;
    ss<<"|------------"<<endl;
    ss<<"| Nombre: "<< getNombre()<<endl;
    ss<<"| Genero: "<< getGenero()<<endl;
    ss<<"| Total de horas jugadas: "<<getTotalHorasJuego()<<endl;
    ss<<"|------------"<<endl;
    return ss.str();
}
