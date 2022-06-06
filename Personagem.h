#pragma once
#include "Entidade.h"
class Personagem: public Entidade
{
protected:

    int tipo;
    int hp;
    float vel;
    float vel_slow;
    float vel_max;
    bool pode_pular;

public:

    //construtora e destrutora
    Personagem(Vector2f p = Vector2f(0.f, 0.f), Vector2f tam_cx = Vector2f(100.f, 100.f), int h = 10, float v = 1);
    virtual ~Personagem();

    //Fun��es
    void move() = 0;
    void ataca() = 0;
    void dano(int d);
    void set_podepular (bool p);
    void set_slowpersonagem ();
    void set_velmaxpersonagem();
};

