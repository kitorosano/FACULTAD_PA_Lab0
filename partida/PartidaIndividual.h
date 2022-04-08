//
// Created by Mathi on 7/4/2022.
//

#ifndef PA_LABORATORIO0_PARTIDAINDIVIDUAL_H
#define PA_LABORATORIO0_PARTIDAINDIVIDUAL_H


#include "Partida.h"
#include "../datatypes/dtFechaHora.h"
#include "../jugador/Jugador.h"
#include "../videojuego/Videojuego.h"

using namespace std;

class PartidaIndividual : public Partida {
private:
    bool continuaPartidaAnterior;
public:
    PartidaIndividual(dtFechaHora fecha, float duracion, Videojuego videojuego, Jugador jugadorIniciador, bool continuaPartidaAnterior);

    bool getContinuaPartidaAnterior();
    void setContinuaPartidaAnterior(bool continuaPartidaAnterior);

    float darTotalHorasParticipantes();


};


#endif //PA_LABORATORIO0_PARTIDAINDIVIDUAL_H
