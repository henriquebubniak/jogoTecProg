#pragma once
#include "Entidade.h"

class Projetil: public Entidade
{
private:

    int forca;

public:

    //Construtora e destrutoras
    Projetil(int f, Vector2f pos, Vector2f tam_cx, float vel_x, float vel_y = 0.0);
    ~Projetil();

    //Fun��es
    void ataca(){}
    void move();
    bool colide(Entidade* ent);
    void dano(int d) {}
    int get_forca ();

    //void testa_colisao(Entidade* ent);
};

