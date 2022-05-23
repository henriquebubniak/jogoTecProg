#pragma once
#define WINDOW_SIZEX 2000
#define WINDOW_SIZEY  1000
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "FaseFloresta.h"
using namespace sf;
using namespace std;
class Jogo
{
private:
    RenderWindow janela;
    FaseFloresta floresta;
    static float gravidade;
public:
    Jogo(/* args */);
    ~Jogo();
    static float get_g() { return gravidade; }
};


