#pragma once
#include "Inimigo.h"
class Militar2: public Inimigo
{
private:

    Camarada* camarada;

public:

    //Construtora e Destrutora
    Militar2(Camarada* g = NULL);
    ~Militar2();

    //Funcoes
    void move();
    void ataca();
};


