//
// Created by Mathi on 10/4/2022.
//

#include "Util.h"

bool Util::verificarNickname(Sistema* sistema, string nickname) {
    if(nickname.empty()) {
        cout<<endl<<"Error: El nickname del jugador no puede ser nulo."<<endl;
        return false;
    }
    for(Jugador* jugador : sistema->obtenerJugadoresTotal()){
        if(jugador->getNickname() == nickname) {
            cout<<endl<<"Error: El jugador ya existe."<<endl;
            return false;
        }
    }
    return true;
}

bool Util::verificarEdad(string edad) {
    for (char const &c : edad) {
        if (std::isdigit(c) == 0){
            cout<<endl<<"Error: La edad debe ser un numero."<<endl;
            return false;
        }
    }
    if(stoi(edad) <= 0) {
        cout<<endl<<"Error: La edad no puede ser negativa."<<endl;
        return false;
    }
    return true;
}

bool Util::verificarNombre(Sistema* sistema, string nombre) {
    if(nombre.empty()) {
        cout<<endl<<"Error: El nombre del videojuego no puede ser nulo."<<endl;
        return false;
    }
    for(Videojuego* videojuego : sistema->obtenerVideojuegosTotal()){
        if(videojuego->getNombre() == nombre) {
            cout<<endl<<"Error: El videojuego ya existe."<<endl;
            return false;
        }
    }
    return true;
}

bool Util::verificarGenero(string genero) {
    for (char const &c : genero) {
        if (std::isdigit(c) == 0){
            cout<<endl<<"Error: Debes ingresar una opcion valida."<<endl;
            return false;
        }
    }
    if(stoi(genero) <= 0 || stoi(genero) > 8) {
        cout<<endl<<"Error: Debes ingresar una opcion valida."<<endl;
        return false;
    }
    return true;
}