#include "tamagotchi.h"

Tamagotchi::Tamagotchi()
{
}

Tamagotchi::Tamagotchi(QString nombre, QString tipo)
{
    this->nombre = nombre;
    this->vida = 100;
    this->hambre = 0;
    this->desechos = 0;
    this->sueno = 0;
    this->enfermedad = 0;
    this->tipo = tipo;
}
