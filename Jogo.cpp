#include "Jogo.h"

int Jogo::gravidade = 10;
Jogo::Jogo(/* args */):
janela(VideoMode(WINDOW_SIZEX, WINDOW_SIZEY), "Jogo"), 
greg(&lista_ent),
greca(&greg),
plataforma(Vector2f(0.f, WINDOW_SIZEY-70), Vector2f(WINDOW_SIZEX, 70))
{
    lista_ent.push_back(static_cast<Entidade*> (&greg));
    lista_ent.push_back(static_cast<Entidade*> (&greca));
    lista_ent.push_back(static_cast<Entidade*> (&plataforma));
    for (list<Entidade*>::iterator i = lista_ent.begin(); i != lista_ent.end(); i++)
    {
        (*i)->setJanela(&janela);
    }
    while (janela.isOpen())
    {
        Event event;
        while (janela.pollEvent(event))
            if (event.type == Event::Closed)
                janela.close();
        
        for (list<Entidade*>::iterator i = lista_ent.begin(); i != lista_ent.end(); i++)
        {
            (*i)->move();
        }
        for (list<Entidade*>::iterator i = lista_ent.begin(); i != lista_ent.end(); i++)
        {
            for(list<Entidade*>::iterator j = lista_ent.begin(); j != lista_ent.end(); j++)
                (*i)->testa_colisao(*j);
        }
        janela.clear();
        for (list<Entidade*>::iterator i = lista_ent.begin(); i != lista_ent.end(); i++)
        {
            (*i)->imprime();
        }
        janela.display();
    }
}

Jogo::~Jogo()
{
}