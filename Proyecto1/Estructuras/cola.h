#ifndef COLA_H
#define COLA_H

#include <iostream>
#include "qnodo.h"

class Cola
{
public:
    Cola();
    void quitarCola();
    void ponerCola(QNodo* nodo);
    QNodo* getFrente();
    bool vacia();
    QNodo* frente;
    QNodo* ultimo;
    int size;
};

#endif // COLA_H
