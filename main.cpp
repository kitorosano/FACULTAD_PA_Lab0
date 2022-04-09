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

    int cantJugadores = 0;
    int cantVideojuegos = 0;
    auto *sistema = new Sistema();

    sistema->agregarJugador("Juan", 21, "123456");
    sistema->agregarJugador("Pedro", 24, "123456");
    sistema->agregarJugador("Jose", 18, "123456");
    sistema->agregarJugador("Maria", 19, "123456");
    vector<Jugador *> jugadores = sistema->obtenerJugadores(cantJugadores);

    //TEST VIDEOJUEGO
    sistema->agregarVideojuego("Counter Strike: Global Offensive", TipoJuego::Disparos);
    sistema->agregarVideojuego("Fifa 22", TipoJuego::Deportes);
    sistema->agregarVideojuego("Gran Turismo 5", TipoJuego::Disparos);
    sistema->agregarVideojuego("Mario Kart 8", TipoJuego::Disparos);
    sistema->agregarVideojuego("Super Mario Bros", TipoJuego::Aventura);
    vector<Videojuego *> videojuegos = sistema->obtenerVideojuegos(cantVideojuegos);
    
    // TEST PARTIDAS
    Partida* partidaI = new PartidaIndividual(2.0, true);
    sistema->iniciarPartida("Juan", "Fifa 22",partidaI);
  
    vector<Jugador*> jugadoresPartida = {jugadores[1], jugadores[3]};
    Partida* partidaM = new PartidaMultijugador(2.0, false, jugadoresPartida);
    sistema->iniciarPartida("Juan", "Mario Kart8",partidaM);
  
    cout<<"Jugadores: "<<endl;
    for (Jugador* jugador : jugadores) {
        cout<<"Nickname: "<<jugador->getNickname()<<" | Edad: "<<jugador->getEdad()<<" | Password: "<<jugador->getPassword()<<endl;
    }
    cout<<endl<<"Videojuegos: "<<endl;
    for (Videojuego* videojuego : videojuegos) {
        cout<<"Nombre: "<<videojuego->getNombre()<<" | Total horas de juego: "<<videojuego->getTotalHorasJuego()<<" | Genero: "<<videojuego->getGenero()<<endl;
    }
    cout<<endl;
    cout<<cantJugadores<<endl;
    cout<<cantVideojuegos<<endl;

}

int main() {

  
    testing();
    return 0;
}
