#ifndef PA_LABORATORIO0_VIDEOJUEGO_H
#define PA_LABORATORIO0_VIDEOJUEGO_H
#include <string>

using namespace std;
enum class TipoJuego {Accion, Disparos, Estrategia, Simulacion, Deportes, Aventura, Carreras};

class Videojuego {

    private:
        string nombre;
        TipoJuego genero;
        long totalHorasJuego;
    public:
        Videojuego();
        Videojuego(string nombre, TipoJuego genero);
        ~Videojuego();
        string getNombre();
        TipoJuego getGenero();
        long getTotalHorasJuego();
        void setNombre(string nombre);
        void setGenero(TipoJuego genero);
        void setTotalHorasJuego(long totalHorasJuego);

};


#endif //PA_LABORATORIO0_VIDEOJUEGO_H
