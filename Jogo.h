#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "FaseFloresta.h"

#define WINDOW_SIZEX 2000
#define WINDOW_SIZEY  1000

using namespace sf;
using namespace std;

class Jogo
{

private:

    RenderWindow janela;
    FaseFloresta floresta;
    static float gravidade;

public:

    //construtora e destrutora
    Jogo(/* args */);
    ~Jogo();

    //Funções
    static float get_g() { return gravidade; }
};


