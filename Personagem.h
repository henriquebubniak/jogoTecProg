#pragma once
#include "Entidade.h"
class Personagem: public Entidade
{
protected:
    int tipo;
    int hp;
    float vel;
    bool pode_pular;
public:
    Personagem(Vector2f p = Vector2f(0.f, 0.f), Vector2f tam_cx = Vector2f(100.f, 100.f), int h = 10, float v = 1);
    ~Personagem();
    virtual void move() = 0;
};

