#include "Partida.h"

using namespace std;

Partida::Partida() {}

Partida::Partida(dtFechaHora fecha, float duracion, Videojuego videojuego, Jugador jugadorIniciador) {
    this->fecha = fecha;
    this->duracion = duracion;
    this->videojuego = videojuego;
    this->jugadorIniciador = jugadorIniciador;
}

void Partida::setFecha(dtFechaHora fecha) {
    this->fecha = fecha;
}

void Partida::setDuracion(float duracion) {
    this->duracion = duracion;
}

void Partida::setVideojuego(Videojuego videojuego) {
    this->videojuego = videojuego;
}

void Partida::setJugadorIniciador(Jugador jugadorIniciador) {
    this->jugadorIniciador = jugadorIniciador;
}

dtFechaHora Partida::getFecha() {
    return fecha;
}

float Partida::getDuracion() {
    return duracion;
}

float Partida::darTotalHorasParticipantes() {
    return duracion;
}

Videojuego Partida::getVideojuego() {
    return videojuego;
}

Jugador Partida::getJugadorIniciador() {
    return jugadorIniciador;
}

