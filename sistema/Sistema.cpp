//
// Created by Mathi on 7/4/2022.

#include "Sistema.h"
using namespace std;//

Sistema::Sistema(){}

void Sistema::agregarJugador(string nickname, int edad, string password) {
    Jugador* jugador = new Jugador(nickname, edad, password);
    if(nickname.empty() || edad <= 0 || password.empty()){
        throw invalid_argument("Error: El jugador no puede ser creado.");
    }
    this->jugadores.push_back(jugador);
}

void Sistema::agregarVideojuego(string nombre, TipoJuego genero) {
    Videojuego* videojuego = new Videojuego(nombre, genero);
    if(nombre.empty()){
        throw invalid_argument("Error: El videojuego no puede ser creado.");
    }
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