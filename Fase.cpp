#include "Fase.h"

Fase::Fase(RenderWindow* j):
janela(j),
gdc(&lista_ent, &lista_proj)
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
    if (lista_proj.size() != 0)
        for (list<Projetil*>::iterator j = lista_proj.begin(); j != lista_proj.end(); j++)
            (*j)->move();
}

void Fase::testa_colisao()
{
    gdc.testaColisoes();
    /*int ii = 0;
    int jj = 0;
    for (list<Entidade*>::iterator i = lista_ent.begin(); i != lista_ent.end(); i++)
    {
        for(list<Entidade*>::iterator j = lista_ent.begin(); j != lista_ent.end(); j++)
        {
            (*i)->testa_colisao(*j);
            jj++;
        }
        ii++;
        jj = 0;
    }*/
}

void Fase::imprime_ents()
{
    if (lista_proj.size() != 0)
        for (list<Projetil*>::iterator j = lista_proj.begin(); j != lista_proj.end(); j++)
            (*j)->imprime();

    for (list<Entidade*>::iterator i = lista_ent.begin(); i != lista_ent.end(); i++)
    {
        (*i)->imprime();
    }
}

void Fase::ad_proj(Projetil* p)
{
    lista_proj.push_back(p);
}

void Fase::rm_proj(Projetil* p)
{
    lista_proj.remove(p);
}

void Fase::rm_ent(Entidade* e)
{
    lista_ent.remove(e);
}