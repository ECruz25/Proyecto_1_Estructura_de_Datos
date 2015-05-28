#include "pila.h"

Pila::Pila()
{
    this->tope = NULL;
}

Actividad* Pila::getTope()
{
    return this->tope;
}

void Pila::sacar()
{
    if(tope)
    {
        Actividad* t = tope;
        tope = tope->anterior;
        delete t;
    }
}

void Pila::meter(Actividad* obj)
{
    if(tope)
    {
        obj->anterior = tope;
    }
    tope = obj;
}

bool Pila::vacia()
{
    if(tope)
    {
        return false;
    }
    return true;
}

void Pila::anular()
{

}
