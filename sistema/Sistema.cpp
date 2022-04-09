//
// Created by Mathi on 7/4/2022.

#include "Sistema.h"
using namespace std;//

Sistema::Sistema(){}

void Sistema::agregarJugador(string nickname, int edad, string password) {
    if(nickname.empty() || edad <= 0 || password.empty()){
        throw invalid_argument("Error: El jugador no puede ser creado.");
    }
    for(Jugador* jug : jugadores) {
        if(jug->getNickname() == nickname) {
            throw invalid_argument("Error: El jugador ya existe.");
        }
    }
    Jugador* jugador = new Jugador(nickname, edad, password);
    this->jugadores.push_back(jugador);
}

void Sistema::agregarVideojuego(string nombre, string genero) {
    if(nombre.empty()){
        throw invalid_argument("Error: El videojuego no puede ser creado.");
    }
    for(Videojuego* vid : videojuegos) {
        if(vid->getNombre() == nombre) {
            throw invalid_argument("Error: El videojuego ya existe.");
        }
    }
    Videojuego* videojuego = new Videojuego(nombre, genero);
    this->videojuegos.push_back(videojuego);
}

vector<Jugador*> Sistema::obtenerJugadores(int &cantJugadores) {
    cantJugadores = this->jugadores.size();
    return this->jugadores;
}

vector<Videojuego*> Sistema::obtenerVideojuegos(int &cantVideojuegos) {
    cantVideojuegos = this->videojuegos.size();
    return this->videojuegos;
}

vector<Partida*> Sistema::obtenerPartidas(string Videojuego, int &cantPartidas) {
    cantPartidas = this->partidas.size();
    return this->partidas;
}

void Sistema::iniciarPartida(string nickname, string videojuego, Partida *datos) {
    if (nickname.empty() || videojuego.empty()) {
        throw invalid_argument("Error: La partida no puede ser creada.");
    }
    for (Jugador *jug: jugadores) {
        if (jug->getNickname() != nickname) {
            throw invalid_argument("Error: El jugador no existe.");
        }
    }
    for (Videojuego *vid: videojuegos) {
        if (vid->getNombre() != videojuego) {
            throw invalid_argument("Error: El videojuego no existe.");
        }
    }
    this->partidas.push_back(datos);
}