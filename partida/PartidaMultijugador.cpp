#include "PartidaMultijugador.h"

using namespace std;

PartidaMultijugador::PartidaMultijugador(float duracion, bool transmitidaEnVivo, vector<Jugador*> jugadores):Partida(duracion) {
    this->transmitidaEnVivo = transmitidaEnVivo;
    videojuego.setTotalHorasJuego(videojuego.getTotalHorasJuego() + this->darTotalHorasParticipantes());
}

bool PartidaMultijugador::getTransmitidaEnVivo() {
    return this->transmitidaEnVivo;
}

void PartidaMultijugador::setTransmitidaEnVivo(bool transmitidaEnVivo) {
    this->transmitidaEnVivo = transmitidaEnVivo;
}

vector<Jugador*> PartidaMultijugador::getJugadores() {
    return this->jugadores;
}

float PartidaMultijugador::darTotalHorasParticipantes() {
    return (this->getDuracion() * static_cast<float>(this->getJugadores().size()));
}
