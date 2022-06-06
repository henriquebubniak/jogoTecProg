#pragma once

#include "Camarada.h"
#include "Chefao.h"
#include "Projetil.h"
#include "Obstaculo.h"
#include "Militar1.h"

#include<list>

using namespace std;

class GerenciadorGrafico{

private:

    list<Entidade*>* entidades;
    list<Projetil*>* projeteis;
    list<Obstaculo*>* obstaculos;


    RenderWindow* janela;

public:

    //construtora e destrutora
    GerenciadorGrafico(list<Entidade*>* ple = NULL, list<Projetil*>* plp = NULL, list<Obstaculo*>* plo = NULL, RenderWindow* j = NULL);
    ~GerenciadorGrafico();

    //Draw
    void imprimeEntes();
    void imprimeProjeteis();
    void imprimeObstaculos();
    void imprimeEntidades();
    void atualizaJanela();

    //sets
    void setListaEntidades (list<Entidade*>* ent);
    void setListaProjeteis(list<Projetil*>* proj);
    void setListaObstaculos (list<Obstaculo*>* obst);
    void setJanela (RenderWindow* j);



};
