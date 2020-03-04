#ifndef LISTA_H
#define LISTA_H

#include<stdlib.h>
#include<iostream>
using namespace std;


class lista
{
public:
    lista();
    ~lista();
    //lista operator+( double co );
    void doloz( double co );
    bool usun( double co );
    friend ostream& operator<<( ostream &out, const lista &org );
private:
    class element
    {
    public:
        double kl;
        element *nast, *pop;
    } *pier;
};

#endif // LISTA_H
