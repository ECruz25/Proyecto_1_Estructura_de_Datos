#include "billetera.h"

Billetera::Billetera()
{
    frente = NULL;
    ultimo = NULL;
    size = 0;
}

void Billetera::quitar()
{
    Moneda* temp;
    if(frente)
    {
        temp = frente;
        frente = frente->anterior;
        delete temp;
        size--;
    }
}

void Billetera::poner(Moneda* nodo)
{
    if(frente == NULL)
    {
        frente = nodo;
        ultimo = nodo;
        size++;
        return;
    }
    ultimo->anterior = nodo;
    ultimo = nodo;
    size++;
}

Moneda* Billetera::getFrente()
{
    return frente;
}

/*
void Billetera::anular()
{
    while(quitarBilletera());
}
*/

bool Billetera::vacia()
{
    if(frente)
    {
        return false;
    }
    return true;
}
