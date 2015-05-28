#ifndef MONEDA_H
#define MONEDA_H

class Moneda
{
public:
    Moneda();
    Moneda(int valor);
    int valor;
    Moneda* anterior;
};

#endif // MONEDA_H
