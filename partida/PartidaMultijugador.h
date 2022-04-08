#ifndef PA_LABORATORIO0_PARTIDAMULTIJUGADOR_H
#define PA_LABORATORIO0_PARTIDAMULTIJUGADOR_H


#include "Partida.h"

#include "Partida.h"
#include "../datatypes/dtFechaHora.h"
#include "../jugador/Jugador.h"
#include "../videojuego/Videojuego.h"
#include <vector>

using namespace std;

class PartidaMultijugador : public Partida {
private:
    bool transmitidaEnVivo;
public:
    vector<Jugador*> jugadores;
    PartidaMultijugador(dtFechaHora fecha, float duracion, Videojuego videojuego, Jugador jugadorIniciador, bool transmitidaEnVivo, vector<Jugador*> jugadores);

    void setTransmitidaEnVivo(bool transmitidaEnVivo);
    bool getTransmitidaEnVivo();

    float darTotalHorasParticipantes();


};


#endif //PA_LABORATORIO0_PARTIDAMULTIJUGADOR_H
