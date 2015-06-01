#ifndef BILLETERA_H
#define BILLETERA_H

#include "moneda.h"
#include <iostream>

class Billetera
{
public:
    Billetera();
    void quitar();
    void poner(Moneda* moneda);
    Moneda* getFrente();
    bool vacia();
    Moneda* frente;
    Moneda* ultimo;
    int size;
};

#endif // BILLETERA_H
