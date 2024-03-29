#ifndef PA_LABORATORIO0_SISTEMA_H
#define PA_LABORATORIO0_SISTEMA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "../partida/Partida.h"
#include "../jugador/Jugador.h"
#include "../videojuego/Videojuego.h"
#include "../datatypes/dtFechaHora.h"

using namespace std;


class Sistema {

    private:
        vector<Jugador*> jugadores;
        vector<Videojuego*> videojuegos;
        
    public:
        Sistema();
        void agregarJugador(string nickname, int edad, string password);
        void agregarVideojuego(string nombre, TipoJuego genero);
        vector<Jugador*> obtenerJugadores(int &cantJugadores);
        vector<Videojuego*> obtenerVideojuegos(int &cantVideojuegos);
        vector<Partida*> obtenerPartidas(string videojuego, int &cantPartidas);
        void iniciarPartida(string nickname, string videojuego, Partida *datos);
        vector<Jugador*> getJugadores();
        vector<Videojuego*> getVideojuegos();
        Partida* crearPartidaInd(float duracion, bool continuaPartidaAnterior);
        Partida* crearPartidaMul(float duracion, bool transmitidaEnVivo, vector<Jugador*> jugadores);

};


#endif //PA_LABORATORIO0_SISTEMA_H
