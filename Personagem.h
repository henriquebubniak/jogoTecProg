#pragma once

#include "Entidade.h"

class Personagem: public Entidade
{
protected:

    int tipo;
    int hp;
    float vel;
    float vel_max;
    float vel_slow;
    bool pode_pular;

public:

    //construtora e destrutora
    Personagem(Vector2f p = Vector2f(0.f, 0.f),  const char* caminhoTextura = "imagens/padrao.png", int h = 10, float v = 1);
    virtual ~Personagem();

    //Fun��es
    void move() = 0;
    void ataca() = 0;
    void dano(int d);
    void set_podepular (bool p);
    void set_slowpersonagem();
    void set_velmaxpersonagem();
};

