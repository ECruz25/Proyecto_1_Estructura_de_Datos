#include "cola.h"

Cola::Cola()
{

}

bool Cola::quitarCola()
{
    Nodo* temp;
    if(frente)
    {
        temp = frente;
        frente = frente->anterior;
        delete temp;
        return true;
    }
    return false;
}

void Cola::ponerCola(Nodo* nodo)
{
    if(frente == NULL)
    {
        frente = nodo;
        ultimo = nodo;
        return;
    }
    ultimo->anterior = nodo;
    ultimo = nodo;
}

Nodo* Cola::getFrente()
{
    return frente;
}

void Cola::anular()
{
    while(quitarCola());
}

bool Cola::vacia()
{
    if(frente)
    {
        return false;
    }
    return true;
}
