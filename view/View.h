#ifndef PA_LABORATORIO0_VIEW_H
#define PA_LABORATORIO0_VIEW_H

#include <string>
#include "../sistema/Sistema.h"

using namespace std;


class View {
    public:
        void menu();
        void agregarJugadorView(Sistema* sistema);
        void agregarVideojuegoView(Sistema* sistema);
};


#endif //PA_LABORATORIO0_VIEW_H
