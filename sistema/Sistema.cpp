//
// Created by Mathi on 7/4/2022.

#include "Sistema.h"
#include "../partida/PartidaIndividual.h"

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
  
  vj = jugadores;
  vj.resize(cantJugadores);
  return vj;
}

vector<Videojuego*> Sistema::obtenerVideojuegos(int &cantVideojuegos) {
  vector<Videojuego*> vv;
  if(cantVideojuegos<0 && cantVideojuegos > videojuegos.size())
    throw invalid_argument("Error: La cantidad especificada de videojuegos no se puede obtener.");
  
  for(auto videojuego : videojuegos) { //VIDEO JUEGO A OBTENER
    auto horasASumar = 0; //contador para la suma
    for (auto partida : videojuego->getPartidas()) //RECORRO LAS PARTIDAS DEL JUEGO PARA SUMAR LAS HORAS
      horasASumar += partida->darTotalHorasParticipantes();// sumo las horas de las partidas
    videojuego->setTotalHorasJuego(horasASumar);  //seteo la variable del videojuego (total horas)
    
    vv.push_back(videojuego);
  }
  
  vv.resize(cantVideojuegos); //limito el vector a la cantidad especificada
  return vv;
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
      
          // SET TOTAL HORAS PARTICIPANTES
          dtFechaHora* fechaHora = new dtFechaHora(2022, 3, 31, 23, 59, 59); //TODO: CREAR FECHA ACTUAL
      datos->setFecha(*fechaHora); //fecha de inicio
  
  
      vid->guardarPartida(datos); // REGISTRAR PARTIDA
      existeVideoJuego = true;
    }
  if (!existeVideoJuego)
    throw invalid_argument("Error: El videojuego no existe.");
}