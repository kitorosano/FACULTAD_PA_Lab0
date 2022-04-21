//
// Created by Mathi on 10/4/2022.
//

#ifndef PA_LABORATORIO0_UTIL_H
#define PA_LABORATORIO0_UTIL_H


#include "../sistema/Sistema.h"

class Util {
    public:
        bool verificarNickname(Sistema* sistema, string nickname);
        bool verificarEdad(string edad);
        bool verificarNombre(Sistema* sistema, string nombre);
        bool verificarGenero(string genero);
        bool verificarCantidadJugadores(Sistema* sistema, string cantJugadores);
        bool verificarCantidadVideojuegos(Sistema* sistema, string cantVideojuegos);
        bool verificarCantidadPartidas(Sistema* sistema,string videojuego, string cantVideojuegos);
        bool verificarVideojuego(Sistema* sistema, string videojuego);
        bool isInteger(string a);
        bool isIntegerWM(string a);
        bool verificarDuracion(string duracion); 
        bool verificarOpcion(string tipoPartida);
        bool verificarJugador(Sistema* sistema, string nickname);
};


#endif //PA_LABORATORIO0_UTIL_H
