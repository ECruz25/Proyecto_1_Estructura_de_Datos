#include "cola.h"

Cola::Cola()
{
    frente = NULL;
    ultimo = NULL;
    size = 0;
}

void Cola::quitarCola()
{
    QNodo* temp;
    if(frente)
    {
        temp = frente;
        frente = frente->anterior;
        delete temp;
        size--;
    }
}

void Cola::ponerCola(QNodo* nodo)
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

QNodo* Cola::getFrente()
{
    return frente;
}
/*
void Cola::anular()
{
    while(quitarCola());
}
*/
bool Cola::vacia()
{
    if(frente)
    {
        return false;
    }
    return true;
}
