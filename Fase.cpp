#include "Fase.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Fase::Fase(RenderWindow* j):
    janela(j),
    gdc(&lista_ent, &lista_proj),gg(&lista_ent, &lista_proj, janela),
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
    gdc.testaColisoes();
    gg.atualizaJanela();
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


/*==================ADICIONA PROJETEIS=========================*/

void Fase::ad_proj(Projetil* p)
{
    lista_proj.push_back(p);
}

/*===================================================================*/

/*==================REMOVE PROJETEIS=========================*/

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

/*===================================================================*/

/*==================GET=========================*/

float Fase:: get_tempo (){

    return tempo;
}
