#pragma once

#include <SFML/Graphics.hpp>
#include "Entidade.h"

using namespace sf;

class Obstaculo: public Entidade
{

protected:


public:

    //construtora e destrutora
    Obstaculo(Vector2f pos, const char* caminhoTextura = "imagens/projetil.png");
    ~Obstaculo();

    //Fun��es
    void move(){}
    void ataca(){}
    void dano(int d) {}
    virtual void aplica_efeito(Entidade* ent) {}
};
