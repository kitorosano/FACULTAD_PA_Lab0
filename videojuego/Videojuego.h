#ifndef PA_LABORATORIO0_VIDEOJUEGO_H
#define PA_LABORATORIO0_VIDEOJUEGO_H
#include <string>
#include <vector>
#include "../partida/Partida.h"
using namespace std;


enum TipoJuego { Accion, Disparos, Estrategia, Simulacion, Deportes, Aventura, Carreras, Plataformas };
static const char* TipoJuego_str[] = {"Accion", "Disparos", "Estrategia", "Simulacion", "Deportes", "Aventura", "Carreras", "Plataformas"};

class Videojuego {

    private:
        string nombre;
        TipoJuego genero;
        float totalHorasJuego;
        vector<Partida*> partidas;
        
    public:
        Videojuego();
        Videojuego(string nombre, TipoJuego genero);
        ~Videojuego();
        
        string getNombre();
        string getGenero();
        float getTotalHorasJuego();
        vector<Partida*> getPartidas();
        int getCantidadPartidas();
        
        void setNombre(string nombre);
        void setGenero(TipoJuego genero);
        void guardarPartida(Partida *partida);
        void setTotalHorasJuego(float totalHorasJuego);

        string toString();
};


#endif //PA_LABORATORIO0_VIDEOJUEGO_H
