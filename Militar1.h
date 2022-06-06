#pragma once

#include "Inimigo.h"
#include "Camarada.h"

class Militar1: public Inimigo
{

private:

    Camarada* camarada;

public:

    //Construtora e Destrutora
    Militar1(Camarada* g = NULL, Vector2f pos = Vector2f (WINDOW_SIZEX - 100, WINDOW_SIZEY - 200));
    ~Militar1();

    //Funcoes
    void move();
};
