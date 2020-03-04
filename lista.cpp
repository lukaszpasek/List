#include "lista.h"

lista::lista()
{
    pier= 0;
}

lista::~lista()
{
    element *p;
    while( pier!= 0 )
    {
        p= pier;
        pier= pier->nast;
        delete p;
    }
}

void lista::doloz( double co )
{
    if( pier== 0 )
    {
        pier= new element;
        pier->kl= co;
        pier->nast= pier->pop= 0;
        return;
    }
    element *p, *q;
    p= pier;
    while( p->nast!= 0&& p->nast->kl< co )
        p= p->nast;
    q= new element;
    q->kl= co;
    if( p== pier&& co< pier->kl )
    {
        q->nast= pier;
        q->pop= 0;
        pier->pop= q;
        pier= q;
    }
    else
    {
        q->nast= p->nast;
        q->pop= p;
        p->nast= q;
        if( q->nast!= 0 )
            q->nast->pop= q;
    }
}

bool lista::usun( double co )
{
    element *p, *q;
    p= pier;
    q= 0;
    while( p!= 0&& p->kl< co )
    {
        q= p;
        p= p->nast;
    }
    if( p== 0|| p->kl> co )
    {
        cout<<"proba usuniecia nieistniejacego klucza z listy";
        exit( 1 );
    }
    if( p== pier )
        pier= pier->nast;
    else
        q->nast= p->nast;
    delete p;
    return *this;
}

ostream& operator<<( ostream &out, const lista &org )
{
    lista::element *p;
    out<<"poczatek->";
    p= org.pier;
    while( p!= 0 )
    {
        out<< p->kl<<"->";
        p= p->nast;
    }
    out<<"koniec"<< endl;
    return out;
}
