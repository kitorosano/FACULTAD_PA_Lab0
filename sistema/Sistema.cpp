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
  vector<Jugador*> vj;
  if(cantJugadores<0 && cantJugadores > jugadores.size())
    throw invalid_argument("Error: La cantidad especificada de videojuegos no se puede obtener.");
  
  for(int i=0;i< cantJugadores;i++)
    vj.push_back(jugadores[i]);
  
  return vj;
    //cantJugadores = this->jugadores.size();
    //return this->jugadores;
}

vector<Videojuego*> Sistema::obtenerVideojuegos(int &cantVideojuegos) {
  vector<Videojuego*> vv;
  if(cantVideojuegos<0 && cantVideojuegos > videojuegos.size())
    throw invalid_argument("Error: La cantidad especificada de videojuegos no se puede obtener.");
  
  for(int i=0;i< cantVideojuegos;i++)
    vv.push_back(videojuegos[i]);
  
  return vv;
    //cantVideojuegos = this->videojuegos.size();
    //return this->videojuegos;
}

vector<Partida*> Sistema::obtenerPartidas(string videojuego, int &cantPartidas) {
  vector<Partida*> vp;
  if(cantPartidas<0 && cantPartidas > partidas.size())
    throw invalid_argument("Error: La cantidad especificada de videojuegos no se puede obtener.");
  
  
  for(int i=0;i< cantPartidas;i++){
    if(partidas[i]->getVideojuego().getNombre() == videojuego)
      vp.push_back(partidas[i]);
  }
  
  return vp;
    //cantPartidas = this->partidas.size();
    //return this->partidas;
}

void Sistema::iniciarPartida(string nickname, string videojuego, Partida *datos) { //datos = Partida {duracion, continuacion/transmision y jugadores}
  //VERIFICAR DATOS
    if (nickname.empty() || videojuego.empty()) {
        throw invalid_argument("Error: La partida no puede ser creada.");
    }
    
    bool existeJugador = false;
    for (Jugador *jug: jugadores)
        if (jug->getNickname() == nickname) {
          datos->setJugadorIniciador(*jug); //seteo jugador iniciador
          existeJugador = true;
        }
    if (!existeJugador)
        throw invalid_argument("Error: El jugador no existe.");
    
    bool existeVideoJuego = false;
      for (Videojuego *vid: videojuegos)
          if (vid->getNombre() == videojuego) {
            datos->setVideojuego(*vid); //setedo videojuego
            existeVideoJuego = true;
          }
      if (!existeVideoJuego)
          throw invalid_argument("Error: El videojuego no existe.");
      
    // SET TOTAL HORAS PARTICIPANTES
    
    
      
    dtFechaHora* fechaHora = new dtFechaHora(2022, 3, 31, 23, 59, 59); //TODO: CREAR FECHA ACTUAL
    datos->setFecha(*fechaHora); //fecha de inicio
    
    this->partidas.push_back(datos); //REGISTRAR PARTIDA
}