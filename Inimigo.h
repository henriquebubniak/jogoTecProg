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
    Inimigo(Vector2f p,  const char* caminhoTextura = "imagens/padrao.png", int h = 0, float v = 0, Camarada* c = nullptr);
    ~Inimigo();

    //Funcoes
    void ataca();
};
