#include "Jugador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>

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
    return "=| Nickname: " + getNickname() + "| Edad: " + to_string(getEdad()) + "| Password: " + getPassword();
}