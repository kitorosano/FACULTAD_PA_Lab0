//
// Created by Mathi on 7/4/2022.
//

#ifndef PA_LABORATORIO0_DTFECHAHORA_H
#define PA_LABORATORIO0_DTFECHAHORA_H

#include <string>
#include <iostream>

using namespace std;

class dtFechaHora {
private:
    int dd, MM, aaaa, HH, mm, ss;
public:
    dtFechaHora();
    dtFechaHora(int dd, int MM, int aaaa, int HH, int mm, int ss);

    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    int getMinuto();
    int getSegundo();

    string toString();
};


#endif //PA_LABORATORIO0_DTFECHAHORA_H
