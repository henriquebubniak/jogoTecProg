#include "Fase.h"

Fase::Fase(RenderWindow* j):
janela(j)
{

}

Fase::~Fase()
{
}
void Fase::ataca_ents()
{
    for (list<Entidade*>::iterator i = lista_ent.begin(); i != lista_ent.end(); i++)
    {
        (*i)->ataca();
    }
}
void Fase::move_ents()
{
    for (list<Entidade*>::iterator i = lista_ent.begin(); i != lista_ent.end(); i++)
    {
        (*i)->move();
    }
}

void Fase::testa_colisao()
{
    for (list<Entidade*>::iterator i = lista_ent.begin(); i != lista_ent.end(); i++)
        {
            for(list<Entidade*>::iterator j = lista_ent.begin(); j != lista_ent.end(); j++)
                (*i)->testa_colisao(*j);
        }
}

void Fase::imprime_ents()
{
    for (list<Entidade*>::iterator i = lista_ent.begin(); i != lista_ent.end(); i++)
    {
        (*i)->imprime();
    }
}