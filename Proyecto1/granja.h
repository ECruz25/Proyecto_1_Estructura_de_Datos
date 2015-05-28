#ifndef GRANJA_H
#define GRANJA_H

#include "tamagotchi.h"

class Granja
{
public:
    Granja();
    void add(QString name, QString tipo);
    void remove(int pos);
    void insert(int pos, QString name, QString tipo);
    Tamagotchi* getFinal();
    Tamagotchi* getPos(int pos);
    bool isEmpty();
    void imprimir();
    int u;
    int size;

private:
    Tamagotchi* inicio;
    Tamagotchi* final;
};

#endif // GRANJA_H
