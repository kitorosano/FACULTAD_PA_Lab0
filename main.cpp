#include <iostream>
#include "sistema/Sistema.h"
using namespace std;

int main() {
    int cantJugadores = 0;
    auto* sistema = new Sistema();

    sistema->agregarJugador("Juan", 21, "123456");
    sistema->agregarJugador("Pedro", 24, "123456");
    sistema->agregarJugador("José", 18, "123456");
    sistema->agregarJugador("María", 19, "123456");
    vector<Jugador*> jugadores = sistema->obtenerJugadores(cantJugadores);

    for (Jugador* jugador : jugadores) {
        cout<<jugador->getNickname()<<endl;
    }

    system("pause");

    //TODO: REVISAR ERROR FATAL AL EJECUTAR EL SISTEMA, QUIZAS HAY QUE CREAR EL PROYECTO NUEVAMENTE.

    return 0;
}
