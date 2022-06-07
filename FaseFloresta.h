#pragma once

#include "Fase.h"
#include "Chefao.h"
#include "Camarada.h"
#include "Obstaculo.h"
#include "Lama.h"
#include "Militar1.h"

class FaseFloresta: public Fase
{

private:

    Camarada camarada;
    Chefao chefao;
    Obstaculo plataforma;
    Militar1 militar;
    Lama lama1;


public:

    //construtora e destrutora
    FaseFloresta(RenderWindow* j = NULL, GerenciadorGrafico* pgg = NULL);
    ~FaseFloresta();

    void inicializa ();
};

