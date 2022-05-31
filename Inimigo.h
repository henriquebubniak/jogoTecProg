#pragma once
#include "Personagem.h"

class Inimigo: public Personagem
{
private:

    /* data */

public:

    //construtora e destrutora
    Inimigo(Vector2f p, Vector2f tam_cx, int h, float v);
    ~Inimigo();

    //Funções
    void ataca(){}
};
