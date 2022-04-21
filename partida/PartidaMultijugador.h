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
        vector<Jugador*> jugadores;
        
    public:
        PartidaMultijugador(float duracion, bool transmitidaEnVivo, vector<Jugador *> jugadores);

        void setTransmitidaEnVivo(bool transmitidaEnVivo);

        bool getTransmitidaEnVivo();

        vector<Jugador *> getJugadores();

        float darTotalHorasParticipantes() override;

        string toString() override;
};


#endif //PA_LABORATORIO0_PARTIDAMULTIJUGADOR_H
