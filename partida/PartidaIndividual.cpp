#include "PartidaIndividual.h"

using namespace std;

PartidaIndividual::PartidaIndividual(dtFechaHora fecha, float duracion, Videojuego videojuego, Jugador jugadorIniciador, bool continuaPartidaAnterior):Partida(fecha, duracion, videojuego, jugadorIniciador) {
    this->continuaPartidaAnterior = continuaPartidaAnterior;
}

bool PartidaIndividual::getContinuaPartidaAnterior() {
    return this->continuaPartidaAnterior;
}

void PartidaIndividual::setContinuaPartidaAnterior(bool continuaPartidaAnterior) {
    this->continuaPartidaAnterior = continuaPartidaAnterior;
}

float PartidaIndividual::darTotalHorasParticipantes() {
    //TODO
}
