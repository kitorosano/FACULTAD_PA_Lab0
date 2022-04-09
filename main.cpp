#include <iostream>
#include "partida/Partida.h"
#include "jugador/Jugador.h"
#include "videojuego/Videojuego.h"
#include "datatypes/dtFechaHora.h"
#include "sistema/Sistema.h"
#include "partida/Partida.h"
#include "partida/PartidaIndividual.h"

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

    sistema->agregarVideojuego("Counter Strike: Global Offensive", TipoJuego_str[TipoJuego::Disparos]);
    sistema->agregarVideojuego("Fifa 22", TipoJuego_str[TipoJuego::Deportes]);
    sistema->agregarVideojuego("Gran Turismo 5", TipoJuego_str[TipoJuego::Disparos]);
    sistema->agregarVideojuego("Mario Kart 8", TipoJuego_str[TipoJuego::Disparos]);
    sistema->agregarVideojuego("Super Mario Bros", TipoJuego_str[TipoJuego::Aventura]);
    vector<Videojuego *> videojuegos = sistema->obtenerVideojuegos(cantVideojuegos);

    auto fecha = new dtFechaHora(1, 1, 2018, 1, 1, 1);
    float duracion = 2.0;

    Videojuego *v1 = videojuegos[0];
    Jugador *j1 = jugadores[0];

    //PartidaIndividual partida = new PartidaIndividual(fecha, duracion, j1, v1, true);


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
