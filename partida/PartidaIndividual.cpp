#include "PartidaIndividual.h"

using namespace std;

PartidaIndividual::PartidaIndividual() {}

PartidaIndividual::PartidaIndividual(const PartidaIndividual &orig) {}

PartidaIndividual::PartidaIndividual(float duracion, bool continuaPartidaAnterior) : Partida(duracion) {
    this->continuaPartidaAnterior = continuaPartidaAnterior;
    videojuego.setTotalHorasJuego(videojuego.getTotalHorasJuego() + this->darTotalHorasParticipantes());
}

PartidaIndividual::~PartidaIndividual() {}

bool PartidaIndividual::getContinuaPartidaAnterior() {
    return this->continuaPartidaAnterior;
}

void PartidaIndividual::setContinuaPartidaAnterior(bool continuaPartidaAnterior) {
    this->continuaPartidaAnterior = continuaPartidaAnterior;
}

float PartidaIndividual::darTotalHorasParticipantes() {
    return this->getDuracion();
}
