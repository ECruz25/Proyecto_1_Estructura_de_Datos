#ifndef PILA_H
#define PILA_H

#include "actividad.h"

class Pila
{
public:
    Pila();
    Actividad* actividad;
    Actividad* tope;
    Actividad* getTope();
    bool sacar();
    void meter(Actividad* obj);
    bool vacia();
    void anular();
};

#endif // PILA_H
