#include "Fase.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Fase::Fase(RenderWindow* j):
janela(j),
gdc(&lista_ent, &lista_proj)
{

}

Fase::~Fase()
{
}

/*===================================================================*/

/*==================ATACA ENTES=========================*/

void Fase::ataca_ents()
{
    for (list<Entidade*>::iterator i = lista_ent.begin(); i != lista_ent.end(); i++)
    {
        (*i)->ataca();
    }
}

/*===================================================================*/


/*==================MOVE ENTES=========================*/

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

/*===================================================================*/

/*==================TESTA COLISAO=========================*/

void Fase::testa_colisao()
{
    gdc.testaColisoes();
}

/*===================================================================*/

/*==================IMPRIME ENTES=========================*/

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

/*===================================================================*/

/*==================ADICIONA PROJETEIS=========================*/

void Fase::ad_proj(Projetil* p)
{
    lista_proj.push_back(p);
}

/*===================================================================*/

/*==================REMOVEPROJETEIS=========================*/

void Fase::rm_proj(Projetil* p)
{
    lista_proj.remove(p);
}

/*===================================================================*/

/*==================REMOVE ENTES=========================*/

void Fase::rm_ent(Entidade* e)
{
    lista_ent.remove(e);
}

/*===================================================================*/
