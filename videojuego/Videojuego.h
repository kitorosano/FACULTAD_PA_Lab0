//
// Created by Mathi on 7/4/2022.
//

#ifndef PA_LABORATORIO0_VIDEOJUEGO_H
#define PA_LABORATORIO0_VIDEOJUEGO_H
#include <string>

using namespace std;

class Videojuego {
private:
    string nombre;
    enum TipoGenero {Accion, Disparos, Estrategia, Simulacion, Deportes, Aventura, Carreras};
    TipoGenero genero;
public:
    Videojuego();
    Videojuego(string nombre, TipoGenero genero);
    ~Videojuego();
    string getNombre();
    TipoGenero getGenero();
    void setNombre(string nombre);
    void setGenero(TipoGenero genero);
};


#endif //PA_LABORATORIO0_VIDEOJUEGO_H
