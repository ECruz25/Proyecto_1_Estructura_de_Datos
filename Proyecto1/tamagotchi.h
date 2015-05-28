#ifndef TAMAGOTCHI_H
#define TAMAGOTCHI_H

#include <QString>

#include "Estructuras/pila.h"
#include "actividad.h"

class Tamagotchi
{
public:
    Tamagotchi();
    Tamagotchi(QString nombre, QString tipo);
    int vida;
    int hambre;
    int desechos;
    int enfermedad;
    int sueno;
    QString tipo;
    QString nombre;
    Tamagotchi* siguiente;
};

#endif // TAMAGOTCHI_H
