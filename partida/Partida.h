//
// Created by Mathi on 7/4/2022.
//

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
    Partida(dtFechaHora fecha, float duracion, Videojuego videojuego, Jugador jugadorIniciador);

    dtFechaHora getFecha();
    virtual float darTotalHorasParticipantes();
    Videojuego getVideojuego();
    Jugador getJugadorIniciador();

    void setFecha(dtFechaHora fecha);
    void setDuracion(float duracion);
    void setVideojuego(Videojuego videojuego);
    void setJugadorIniciador(Jugador jugadorIniciador);
};


#endif //PA_LABORATORIO0_PARTIDA_H
