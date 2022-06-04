#pragma once

#include "Camarada.h"
#include "Chefao.h"
#include "Projetil.h"
#include "Militar1.h"

#include<list>
using namespace std;

class GerenciadorGrafico{

private:

    list<Entidade*>* entidades;
    list<Projetil*>* projeteis;

public:

    //construtora e destrutora
    GerenciadorGrafico(list<Entidade*>* ple = NULL, list<Projetil*>* plp = NULL);
    ~GerenciadorGrafico();

    //testes
    void imprimeEntes();
    void imprimeProjeteis();
    void imprimeEntidades();

    //sets
    void setListaEntidades (list<Entidade*>* ent);
    void setListaProjeteis(list<Projetil*>* proj);


};
