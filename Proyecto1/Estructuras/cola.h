#ifndef COLA_H
#define COLA_H

#include <iostream>
#include "nodo.h"

class Cola
{
public:
    Cola();
    bool quitarCola();
    void ponerCola(Nodo* nodo);
    Nodo* getFrente();
    void anular();
    bool vacia();
    Nodo* frente;
    Nodo* ultimo;
};

#endif // COLA_H
