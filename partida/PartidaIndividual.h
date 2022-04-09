#ifndef PA_LABORATORIO0_PARTIDAINDIVIDUAL_H
#define PA_LABORATORIO0_PARTIDAINDIVIDUAL_H

#include <iostream>
#include "Partida.h"
#include "../datatypes/dtFechaHora.h"
#include "../jugador/Jugador.h"
#include "../videojuego/Videojuego.h"

using namespace std;

class PartidaIndividual : public Partida {

private:
    bool continuaPartidaAnterior;

public:
    PartidaIndividual();
    PartidaIndividual(const PartidaIndividual& orig);
    PartidaIndividual(float duracion, bool continuaPartidaAnterior);
    ~PartidaIndividual();

    bool getContinuaPartidaAnterior();
    void setContinuaPartidaAnterior(bool continuaPartidaAnterior);

    float darTotalHorasParticipantes();

};
#endif //PA_LABORATORIO0_PARTIDAINDIVIDUAL_H
