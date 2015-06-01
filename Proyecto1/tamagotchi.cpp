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

    monedas_ganadas = new Billetera();
    monedas_recibidas = new Billetera();

    if(tipo == "Fuerte")
    {
        resistencia_hambre = 0;
        resistencia_enfermedades = 5;
        resistencia_sueno = 0;
    }
    else if(tipo == "Inteligente")
    {
        resistencia_hambre = 0;
        resistencia_enfermedades = 0;
        resistencia_sueno = 5;
    }
    else if(tipo == "Habil")
    {
        resistencia_hambre = 5;
        resistencia_enfermedades = 0;
        resistencia_sueno = 0;
    }
}


void Tamagotchi::recibir_monedas(int cant)
{
    monedas_ganadas->poner(new Moneda(cant));
}

void Tamagotchi::quitar_monedas(int cant)
{

}
