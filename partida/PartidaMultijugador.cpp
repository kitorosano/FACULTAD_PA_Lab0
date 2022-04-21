#include <sstream>
#include "PartidaMultijugador.h"

using namespace std;

PartidaMultijugador::PartidaMultijugador(float duracion, bool transmitidaEnVivo, vector<Jugador*> jugadores):Partida(duracion) {
    this->transmitidaEnVivo = transmitidaEnVivo;
    this->jugadores = jugadores;
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
    ss<<"\t\tTipo de partida: Multijugador "<<endl;
    ss<<Partida::toString();
    ss<<"\t\t"<<"Transmitida en vivo: "<<(getTransmitidaEnVivo() ? "Si" : "No")<<endl;
    ss<<"\t\t"<<"Jugadores: "<<endl;
    for (Jugador* jugador : getJugadores()) {
        ss<<"\t\t\t - "<<jugador->getNickname()<<endl;
    }
    return ss.str();
}