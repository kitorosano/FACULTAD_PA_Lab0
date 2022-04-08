//
// Created by Mathi on 7/4/2022.
//

#include "Partida.h"
#include "../datatypes/dtFechaHora.h"
using namespace std;

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

float Partida::darTotalHorasParticipantes() {
    return duracion;
}

Videojuego Partida::getVideojuego() {
    return videojuego;
}

Jugador Partida::getJugadorIniciador() {
    return jugadorIniciador;
}

