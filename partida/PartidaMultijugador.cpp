#include "PartidaMultijugador.h"

using namespace std;

PartidaMultijugador::PartidaMultijugador(dtFechaHora fecha, float duracion, Videojuego videojuego, Jugador jugadorIniciador, bool transmitidaEnVivo, vector<Jugador*> jugadores):Partida(fecha, duracion, videojuego, jugadorIniciador) {
    this->transmitidaEnVivo = transmitidaEnVivo;
}

bool PartidaMultijugador::getContinuaPartidaAnterior() {
    return this->transmitidaEnVivo;
}

void PartidaMultijugador::setTransmitidaEnVivo(bool transmitidaEnVivo) {
    this->transmitidaEnVivo = transmitidaEnVivo;
}

float PartidaMultijugador::darTotalHorasParticipantes() {
    //TODO
}
