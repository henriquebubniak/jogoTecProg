#pragma once

#include <list>
#include "Entidade.h"
#include "Projetil.h"
#include "Obstaculo.h"
#include "GerenciadorDeColisoes.h"
#include "GerenciadorGrafico.h"

using namespace std;

class Fase
{
protected:

    list<Entidade*> lista_ent;
    list<Projetil*> lista_proj;
    list<Obstaculo*> lista_obst;

    GerenciadorDeColisoes gdc;
    GerenciadorGrafico* pGerenciadorGrafico;
    float tempo;

public:

    //Construtora e Destrutora
    Fase(GerenciadorGrafico* pgg = NULL);
    ~Fase();

    //Fun��es
    void atualiza();
    void move_ents();
    void ataca_ents();

    void executa_fase(); //loop do jogo

    //adiciona
    void ad_proj(Projetil* p);

    //remove
    void rm_proj(Projetil* p);
    void rm_ent(Entidade* e);

    //get
    float get_tempo();
    list<Entidade*>* get_lista_ent();
    list<Projetil*>* get_lista_proj();
    list<Obstaculo*>* get_lista_obst();
    GerenciadorGrafico* get_gerenciador_grafico();


};

