//
// Created by Mathi on 10/4/2022.
//

#include "Util.h"
#include <regex>

bool Util::verificarNickname(Sistema* sistema, string nickname) {
    if(nickname.empty()) {
        cout<<endl<<"Error: El nickname del jugador no puede ser nulo."<<endl;
        system("pause");
        return false;
    }
    for(Jugador* jugador : sistema->getJugadores()){
        if(jugador->getNickname() == nickname) {
            cout<<endl<<"Error: El jugador ya existe."<<endl;
            system("pause");
            return false;
        }
    }
    return true;
}

bool Util::verificarEdad(string edad) {
    if(!this->isInteger(edad)) {
        return false;
    }
    if(stoi(edad) == 0) {
        cout<<endl<<"Error: La edad del jugador no puede ser 0."<<endl;
        system("pause");
        return false;
    }
    return true;
}

bool Util::verificarNombre(Sistema* sistema, string nombre) {
    if(nombre.empty()) {
        cout<<endl<<"Error: El nombre del videojuego no puede ser nulo."<<endl;
        system("pause");
        return false;
    }
    for(Videojuego* videojuego : sistema->getVideojuegos()){
        if(videojuego->getNombre() == nombre) {
            cout<<endl<<"Error: El videojuego ya existe."<<endl;
            system("pause");
            return false;
        }
    }
    return true;
}

bool Util::verificarGenero(string genero) {
    if(!this->isInteger(genero)) {
        return false;
    }
    if(stoi(genero) <= 0 || stoi(genero) > 8) {
        cout<<endl<<"Error: Debes ingresar una opcion valida."<<endl;
        system("pause");
        return false;
    }
    return true;
}

bool Util::verificarCantidadJugadores(Sistema* sistema, string cantJugadores){
    if(!this->isInteger(cantJugadores)){
        return false;
    }
    if(stoi(cantJugadores) == 0){
        cout<<endl<<"Error: La cantidad de jugadores no puede ser 0."<<endl;
        system("pause");
        return false;
    }
    if(stoi(cantJugadores) > sistema->getJugadores().size()) {
        cout<<endl<<"Error: El valor ingresado es mayor al maximo de jugadores registrados."<<endl;
        system("pause");
        return false;
    }
    return true;
}

bool Util::verificarCantidadVideojuegos(Sistema* sistema, string cantVideojuegos){
    if(!this->isInteger(cantVideojuegos)) {
        return false;
    }
    if(stoi(cantVideojuegos) == 0) {
        cout<<endl<<"Error: La cantidad de videojuegos no puede ser 0."<<endl;
        system("pause");
        return false;
    }
    if(stoi(cantVideojuegos) > sistema->getVideojuegos().size()) {
        cout<<endl<<"Error: El valor ingresado es mayor al maximo de videojuegos registrados."<<endl;
        system("pause");
        return false;
    }
    return true;
}

bool Util::verificarCantidadPartidas(Sistema* sistema, string videojuego, string cantPartidas){
    if(!this->isInteger(cantPartidas)) {
        return false;
    }
    if(stoi(cantPartidas) == 0) {
        cout<<endl<<"Error: La cantidad de partidas no puede ser 0."<<endl;
        system("pause");
        return false;
    }
    for(Videojuego* videojuegoAux : sistema->getVideojuegos()) { //BUSCAR EL VIDEOJUEGO
        if(videojuegoAux->getNombre() == videojuego) { //OBTENER LAS PARTIDAS DEL VIDEOJUEGO CUYO NOMBRE SEA IGUAL
            if(stoi(cantPartidas) >  videojuegoAux->getPartidas().size()) {
                cout<<endl<<"Error: El valor ingresado es mayor al maximo de partidas registradas."<<endl;
                system("pause");
                return false;
            }
            return true;
        }
    }
    return false;
}

bool Util::verificarVideojuego(Sistema* sistema, string videojuego) {
    for(Videojuego* videojuegoAux : sistema->getVideojuegos()) {
        if(videojuegoAux->getNombre() == videojuego) {
            return true;
        }
    }
    cout<<endl<<"Error: El videojuego no existe."<<endl;
    system("pause");
    return false;
}

bool Util::isInteger(string a) {
    for(char const &c : a) {
        if (isdigit(c) == 0){
            cout<<endl<<"Error: Debe ingresar un numero entero positivo."<<endl;
            system("pause");
            return false;
        }
    }
    return true;
}

bool Util::isIntegerWM(string a) {
    for(char const &c : a) {
        if (isdigit(c) == 0){
            return false;
        }
    }
    return true;
}

bool Util::verificarDuracion(string duracion) {
    if(!this->isIntegerWM(duracion)) {
        int longitud = duracion.size();
        // Quitar espacios, saltos de línea, etcétera
        while (longitud > 0 && isspace(duracion[longitud - 1]))
            longitud--;
        if (longitud <= 0){
            cout<<endl<<"Error: Debe ingresar un numero correcto."<<endl;
            system("pause");
            return false;
        }
        int i;
        int haEncontradoElPunto = 0;
        for (i = 0; i < longitud; ++i) {
            // En caso de que sea un guión, y que no esté al inicio, no es válido
            if (duracion[i] == '-' && i > 0) {
                cout<<endl<<"Error: Debe ingresar un numero correcto."<<endl;
                system("pause");
                return false;
            }
            // El punto solo puede aparecer una vez
            if (duracion[i] == '.') {
                // Si ya lo ha encontrado antes, entonces no es válido
                if (haEncontradoElPunto) {
                    cout<<endl<<"Error: Debe ingresar un numero correcto."<<endl;
                    system("pause");
                    return false;
                } else {

                    haEncontradoElPunto = 1;
                }
            }
            // Si no es dígito, tampoco es válido
            if (!isdigit(duracion[i]) && duracion[i] != '-' && duracion[i] != '.') {
                cout<<endl<<"Error: Debe ingresar un numero correcto."<<endl;
                system("pause");
                return false;
            }
        }
    }
    return true;
}

bool Util::verificarOpcion(string opcion) {
    if(!this->isInteger(opcion)) {
        return false;
    }
    if(stoi(opcion) < 1 || stoi(opcion) > 2) {
        cout<<endl<<"Error: Debes ingresar una opcion valida."<<endl;
        system("pause");
        return false;
    }
    return true;
}

bool Util::verificarJugador(Sistema *sistema, string nickname) {
    if(nickname.empty()) {
        cout<<endl<<"Error: El nickname del jugador no puede ser nulo."<<endl;
        system("pause");
        return false;
    }
    for(Jugador* jugador : sistema->getJugadores()){
        if(jugador->getNickname() == nickname) {
            return true; // significa que este jugador existe en el vector de jugadores
        }
    }
    cout<<endl<<"Error: El jugador no existe."<<endl;
    system("pause");
    return false;
}