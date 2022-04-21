#include <sstream>
#include "Jugador.h"

using namespace std;

Jugador::Jugador() {}

Jugador::Jugador(string nickname, int edad, string password) {
    this->nickname = nickname;
    this->edad = edad;
    this->password = password;
}

Jugador::~Jugador() {}

void Jugador::setNickname(string nickname) {
    this->nickname = nickname;
}

void Jugador::setEdad(int edad) {
    this->edad = edad;
}

void Jugador::setPassword(string password) {
    this->password = password;
}

string Jugador::getNickname() {
    return this->nickname;
}

string Jugador::getPassword() {
    return this->password;
}

int Jugador::getEdad() {
    return this->edad;
}

string Jugador::toString() {
    stringstream ss;
    ss<<"|------------"<<endl;
    ss<<"| Nickname: "<<getNickname()<<" | Edad: "<<getEdad()<<" años | Password: "<<getPassword()<<endl;
    ss<<"|------------"<<endl;
    return ss.str();
}
