#ifndef PA_LABORATORIO0_DTFECHAHORA_H
#define PA_LABORATORIO0_DTFECHAHORA_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class dtFechaHora {

    private:
        string date;
        string time;
    public:
        dtFechaHora();

        string toString();

};


#endif //PA_LABORATORIO0_DTFECHAHORA_H
