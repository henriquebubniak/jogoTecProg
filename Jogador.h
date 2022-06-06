#pragma once

#include "Personagem.h"
#include "Projetil.h"
#include <iostream>

using namespace std;

class Jogador: public Personagem
{
protected:

    bool pode_atirar;

    float auxt;

    int tiros_tambor;

public:

    //construtora e destrutora
    Jogador(Vector2f p = Vector2f(0.f, 0.f),const char* caminhoTextura = "/imagens/padrao.png", int h = 10, float v = 1);
    ~Jogador();

    //Fun��es
    void move();
    void ataca();
};
