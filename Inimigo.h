#pragma once
#include "Personagem.h"
class Inimigo: public Personagem
{
private:
    /* data */
public:
    Inimigo(Vector2f p, Vector2f tam_cx, int h, float v);
    ~Inimigo();
    void ataca(){}
};
