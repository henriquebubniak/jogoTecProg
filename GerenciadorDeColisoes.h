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


    GerenciadorDeColisoes();
    ~GerenciadorDeColisoes();

    //Funções

    void testaColisoes ();
    void testaColisoesProjeteis();
    void testaColisoesEntes();
    void setListaEntidades (list<Entidade*>* ent);
    void setListaProjeteis(list<Projetil*>* proj);


};

