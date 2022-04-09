#include <iostream>
#include "partida/Partida.h"
#include "jugador/Jugador.h"
#include "videojuego/Videojuego.h"
#include "datatypes/dtFechaHora.h"
#include "sistema/Sistema.h"
#include "partida/Partida.h"
#include "partida/PartidaIndividual.h"
#include "partida/PartidaMultijugador.h"

using namespace std;

void testing(){

    auto *sistema = new Sistema();

    //TEST JUGADORES
    sistema->agregarJugador("Juan", 21, "123456");
    sistema->agregarJugador("Pedro", 24, "123456");
    sistema->agregarJugador("Jose", 18, "123456");
    sistema->agregarJugador("Maria", 19, "123456");

    //TEST VIDEOJUEGO
    sistema->agregarVideojuego("Counter Strike: Global Offensive", TipoJuego::Disparos);
    sistema->agregarVideojuego("Fifa 22", TipoJuego::Deportes);
    sistema->agregarVideojuego("Gran Turismo 5", TipoJuego::Disparos);
    sistema->agregarVideojuego("Mario Kart 8", TipoJuego::Disparos);
    sistema->agregarVideojuego("Super Mario Bros", TipoJuego::Aventura);
  
    // TEST PARTIDAS
    int cantJugadores = 4;
    vector<Jugador *> jugadores = sistema->obtenerJugadores(cantJugadores);
  
  
    Partida* partidaI = new PartidaIndividual(2.0, true);
    sistema->iniciarPartida("Juan", "Fifa 22",partidaI);
  
    vector<Jugador*> jugadoresPartida = {jugadores[1], jugadores[3]};
    Partida* partidaM = new PartidaMultijugador(2.0, false, jugadoresPartida);
    sistema->iniciarPartida("Juan", "Mario Kart 8",partidaM);
  
    //TEST CONSOLA
    int cantVideojuegos = 4;
    vector<Videojuego *> videojuegos = sistema->obtenerVideojuegos(cantVideojuegos);
    
    cout<<"Jugadores: "<<endl;
    for (Jugador* jugador : jugadores) {
        cout<<jugador->toString()<<endl;
    }
    
    cout<<endl<<"Videojuegos: "<<endl;
    for (Videojuego* videojuego : videojuegos) {
        cout<<endl<<"="<<videojuego->toString()<<endl;
  
        cout<<"Partidas: "<<endl;
        int cantPartidas = videojuego->getCantidadPartidas();
        for(auto partida : sistema->obtenerPartidas(videojuego->getNombre(), cantPartidas))
              cout<<partida->toString()<<endl;
    }

}

int main() {

  //TOFIX  MOSTRAR JUGADORES DE PARTIDAS MULTIJUGADOR
  //TOFIX: no se esta pudiendo trabajar con el vector de jugadores de partida multijugador
  //TODO: agregar menu al main
  //TOFIX: NOSE PORQUE FECHA TIRA 'HOLA'
  
    testing();
    return 0;
}
