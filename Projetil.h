#pragma once

#include "Entidade.h"

class Projetil: public Entidade
{
private:

    int forca;

public:

    //Construtora e destrutoras
    Projetil(int f, Vector2f pos, const char* caminhoTextura = "imagens/projetil.png", float vel_x = 0.f, float vel_y = 0.0);
    ~Projetil();

    //Fun��es
    void ataca(){}
    void move();
    bool colide(Entidade* ent);
    void dano(int d) {}
    int get_forca ();

};

