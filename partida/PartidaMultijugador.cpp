#include <sstream>
#include "PartidaMultijugador.h"

using namespace std;

PartidaMultijugador::PartidaMultijugador(float duracion, bool transmitidaEnVivo, vector<Jugador*> jugadores):Partida(duracion) {
    this->transmitidaEnVivo = transmitidaEnVivo;
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

string PartidaMultijugador::toString() {
    stringstream ss;
    ss << Partida::toString();
    ss << "Transmitida en vivo: " << (getTransmitidaEnVivo() ? "Si" : "No") << endl;
    ss << "Jugadores: " << endl;
    for (auto jugador : getJugadores()) {
        ss << jugador->toString() << endl;
    }
    return ss.str();
}