#ifndef TAMAGOTCHI_H
#define TAMAGOTCHI_H

#include <QString>
#include <QPixmap>

#include "Estructuras/pila.h"
#include "Estructuras/cola.h"
#include "Estructuras/billetera.h"
#include "actividad.h"
#include "moneda.h"

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
    int cant_monedas;
    QString tipo;
    QString nombre;
    Tamagotchi* siguiente;
    Billetera* monedas_ganadas;
    Billetera* monedas_recibidas;
    void recibir_monedas(int cant);
    void quitar_monedas(int cant);
    int resistencia_sueno;
    int resistencia_hambre;
    int resistencia_enfermedades;
};

#endif // TAMAGOTCHI_H
