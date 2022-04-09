#ifndef PA_LABORATORIO0_JUGADOR_H
#define PA_LABORATORIO0_JUGADOR_H

#include <string>
using namespace std;


class Jugador {

    private:
        string nickname;
        int edad;
        string password;
    public:
        Jugador();
        Jugador(string nickname, int edad, string password);
        ~Jugador();
        string getNickname();
        int getEdad();
        string getPassword();
        void setNickname(string nickname);
        void setEdad(int edad);
        void setPassword(string password);

};


#endif //PA_LABORATORIO0_JUGADOR_H
