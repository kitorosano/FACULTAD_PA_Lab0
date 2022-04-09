#ifndef PA_LABORATORIO0_PARTIDA_H
#define PA_LABORATORIO0_PARTIDA_H

#include "../jugador/Jugador.h"
#include "../datatypes/dtFechaHora.h"

using namespace std;

class Partida {

    private:
        dtFechaHora fecha;
        float duracion;
        Jugador jugadorIniciador;
        
    public:
        Partida();
        Partida(float duracion);

        dtFechaHora getFecha();
        float getDuracion();
        Jugador getJugadorIniciador();;
        virtual float darTotalHorasParticipantes();

        void setFecha(dtFechaHora fecha);
        void setDuracion(float duracion);
        void setJugadorIniciador(Jugador jugadorIniciador);
        
        virtual string toString();

};


#endif //PA_LABORATORIO0_PARTIDA_H
