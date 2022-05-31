#pragma once
#include "Fase.h"
#include "Chefao.h"
#include "Camarada.h"
#include "Obstaculo.h"

class FaseFloresta: public Fase
{

private:

    Camarada camarada;
    Chefao chefao;
    Obstaculo plataforma;

public:

    //construtora e destrutora
    FaseFloresta(RenderWindow* j = NULL);
    ~FaseFloresta();
};

