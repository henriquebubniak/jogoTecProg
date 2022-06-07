#pragma once

#include <SFML/Graphics.hpp>
#include "Entidade.h"

using namespace sf;

class Obstaculo: public Entidade
{

protected:

    bool tipo;

public:

    //construtora e destrutora
    Obstaculo(Vector2f pos, const char* caminhoTextura = "imagens/padrao.png", bool tipo = true);
    ~Obstaculo();

    //Fun��es
    void move(){}
    void ataca(){}
    void dano(int d) {}
    virtual void aplica_efeito(Entidade* ent) {}

    ////////////
    //Tipos: Perene-> Nao eh deletado apos colidir; Temporario-> morre apos colidir
    // Perene: True
    // Temporario: False
    //
    ///////////
    bool get_tipo ();
};
