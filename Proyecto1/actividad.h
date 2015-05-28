#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H

#include <QString>

class Actividad
{
public:
    Actividad();
    Actividad(int valor);
    int valor;
    Actividad* anterior;
};

#endif // ACTIVIDAD_H
