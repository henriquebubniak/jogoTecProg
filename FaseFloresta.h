#pragma once
#include "Fase.h"
#include "Greca.h"
#include "Greg.h"
#include "Obstaculo.h"

class FaseFloresta: public Fase
{

private:

    Greg greg;
    Greca greca;
    Obstaculo plataforma;

public:

    //construtora e destrutora
    FaseFloresta(RenderWindow* j = NULL);
    ~FaseFloresta();
};

