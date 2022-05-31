#pragma once
#include "Inimigo.h"
#include "Greg.h"

class Greca: public Inimigo
{
private:

    Greg* greg;

public:

    //Construtora e Destrutora
    Greca(Greg* g = NULL);
    ~Greca();

    //Funções
    void move();
};

