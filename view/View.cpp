#include "View.h"
#include "../util/Util.h"
#include <iostream>

void View::menu() {
    cout<<"|------------------------------------------------------|"<<endl;
    cout<<"|                 LABORATORIO  AVANZADA                |"<<endl;
    cout<<"|------------------------------------------------------|"<<endl;
    cout<<"| 1. Agregar jugador                                   |"<<endl;
    cout<<"| 2. Agregar videojuego                                |"<<endl;
    cout<<"| 3. Obtener jugadores                                 |"<<endl;
    cout<<"| 4. Obtener videojuegos                               |"<<endl;
    cout<<"| 5. Obtener partidas                                  |"<<endl;
    cout<<"| 6. Iniciar partida                                   |"<<endl;
    cout<<"| 0. Salir                                             |"<<endl;
    cout<<"|------------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese una opcion:";
}

void View::agregarJugadorView(Sistema* sistema) {
    Util* utilities = new Util();
    string nickname;
    string edad;
    string password;
    do{
        cout<<"|------------------------------------------------------|"<<endl;
        cout<<"|                   AGREGAR  JUGADOR                   |"<<endl;
        cout<<"|------------------------------------------------------|"<<endl<<endl;
        cout<<"Ingrese el nickname:";
        cin.ignore();
        getline(cin, nickname);
    } while(!utilities->verificarNickname(sistema, nickname));
    do{
        cout<<"|------------------------------------------------------|"<<endl;
        cout<<"|                   AGREGAR  JUGADOR                   |"<<endl;
        cout<<"|------------------------------------------------------|"<<endl<<endl;
        cout<<"Ingrese la edad:";
        cin>>edad;
    } while(!utilities->verificarEdad(edad));
    //De esta forma permito que la password sea por defecto 123456
    cout<<"|------------------------------------------------------|"<<endl;
    cout<<"|                   AGREGAR  JUGADOR                   |"<<endl;
    cout<<"|------------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese la password (por defecto 123456):";
    cin.ignore();
    getline(cin, password);
    sistema->agregarJugador(nickname, stoi(edad), password);
    cout<<"|------------------------------------------------------|"<<endl;
    cout<<"|                   AGREGAR  JUGADOR                   |"<<endl;
    cout<<"|------------------------------------------------------|"<<endl<<endl;
    cout<<"Jugador agregado con exito!"<<endl<<endl;
    system("pause");
}

