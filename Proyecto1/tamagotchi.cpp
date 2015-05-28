#include "tamagotchi.h"

Tamagotchi::Tamagotchi()
{
}

Tamagotchi::Tamagotchi(QString nombre, QString tipo)
{
    this->nombre = nombre;
    this->vida = 100 - ((hambre + desechos + sueno + enfermedad) * 0.25);
    this->hambre = 0;
    this->desechos = 0;
    this->sueno = 0;
    this->enfermedad = 0;
    this->cant_monedas = 0;
    this->tipo = tipo;
}

void Tamagotchi::regalar_monedas(int cant, QString nombre)
{

}

