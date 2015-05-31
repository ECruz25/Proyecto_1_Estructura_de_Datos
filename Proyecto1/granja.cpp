#include "granja.h"

Granja::Granja()
{
    size = 0;
    inicio = NULL;
    final = NULL;
}

void Granja::add(QString nombre, QString tipo)
{
    size++;
    if(!inicio)
    {
        inicio = new Tamagotchi(nombre,tipo);
        final = inicio;
        return;
    }
    Tamagotchi* temp = new Tamagotchi(nombre,tipo);
    temp->siguiente = inicio;
    inicio = temp;
    if(temp->nombre == nombre)
    {
        return;
    }
    final->siguiente = new Tamagotchi(nombre,tipo);
    final = final->siguiente;
}

void Granja::remove(int pos)
{
    pos -= 1;
    if(pos >= 0 && pos < size-1)
    {
        Tamagotchi* temp = getPos(pos);
        Tamagotchi* tempo = temp->siguiente;
        temp->siguiente =tempo->siguiente;
        delete tempo;
        size--;
    }
    else if(pos == -1)
    {
        Tamagotchi* temp = inicio;
        inicio = inicio->siguiente;
        delete temp;
        size--;
    }
    else if(pos == size-2)
    {
        Tamagotchi* temp = getPos(pos);
        temp->siguiente = NULL;
        delete final;
        final = temp;
        size--;
    }
}

void Granja::insert(int pos, QString nombre, QString tipo)
{
    if(pos >= 0 && pos < size)
    {
        if(pos == 0)
        {
            Tamagotchi* temp = new Tamagotchi(nombre,tipo);
            temp->siguiente = inicio;
            inicio = temp;
        }
        else if(pos == size-1)
        {
            add(nombre, tipo);
        }
        else
        {
            Tamagotchi* temp = getPos(pos-1);
            Tamagotchi* tempo = new Tamagotchi(nombre,tipo);
            tempo->siguiente = temp->siguiente;
            temp->siguiente = tempo;
            size++;
        }
    }
}

Tamagotchi* Granja::getFinal()
{
    return final;
}

Tamagotchi* Granja::getPos(int pos)
{
    if(pos >= 0 && pos < size)
    {
        if(pos == size-1)
        {
            return final;
        }
        else
        {
            Tamagotchi* temp = inicio;
            for(int i = 1; i <= pos; i++)
            {
                temp = temp->siguiente;
            }
            return temp;
        }
    }
    return NULL;
}

bool Granja::isEmpty()
{
    if(inicio==NULL)
        return true;
    return false;
}

void Granja::regalar_monedas(int cant, QString nombre)
{
    if(!inicio)
        return;
    Tamagotchi* temp = inicio;
    if(temp->nombre == nombre)
    {
        temp->recibir_monedas(cant);
    }
}
