#pragma once
#include "Inimigo.h"
#include "Camarada.h"



class Militar1: public Inimigo
{

private:

    Camarada* camarada;

public:

    //Construtora e Destrutora
    Militar1(Camarada* g = NULL);
    ~Militar1();

    //Funcoes
    void move();
};
