#ifndef PA_LABORATORIO0_VIDEOJUEGO_H
#define PA_LABORATORIO0_VIDEOJUEGO_H
#include <string>

using namespace std;
enum class TipoJuego {Accion, Disparos, Estrategia, Simulacion, Deportes, Aventura, Carreras};

class Videojuego {
public:
    Videojuego();
    Videojuego(string nombre, TipoJuego genero);
    ~Videojuego();
    string getNombre();
    TipoJuego getGenero();
    void setNombre(string nombre);
    void setGenero(TipoJuego genero);
private:
    string nombre;
    TipoJuego genero;
};


#endif //PA_LABORATORIO0_VIDEOJUEGO_H
