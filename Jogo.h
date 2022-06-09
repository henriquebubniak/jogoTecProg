#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "FaseFloresta.h"
#include "Menu.h"

#define WINDOW_SIZEX 3000
#define WINDOW_SIZEY  1500

using namespace sf;
using namespace std;

class Jogo
{

private:

    Menu menu;
    GerenciadorGrafico gg;
    FaseFloresta floresta;
    static float gravidade;

public:

    //construtora e destrutora
    Jogo(/* args */);
    ~Jogo();

    void executa_fase_floresta();

    //Funcoes
    static float get_g();
};


