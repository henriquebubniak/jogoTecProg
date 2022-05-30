#pragma once
#include <list>
#include "Entidade.h"
#include "Projetil.h"
#include "GerenciadorDeColisoes.h"
using namespace std;
class Fase
{
protected:
    list<Entidade*> lista_ent;
    list<Projetil*> lista_proj;
    RenderWindow* janela;
    GerenciadorDeColisoes gdc;

public:
    Fase(RenderWindow* j = NULL);
    ~Fase();
    void move_ents();
    void testa_colisao();
    void imprime_ents();
    void ataca_ents();
    void ad_proj(Projetil* p);
    void rm_proj(Projetil* p);
    void rm_ent(Entidade* e);
};

