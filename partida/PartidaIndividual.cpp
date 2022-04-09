#include <sstream>
#include "PartidaIndividual.h"

using namespace std;

PartidaIndividual::PartidaIndividual() {}

PartidaIndividual::PartidaIndividual(const PartidaIndividual &orig) {}

PartidaIndividual::PartidaIndividual(float duracion, bool continuaPartidaAnterior) : Partida(duracion) {
    this->continuaPartidaAnterior = continuaPartidaAnterior;
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

string PartidaIndividual::toString() {
    stringstream ss;
    ss<<Partida::toString();
    ss<<"\t\tContinuar partida: "<<(getContinuaPartidaAnterior() ? "Si" : "No")<<endl;
    return ss.str();
}