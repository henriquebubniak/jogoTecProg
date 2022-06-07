#pragma once

#include "Fase.h"
#include "Chefao.h"
#include "Camarada.h"
#include "Obstaculo.h"
#include "Lama.h"
#include "Mina.h"
#include "Militar1.h"
#include "Militar2.h"

class FaseFloresta: public Fase
{

private:

    Camarada camarada;
    Chefao chefao;
    Obstaculo plataforma;
    Militar1 militar1;
    Militar2 militar2;
    Lama lama1;
    Mina mina1;


public:

    //construtora e destrutora
    FaseFloresta(RenderWindow* j = NULL, GerenciadorGrafico* pgg = NULL);
    ~FaseFloresta();

    void inicializa ();
};

