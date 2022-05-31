#pragma once
#include <SFML/Graphics.hpp>
#include "Entidade.h"

using namespace sf;

class Obstaculo: public Entidade
{

private:

    RectangleShape caixa;

public:

    //construtora e destrutora
    Obstaculo(Vector2f pos, Vector2f dim);
    ~Obstaculo();

    //Funções
    void move(){}
    void ataca(){}
    void dano(int d) {}
};
