cmake_minimum_required(VERSION 3.21)
project(PA_Laboratorio0)

set(CMAKE_CXX_STANDARD 14)

add_executable(PA_Laboratorio0 main.cpp sistema/Sistema.cpp sistema/Sistema.h videojuego/Videojuego.cpp videojuego/Videojuego.h partida/Partida.cpp partida/Partida.h jugador/Jugador.cpp jugador/Jugador.h partida/PartidaIndividual.cpp partida/PartidaIndividual.h partida/PartidaMultijugador.cpp partida/PartidaMultijugador.h partida/dtFechaHora.cpp partida/dtFechaHora.h datatypes/dtFechaHora.cpp datatypes/dtFechaHora.h)
