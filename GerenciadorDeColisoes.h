#pragma once

#include "Greg.h"
#include "Greca.h"
#include "Projetil.h"

#include<list>
using namespace std;

class GerenciadorDeColisoes
{

private:

    list<Entidade*>* entidades;
    list<Projetil*>* projeteis;


public:


    GerenciadorDeColisoes(list<Entidade*>* ple = NULL, list<Projetil*>* plp = NULL);
    ~GerenciadorDeColisoes();

    //Fun��es

    void testaColisoes ();
    void testaColisoesProjeteis();
    void testaColisoesEntidades ();
    void setListaEntidades (list<Entidade*>* ent);
    void setListaProjeteis(list<Projetil*>* proj);


};

