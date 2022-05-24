#pragma once
#include "Entidade.h"
class Projetil: public Entidade
{
private:
    int forca;
public:
    Projetil(int f, Vector2f pos, Vector2f tam_cx, float vel_x);
    ~Projetil();
    void ataca(){}
    void move();
    bool colide(Entidade* ent);
    void dano(int d) {}
};

