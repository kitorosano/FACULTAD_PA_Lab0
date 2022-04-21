#include "View.h"
#include "../util/Util.h"
#include <iostream>
#include <limits>

void View::menu() {
    system("cls");
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
        system("cls");
        cout<<"|------------------------------------------------------|"<<endl;
        cout<<"|                   AGREGAR  JUGADOR                   |"<<endl;
        cout<<"|------------------------------------------------------|"<<endl<<endl;
        cout<<"Ingrese el nickname:";
        cin.ignore();
        getline(cin, nickname);
    } while(!utilities->verificarNickname(sistema, nickname));
    do{
        system("cls");
        cout<<"|------------------------------------------------------|"<<endl;
        cout<<"|                   AGREGAR  JUGADOR                   |"<<endl;
        cout<<"|------------------------------------------------------|"<<endl<<endl;
        cout<<"Ingrese la edad:";
        cin>>edad;
    } while(!utilities->verificarEdad(edad));
    //De esta forma permito que la password sea por defecto 123456
    system("cls");
    cout<<"|------------------------------------------------------|"<<endl;
    cout<<"|                   AGREGAR  JUGADOR                   |"<<endl;
    cout<<"|------------------------------------------------------|"<<endl<<endl;
    cout<<"Ingrese la password (por defecto 123456):";
    cin.ignore();
    getline(cin, password);
    sistema->agregarJugador(nickname, stoi(edad), password);
    system("cls");
    cout<<"|------------------------------------------------------|"<<endl;
    cout<<"|                   AGREGAR  JUGADOR                   |"<<endl;
    cout<<"|------------------------------------------------------|"<<endl<<endl;
    cout<<"Jugador agregado con exito!"<<endl<<endl;
    system("pause");
}

void View::agregarVideojuegoView(Sistema *sistema) {
    Util* utilities = new Util();
    string nombre;
    string genero;
    do{
        system("cls");
        cout<<"|------------------------------------------------------|"<<endl;
        cout<<"|                 AGREGAR   VIDEOJUEGO                 |"<<endl;
        cout<<"|------------------------------------------------------|"<<endl<<endl;
        cout<<"Ingrese el nombre:";
        cin.ignore();
        getline(cin, nombre);
    } while(!utilities->verificarNombre(sistema, nombre));
    do{
        system("cls");
        cout<<"|------------------------------------------------------|"<<endl;
        cout<<"|                 AGREGAR   VIDEOJUEGO                 |"<<endl;
        cout<<"|------------------------------------------------------|"<<endl;
        cout<<"| 1. Accion                                            |"<<endl;
        cout<<"| 2. Disparos                                          |"<<endl;
        cout<<"| 3. Estrategia                                        |"<<endl;
        cout<<"| 4. Simulacion                                        |"<<endl;
        cout<<"| 5. Deportes                                          |"<<endl;
        cout<<"| 6. Aventura                                          |"<<endl;
        cout<<"| 7. Carreras                                          |"<<endl;
        cout<<"| 8. Plataformas                                       |"<<endl;
        cout<<"|------------------------------------------------------|"<<endl<<endl;
        cout<<"Ingrese el genero:";
        cin>>genero;
    } while(!utilities->verificarGenero(genero));
    switch(stoi(genero)) {
        case 1:
            sistema->agregarVideojuego(nombre, TipoJuego::Accion);
            break;
        case 2:
            sistema->agregarVideojuego(nombre, TipoJuego::Disparos);
            break;
        case 3:
            sistema->agregarVideojuego(nombre, TipoJuego::Estrategia);
            break;
        case 4:
            sistema->agregarVideojuego(nombre, TipoJuego::Simulacion);
            break;
        case 5:
            sistema->agregarVideojuego(nombre, TipoJuego::Simulacion);
            break;
        case 6:
            sistema->agregarVideojuego(nombre, TipoJuego::Aventura);
            break;
        case 7:
            sistema->agregarVideojuego(nombre, TipoJuego::Carreras);
            break;
        case 8:
            sistema->agregarVideojuego(nombre, TipoJuego::Plataformas);
            break;
    }
    system("cls");
    cout<<"|------------------------------------------------------|"<<endl;
    cout<<"|                 AGREGAR   VIDEOJUEGO                 |"<<endl;
    cout<<"|------------------------------------------------------|"<<endl<<endl;
    cout<<"Videojuego agregado con exito!"<<endl<<endl;
    system("pause");
}

void View::obtenerJugadoresView(Sistema* sistema){
    Util* utilities = new Util();
    string cantidad;
    int cant = 0;
    do{
        system("cls");
        cout<<"|------------------------------------------------------|"<<endl;
        cout<<"|                   OBTENER  JUGADORES                 |"<<endl;
        cout<<"|------------------------------------------------------|"<<endl<<endl;
        if(sistema->getJugadores().empty()){
            cout<<"No hay jugadores registrados."<<endl<<endl;
            system("pause");
            return;
        }
        cout<<"Ingrese la cantidad:";
        cin>>cantidad;
    } while(!utilities->verificarCantidadJugadores(sistema,cantidad));
    system("cls");
    cout<<"|------------------------------------------------------|"<<endl;
    cout<<"|                   OBTENER  JUGADORES                 |"<<endl;
    cout<<"|------------------------------------------------------|"<<endl<<endl;
    cant = stoi(cantidad);
    for (Jugador* jugador : sistema->obtenerJugadores(cant)) {
        cout<<jugador->toString();
    }
    cout<<endl<<"|------------------------------------------------------|"<<endl<<endl;
    system("pause");
}

void View::obtenerVideojuegosView(Sistema* sistema){
    Util* utilities = new Util();
    string cantidad;
    int cant = 0;
    do{
        system("cls");
        cout<<"|------------------------------------------------------|"<<endl;
        cout<<"|                 OBTENER  VIDEOJUEGOS                 |"<<endl;
        cout<<"|------------------------------------------------------|"<<endl<<endl;
        if(sistema->getVideojuegos().empty()){
            cout<<"No hay videojuegos registrados."<<endl<<endl;
            system("pause");
            return;
        }
        cout<<"Ingrese la cantidad:";
        cin>>cantidad;
    } while(!utilities->verificarCantidadVideojuegos(sistema,cantidad));
    system("cls");
    cout<<"|------------------------------------------------------|"<<endl;
    cout<<"|                 OBTENER  VIDEOJUEGOS                 |"<<endl;
    cout<<"|------------------------------------------------------|"<<endl<<endl;
    cant = stoi(cantidad);
    for (Videojuego* videojuego : sistema->obtenerVideojuegos(cant)) {
        cout<<videojuego->toString();
    }
    cout<<endl<<"|------------------------------------------------------|"<<endl;
    system("pause");
}

void View::obtenerPartidasView(Sistema* sistema){
    Util* utilities = new Util();
    string nombreVideojuego;
    string cantidad;
    int cant = 0;
    do{
        system("cls");
        cout<<"|------------------------------------------------------|"<<endl;
        cout<<"|                 OBTENER   PARTIDAS                   |"<<endl;
        cout<<"|------------------------------------------------------|"<<endl<<endl;
        if(sistema->getVideojuegos().empty()){
            cout<<"No hay videojuegos registrados."<<endl<<endl;
            system("pause");
            return;
        }
        cout<<"Ingrese el nombre del videojuego:";
        cin.ignore();
        getline(cin, nombreVideojuego);
    } while(!utilities->verificarVideojuego(sistema, nombreVideojuego));
    do{
        system("cls");
        cout<<"|------------------------------------------------------|"<<endl;
        cout<<"|                 OBTENER   PARTIDAS                   |"<<endl;
        cout<<"|------------------------------------------------------|"<<endl<<endl;
        cout<<"Videojuego: "<<nombreVideojuego<<endl<<endl;
        for(Videojuego* videojuego : sistema->getVideojuegos()){
            if(videojuego->getNombre() == nombreVideojuego){
                if(videojuego->getPartidas().empty()){
                    cout<<"No hay partidas registradas."<<endl<<endl;
                    system("pause");
                    return;
                }
                cout<<"Ingrese la cantidad de partidas:";
                cin>>cantidad;
            }
        }
    } while(!utilities->verificarCantidadPartidas(sistema, nombreVideojuego, cantidad));
    cant = stoi(cantidad);
    vector<Partida*> partidas = sistema->obtenerPartidas(nombreVideojuego, cant);
    cout<<"\t"<<"Partidas: "<<endl;
    cout<<"\t\t--------------------------------------"<<endl;
    for(Partida* partida : partidas){
        cout<<partida->toString();
        cout<<"\t\t--------------------------------------"<<endl;
    }
    system("pause");
}

void View::crear_e_IniciarPartidaView(Sistema *sistema) {
    Util *utilities = new Util();
    string nombreVideojuego;
    string nombreJugador;
    string nombreJugadorIniciador;
    string cantidad;
    string duracion;
    string tipoPartida;
    cin.ignore(numeric_limits<size_t>::max(), '\n');
    do {
        system("cls");
        cout << "|------------------------------------------------------|" << endl;
        cout << "|                CREAR E INICIAR PARTIDA               |" << endl;
        cout << "|------------------------------------------------------|" << endl << endl;
        if (sistema->getVideojuegos().empty()) {
            cout << "No hay videojuegos registrados." << endl << endl;
            system("pause");
            return;
        }
        if (sistema->getJugadores().empty()) {
            cout << "No hay jugadores registrados." << endl << endl;
            system("pause");
            return;
        }
        cout << "Ingrese el nickname:";
        cin.clear();
        getline(cin, nombreJugadorIniciador);
    }while (!utilities->verificarJugador(sistema, nombreJugadorIniciador));
    do {
        system("cls");
        cout << "|------------------------------------------------------|" << endl;
        cout << "|                CREAR E INICIAR PARTIDA               |" << endl;
        cout << "|------------------------------------------------------|" << endl << endl;
        cout<<"Ingrese el nombre del videojuego:";
        cin.clear();
        getline(cin, nombreVideojuego);
        //cin>>nombreVideojuego;
    }while (!utilities->verificarVideojuego(sistema, nombreVideojuego));

    do{
        system("cls");
        cout << "|------------------------------------------------------|" << endl;
        cout << "|                CREAR E INICIAR PARTIDA               |" << endl;
        cout << "|------------------------------------------------------|" << endl << endl;
        cout << "Ingrese duracion:";
        cin>>duracion;
    }while(!utilities->verificarDuracion(duracion));
    do{
        system("cls");
        cout<<"|------------------------------------------------------|"<<endl;
        cout<<"|                 CREAR E INICIAR PARTIDA              |"<<endl;
        cout<<"|------------------------------------------------------|"<<endl;
        cout<<"| 1. Individual                                        |"<<endl;
        cout<<"| 2. Multijugador                                      |"<<endl;
        cout<<"|------------------------------------------------------|"<<endl<<endl;
        cout<<"Ingrese el tipo de partida:";
        cin>>tipoPartida;
    } while(!utilities->verificarOpcion(tipoPartida));
    Partida* dato;
    if(tipoPartida == "1"){
        string continua;
        bool continuaPartidaAnterior;
        do {
            system("cls");
            cout<<"|------------------------------------------------------|"<<endl;
            cout<<"|                 CREAR E INICIAR PARTIDA              |"<<endl;
            cout<<"|------------------------------------------------------|"<<endl;
            cout<<"| 1. Es una continuacion de una partida anterior       |"<<endl;
            cout<<"| 2. No es una continuacion de una partida anterior    |"<<endl;
            cout<<"|------------------------------------------------------|"<<endl<<endl;
            cout << "Ingrese una opcion:";
            cin >> continua;
        }while(!utilities->verificarOpcion(continua));
        if(continua == "1"){
            continuaPartidaAnterior = true;
        }else if(continua == "2"){
            continuaPartidaAnterior = false;
        }
        dato = sistema->crearPartidaInd(stof(duracion), continuaPartidaAnterior);
    } else if (tipoPartida == "2") {
        string transmitida;
        bool transmitidaEnVivo;
        string agregarJugador;
        vector<Jugador*> listaJugadores; // jugadores de la partida
        for (Jugador *jug : sistema->getJugadores()) {
            if (jug->getNickname() == nombreJugadorIniciador) {
                listaJugadores.push_back(jug);
            }
        }
        do {
            system("cls");
            cout<<"|------------------------------------------------------|"<<endl;
            cout<<"|                 CREAR E INICIAR PARTIDA              |"<<endl;
            cout<<"|------------------------------------------------------|"<<endl;
            cout<<"| 1. La partida es transmitida en vivo                 |"<<endl;
            cout<<"| 2. La partida no es transmitida en vivo              |"<<endl;
            cout<<"|------------------------------------------------------|"<<endl<<endl;
            cout << "Ingrese una opcion:";
            cin >> transmitida;
        }while(!utilities->verificarOpcion(transmitida));
        if(transmitida == "1"){
            transmitidaEnVivo = true;
        }else if(transmitida == "2"){
            transmitidaEnVivo = false;
        }
        do{
            bool jugadorEnLista = false;
            do {
                system("cls");
                cout << "|------------------------------------------------------|" << endl;
                cout << "|                CREAR E INICIAR PARTIDA               |" << endl;
                cout << "|------------------------------------------------------|" << endl << endl;
                cout << "Ingrese el nickname de un jugador para la partida:";
                cin.clear();
                getline(cin, nombreJugador);
                for (Jugador *jug : listaJugadores) {
                    if (jug->getNickname() == nombreJugador) {
                        cout<<endl<<"Error: Este jugador ya fue ingresado."<<endl;
                        jugadorEnLista = true;
                    }
                }
            } while ((!utilities->verificarJugador(sistema, nombreJugador)) || jugadorEnLista);

            for (Jugador *jug : sistema->getJugadores()) {
                if (jug->getNickname() == nombreJugador) {
                    listaJugadores.push_back(jug);
                }
            }

            do {
                system("cls");
                cout<<"|------------------------------------------------------|"<<endl;
                cout<<"|                 CREAR E INICIAR PARTIDA              |"<<endl;
                cout<<"|------------------------------------------------------|"<<endl;
                cout<<"| 1. Agregar otro jugador                              |"<<endl;
                cout<<"| 2. No agregar otro jugador                                        |"<<endl;
                cout<<"|------------------------------------------------------|"<<endl<<endl;
                cout<<"Ingrese una opcion:";
                cin>>agregarJugador;
            } while(!utilities->verificarOpcion(agregarJugador));

        } while (stoi(agregarJugador) != 2);

        dato = sistema->crearPartidaMul(stof(duracion), transmitidaEnVivo, listaJugadores);
    }

    sistema->iniciarPartida(nombreJugadorIniciador, nombreVideojuego, dato);
    system("cls");
    cout << "|------------------------------------------------------|" << endl;
    cout << "|                CREAR E INICIAR PARTIDA               |" << endl;
    cout << "|------------------------------------------------------|" << endl << endl;
    cout<<"Partida agregada con exito!"<<endl<<endl;
    system("pause");
}