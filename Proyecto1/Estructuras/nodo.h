#ifndef NODO_H
#define NODO_H

class Nodo
{
public:
    Nodo();
    Nodo(int valor);
    ~Nodo();
    int valor;
    Nodo* anterior;
};

#endif // NODO_H
