#pragma once

#include "Camarada.h"
#include "Chefao.h"
#include "Projetil.h"
#include "Militar1.h"
#include "Obstaculo.h"
#include<list>

using namespace std;

class GerenciadorDeColisoes
{

private:

    list<Entidade*>* entidades;
    list<Projetil*>* projeteis;
    list<Obstaculo*>* obstaculos;
    GerenciadorGrafico* pGerenciadorGrafico;


public:

    //construtora e destrutora
    GerenciadorDeColisoes(list<Entidade*>* ple = NULL, list<Projetil*>* plp = NULL, list<Obstaculo*>* plo = NULL, GerenciadorGrafico* pgg = NULL);
    ~GerenciadorDeColisoes();


    //testes
    void testaColisoes ();
    void testaColisoesProjeteis();
    void testaColisoesEntidades ();
    void testaColisoesObstaculos ();

    //sets
    void setListaEntidades (list<Entidade*>* ent);
    void setListaProjeteis(list<Projetil*>* proj);


};

