#include "Partida.h"
#include <sstream>

using namespace std;

Partida::Partida() {}

Partida::Partida(float duracion) {
    this->duracion = duracion;
}

void Partida::setFecha(dtFechaHora fecha) {
    this->fecha = fecha;
}

void Partida::setDuracion(float duracion) {
    this->duracion = duracion;
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
Jugador Partida::getJugadorIniciador() {
    return jugadorIniciador;
}

string Partida::toString() {
    stringstream ss;
    ss << "Fecha: " << getFecha().toString() << endl;
    ss << "Duracion: " << getDuracion() << "hrs"<< endl;
    ss << "Jugador iniciador: " << getJugadorIniciador().toString() << endl;
    return ss.str();
}