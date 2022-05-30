#pragma once
#include <list>
#include "Entidade.h"
#include "Projetil.h"
using namespace std;
class Fase
{
protected:
    list<Entidade*> lista_ent;
    list<Projetil*> lista_proj;
    RenderWindow* janela;
    //GerenciadorDeColisoes gdc;

public:
    Fase(RenderWindow* j = NULL);
    ~Fase();
    void move_ents();
    void testa_colisao();
    void imprime_ents();
    void ataca_ents();
};

