#pragma once
#include "Personagem.h"
#include "Projetil.h"
#include "Camarada.h"

class Inimigo: public Personagem
{
private:

    bool pode_atirar;
    float auxt;
    int tiros_tambor;
    Camarada* cam;

public:

    //construtora e destrutora
    Inimigo(Vector2f p, Vector2f tam_cx, int h, float v, Camarada* c);
    ~Inimigo();

    //Funcoes
    void ataca();
};
