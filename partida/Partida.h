#ifndef PA_LABORATORIO0_PARTIDA_H
#define PA_LABORATORIO0_PARTIDA_H

#include "../jugador/Jugador.h"
#include "../videojuego/Videojuego.h"
#include "../datatypes/dtFechaHora.h"

using namespace std;

class Partida {

    private:
        dtFechaHora fecha;
        float duracion;
        Videojuego videojuego;
        Jugador jugadorIniciador;
        
    public:
        Partida();
        Partida(float duracion);

        dtFechaHora getFecha();
        float getDuracion();
        Videojuego getVideojuego();
        Jugador getJugadorIniciador();;
        virtual float darTotalHorasParticipantes();

        void setFecha(dtFechaHora fecha);
        void setDuracion(float duracion);
        void setVideojuego(Videojuego videojuego);
        void setJugadorIniciador(Jugador jugadorIniciador);

};


#endif //PA_LABORATORIO0_PARTIDA_H
