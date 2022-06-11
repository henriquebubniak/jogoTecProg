#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "FaseFloresta.h"
#include "FaseDeserto.h"
#include "Menu.h"

#define WINDOW_SIZEX 3000
#define WINDOW_SIZEY  1500

using namespace sf;
using namespace std;

class Jogo
{

private:

    GerenciadorGrafico gg;
    FaseFloresta floresta;
    FaseDeserto deserto;
    Menu menu;
    static float gravidade;

public:

    //construtora e destrutora
    Jogo(/* args */);
    ~Jogo();

    void executa_fase_floresta();
    void executa_fase_deserto();

    //Funcoes
    static float get_g();
};


