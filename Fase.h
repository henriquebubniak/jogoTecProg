#pragma once
#include <list>
#include "Entidade.h"
using namespace std;
class Fase
{
protected:
    list<Entidade*> lista_ent;
    RenderWindow* janela;
public:
    Fase(RenderWindow* j = NULL);
    ~Fase();
    void move_ents();
    void testa_colisao();
    void imprime_ents();
    void ataca_ents();
};

