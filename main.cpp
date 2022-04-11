#include <iostream>
#include "partida/Partida.h"
#include "jugador/Jugador.h"
#include "videojuego/Videojuego.h"
#include "sistema/Sistema.h"
#include "partida/PartidaIndividual.h"
#include "partida/PartidaMultijugador.h"
#include "view/View.h"

using namespace std;

void testing(){

    auto *sistema = new Sistema();

    //TEST JUGADORES
    sistema->agregarJugador("Juan", 21, "123456");
    sistema->agregarJugador("Pedro", 24, "123456");
    sistema->agregarJugador("Jose", 18, "123456");
    sistema->agregarJugador("Maria", 19, "123456");

    //TEST VIDEOJUEGO
    sistema->agregarVideojuego("Fifa 22", TipoJuego::Deportes);
    sistema->agregarVideojuego("Mario Kart 8", TipoJuego::Disparos);
    sistema->agregarVideojuego("Gran Turismo 5", TipoJuego::Disparos);
    sistema->agregarVideojuego("Counter Strike: Global Offensive", TipoJuego::Disparos);
    sistema->agregarVideojuego("Super Mario Bros", TipoJuego::Aventura);
    sistema->agregarVideojuego("Super Mario Bros 2", TipoJuego::Aventura);
    sistema->agregarVideojuego("Super Mario Bros 3", TipoJuego::Aventura);
    sistema->agregarVideojuego("Super Mario Bros 4", TipoJuego::Aventura);
  
    // TEST PARTIDAS
    int cantJugadores = 4;
    vector<Jugador*> jugadores = sistema->obtenerJugadores(cantJugadores);
  
  
    Partida* partidaI = new PartidaIndividual(2.0, true);
    sistema->iniciarPartida("Juan", "Fifa 22",partidaI);

    Partida* partidaI2 = new PartidaIndividual(2.0, false);
    sistema->iniciarPartida("Juan", "Mario Kart 8",partidaI2);
  
    vector<Jugador*> jugadoresPartida = {jugadores[1], jugadores[3]};
    Partida* partidaM = new PartidaMultijugador(2.0, false, jugadoresPartida);
    sistema->iniciarPartida("Pedro", "Mario Kart 8",partidaM);
  
    //TEST CONSOLA
    int cantVideojuegos = 4;
    vector<Videojuego *> videojuegos = sistema->obtenerVideojuegos(cantVideojuegos);
    
    cout<<"Jugadores: "<<endl;
    for (Jugador* jugador : jugadores) {
        cout<<jugador->toString()<<endl;
    }
    
    cout<<endl<<"Videojuegos: "<<endl;
    cout<<"______________________________________________________"<<endl;
    for (Videojuego* videojuego : videojuegos) {
        cout<<videojuego->toString();
        int cantPartidas = videojuego->getCantidadPartidas();
        if(cantPartidas > 0){
            cout<<"\t"<<"Partidas: "<<endl;
            cout<<"\t\t--------------------------------------"<<endl;
            for(Partida* partida : sistema->obtenerPartidas(videojuego->getNombre(), cantPartidas)) {
                cout<<partida->toString();
                cout<<"\t\t--------------------------------------"<<endl;
            }
        } else
            cout<<"\t"<<"Partidas: Este juego aun no tiene partidas."<<endl;
        cout<<"______________________________________________________"<<endl;
    }

}

int main() {
    int opcion;
    Sistema* sistema = new Sistema();
    View* view = new View();
    do {
        view->menu();
        cin>>opcion;
        switch(opcion) {
            case 1:
                view->agregarJugadorView(sistema);
                break;
        }

    } while(opcion != 0);
    return 0;
}
