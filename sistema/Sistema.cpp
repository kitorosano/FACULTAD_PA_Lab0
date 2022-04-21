//
// Created by Mathi on 7/4/2022.

#include "Sistema.h"
#include "../partida/PartidaIndividual.h"
#include "../partida/PartidaMultijugador.h"

using namespace std;//

Sistema::Sistema(){}

void Sistema::agregarJugador(string nickname, int edad, string password) {
    if(nickname.empty() || edad <= 0)
        throw invalid_argument("Error: El jugador no puede ser creado.");

    for(Jugador* jug : jugadores) {
        if(jug->getNickname() == nickname)
            throw invalid_argument("Error: El jugador ya existe.");
    }

    Jugador* jugador = new Jugador(nickname, edad, (password.empty() || password == "") ? "123456" : password);
    this->jugadores.push_back(jugador);
}

void Sistema::agregarVideojuego(string nombre, TipoJuego genero) {
    if(nombre.empty())
        throw invalid_argument("Error: El videojuego no puede ser creado.");
    
    for(Videojuego* vid : videojuegos) {
        if(vid->getNombre() == nombre)
            throw invalid_argument("Error: El videojuego ya existe.");
    }
    
    Videojuego* videojuego = new Videojuego(nombre, genero);
    this->videojuegos.push_back(videojuego);
}

vector<Jugador*> Sistema::obtenerJugadores(int &cantJugadores) {
    vector<Jugador*> vectorJugadores;

    if(cantJugadores < 0 || cantJugadores > jugadores.size())
        throw invalid_argument("Error: La cantidad especificada de videojuegos no se puede obtener.");

    vectorJugadores = jugadores;
    vectorJugadores.resize(cantJugadores);
    return vectorJugadores;
}

vector<Videojuego*> Sistema::obtenerVideojuegos(int &cantVideojuegos) {
    vector<Videojuego*> vectorVideojuegos;

    if(cantVideojuegos < 0 || cantVideojuegos > videojuegos.size())
        throw invalid_argument("Error: La cantidad especificada de videojuegos no se puede obtener.");
  
    for(Videojuego* videojuego : videojuegos) { //VIDEO JUEGO A OBTENER
        auto horasASumar = 0; //contador para la suma
        for (Partida* partida : videojuego->getPartidas()) //RECORRO LAS PARTIDAS DEL JUEGO PARA SUMAR LAS HORAS
            horasASumar += partida->darTotalHorasParticipantes();// sumo las horas de las partidas
        videojuego->setTotalHorasJuego(horasASumar);  //seteo la variable del videojuego (total horas)
        vectorVideojuegos.push_back(videojuego);
    }
    vectorVideojuegos.resize(cantVideojuegos); //limito el vector a la cantidad especificada
    return vectorVideojuegos;
}

vector<Partida*> Sistema::obtenerPartidas(string videojuego, int &cantPartidas) {
    vector<Partida*> vp; //vector auxiliar
  
    if(videojuego.empty())
        throw invalid_argument("Error: El videojuego no existe.");

    for(auto videojuegoAux : videojuegos) { //BUSCAR EL VIDEOJUEGO
        if(videojuegoAux->getNombre() == videojuego) { //OBTENER LAS PARTIDAS DEL VIDEOJUEGO CUYO NOMBRE SEA IGUAL
      
            if(cantPartidas<0 && cantPartidas > videojuegoAux->getPartidas().size()) //VERIFICO EL PARAMETRO cantPartidas
                throw invalid_argument("Error: La cantidad especificada de videojuegos no se puede obtener.");
     
            vp = videojuegoAux->getPartidas();//obtengo las partidas del videojuego
        }
    }
  
    vp.resize(cantPartidas); //limito el vector a la cantidad especificada
    return vp;
}

void Sistema::iniciarPartida(string nickname, string videojuego, Partida *datos) { //datos = Partida {duracion, continuacion/transmision y jugadores}
    //VERIFICAR DATOS
    if (nickname.empty() || videojuego.empty())
        throw invalid_argument("Error: La partida no puede ser creada.");

    bool existeJugador = false;

    for (Jugador *jug: jugadores) {
        if (jug->getNickname() == nickname) {
            datos->setJugadorIniciador(*jug); //seteo jugador iniciador
            existeJugador = true;
        }
    }

    if (!existeJugador)
        throw invalid_argument("Error: El jugador no existe.");

    bool existeVideoJuego = false;
    for (Videojuego *vid: videojuegos) {
        if (vid->getNombre() == videojuego) {
            dtFechaHora *fechaHora = new dtFechaHora();
            datos->setFecha(*fechaHora);
            vid->guardarPartida(datos);
            existeVideoJuego = true;
        }
    }

    if (!existeVideoJuego)
        throw invalid_argument("Error: El videojuego no existe.");

}

vector<Jugador*> Sistema::getJugadores() {
    return this->jugadores;
}

vector<Videojuego*> Sistema::getVideojuegos() {
    return this->videojuegos;
}

Partida* Sistema::crearPartidaInd(float duracion, bool continuaPartidaAnterior){
    Partida* partida = new PartidaIndividual(duracion, continuaPartidaAnterior);
    return partida;
}

Partida* Sistema::crearPartidaMul(float duracion, bool transmitidaEnVivo, vector<Jugador*> jugadores){
    Partida* partida = new PartidaMultijugador(duracion,transmitidaEnVivo,jugadores);
    return partida;
}