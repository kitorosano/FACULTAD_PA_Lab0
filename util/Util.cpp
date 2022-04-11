//
// Created by Mathi on 10/4/2022.
//

#include "Util.h"

bool Util::verificarNickname(Sistema* sistema, string nickname) {
    if(nickname.empty()) {
        cout<<endl<<"Error: El nombre del jugador no puede ser nulo."<<endl;
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