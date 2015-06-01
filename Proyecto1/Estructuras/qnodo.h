#ifndef QNODO_H
#define QNODO_H

#include <QString>

class QNodo
{
public:
    QNodo();
    QNodo(QString string);
    QString string;
    QNodo* anterior;
};

#endif // QNODO_H
