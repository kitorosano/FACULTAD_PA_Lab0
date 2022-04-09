#ifndef PA_LABORATORIO0_VIDEOJUEGO_H
#define PA_LABORATORIO0_VIDEOJUEGO_H
#include <string>


enum TipoJuego { Accion, Disparos, Estrategia, Simulacion, Deportes, Aventura, Carreras, Plataformas };
static const char* TipoJuego_str[] = {"Accion", "Disparos", "Estrategia", "Simulacion", "Deportes", "Aventura", "Carreras", "Plataformas"};

using namespace std;
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
        string getGenero();
        long getTotalHorasJuego();
        void setNombre(string nombre);
        void setGenero(string genero);
        void setTotalHorasJuego(long totalHorasJuego);

};


#endif //PA_LABORATORIO0_VIDEOJUEGO_H
