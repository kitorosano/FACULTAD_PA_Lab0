//
// Created by Mathi on 10/4/2022.
//

#include "Util.h"

bool Util::verificarNickname(Sistema* sistema, string nickname) {
    if(nickname.empty()) {
        cout<<endl<<"Error: El nickname del jugador no puede ser nulo."<<endl;
        return false;
    }
    for(Jugador* jugador : sistema->getJugadores()){
        if(jugador->getNickname() == nickname) {
            cout<<endl<<"Error: El jugador ya existe."<<endl;
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
        return false;
    }
    return true;
}

bool Util::verificarNombre(Sistema* sistema, string nombre) {
    if(nombre.empty()) {
        cout<<endl<<"Error: El nombre del videojuego no puede ser nulo."<<endl;
        return false;
    }
    for(Videojuego* videojuego : sistema->getVideojuegos()){
        if(videojuego->getNombre() == nombre) {
            cout<<endl<<"Error: El videojuego ya existe."<<endl;
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
        return false;
    }
    if(stoi(cantJugadores) > sistema->getJugadores().size()) {
        cout<<endl<<"Error: El valor ingresado es mayor al maximo de jugadores registrados."<<endl;
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
        return false;
    }
    if(stoi(cantVideojuegos) > sistema->getVideojuegos().size()) {
        cout<<endl<<"Error: El valor ingresado es mayor al maximo de videojuegos registrados."<<endl;
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
        return false;
    }
    for(Videojuego* videojuegoAux : sistema->getVideojuegos()) { //BUSCAR EL VIDEOJUEGO
        if(videojuegoAux->getNombre() == videojuego) { //OBTENER LAS PARTIDAS DEL VIDEOJUEGO CUYO NOMBRE SEA IGUAL
            if(stoi(cantPartidas) >  videojuegoAux->getPartidas().size()) {
                cout<<endl<<"Error: El valor ingresado es mayor al maximo de partidas registradas."<<endl;
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
    return false;
}

bool Util::isInteger(string a) {
    for(char const &c : a) {
        if (isdigit(c) == 0){
            cout<<endl<<"Error: Debe ingresar un numero entero positivo."<<endl;
            return false;
        }
    }
    return true;
}