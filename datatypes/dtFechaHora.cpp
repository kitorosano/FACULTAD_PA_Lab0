#include <iomanip>
#include "dtFechaHora.h"

dtFechaHora::dtFechaHora() {
    stringstream ssDate;
    stringstream ssTime;
    auto t = std::time(nullptr);
    auto tm = *localtime(&t);
    ssDate<<put_time(&tm, "%d-%m-%Y");
    ssTime<<put_time(&tm, "%H:%M:%S");
    this->date = ssDate.str();
    this->time = ssTime.str();
}

string dtFechaHora::toString() {
    stringstream ss;
    ss<<this->date<<" "<<this->time;
    return ss.str();
};