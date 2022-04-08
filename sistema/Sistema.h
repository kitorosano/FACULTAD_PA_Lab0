//
// Created by Mathi on 7/4/2022.
//

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
        vector<Partida> partidas;

    public:
        Sistema();
        void agregarJugador(string nickname, int edad, string password);
        void agregarVideojuego(string nombre, dtTipoJuego genero);
        Jugador *obtenerJugadores(int &cantJugadores);
        Videojuego *obtenerVideojuegos(int &cantVideojuegos);
        Partida *obtenerPartidas(string videojuego, int &cantPartidas);
        void iniciarPartida(string nickname, string videojuego, Partida *datos);
};


#endif //PA_LABORATORIO0_SISTEMA_H