#pragma once

#include "Greg.h"
#include "Greca.h"
#include "Projetil.h"

#include<list>
using namespace std;

class GerenciadorDeColisoes {


public:

    static list<Entidade*> entidades;

    GerenciadorDeColisoes();
    ~GerenciadorDeColisoes();

    //Funções

    void testaColisoes ();


};

