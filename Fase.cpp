#include "Fase.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Fase::Fase(GerenciadorGrafico* pgg):
    pGerenciadorGrafico(pgg),
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
    gdc.testaColisoes();
    pGerenciadorGrafico->atualizaJanela();
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
    while (pGerenciadorGrafico->get_JanelaAberta())
    {
        Event event;
        while (pGerenciadorGrafico->pega_evento(&event))
            if (event.type == Event::Closed)
                pGerenciadorGrafico->fecha_janela();

        atualiza();
    }
}

/*===================================================================*/

/*==================GET=========================*/

float Fase:: get_tempo (){

    return tempo;
}

list<Entidade*>* Fase::get_lista_ent()
{
    return &lista_ent;
}

list<Projetil*>* Fase:: get_lista_proj ()
{
    return &lista_proj;
}
list<Obstaculo*>* Fase:: get_lista_obst ()
{
    return &lista_obst;
}

