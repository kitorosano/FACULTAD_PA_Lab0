//
// Created by Mathi on 10/4/2022.
//

#ifndef PA_LABORATORIO0_UTIL_H
#define PA_LABORATORIO0_UTIL_H


#include "../sistema/Sistema.h"

class Util {
    public:
        bool verificarNickname(Sistema* sistema, string nickname);
        bool verificarEdad(string edad);
};


#endif //PA_LABORATORIO0_UTIL_H
