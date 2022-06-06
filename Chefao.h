#pragma once

#include "Inimigo.h"
#include "Camarada.h"

class Chefao: public Inimigo
{
private:

    Camarada* camarada;

public:

    //Construtora e Destrutora
    Chefao(Camarada* g = NULL);
    ~Chefao();

    //Fun��es
    void move();
};

