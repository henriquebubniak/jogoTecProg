#include "Fase.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Fase::Fase(RenderWindow* j):
janela(j),
gdc(&lista_ent, &lista_proj, &lista_obst),
tempo(0)
{

}

Fase::~Fase()
{
}

/*===================================================================*/

/*========================ATUALIZA==================================*/


void Fase::atualiza()
{
    move_ents();
    ataca_ents();
    testa_colisao();
    janela->clear();
    imprime_ents();
    janela->display();
    tempo += 8.333;
}
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
    for (list<Obstaculo*>::iterator i = lista_obst.begin(); i != lista_obst.end(); i++)
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

/*==================EXECUTA FASE=========================*/

void Fase::executa_fase()
{
    while (janela->isOpen())
    {
        Event event;
        while (janela->pollEvent(event))
            if (event.type == Event::Closed)
                janela->close();

        atualiza();
    }
}

