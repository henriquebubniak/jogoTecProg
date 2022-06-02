#include "Militar1.h"

/*=======================CONSTRUTORA E DESTRUTORA==============================*/
Militar1::Militar1(/* args */):
    Inimigo(Vector2f(WINDOW_SIZEX - 200.f, WINDOW_SIZEY - 400.f), Vector2f(200.f, 200.f), 100, 0.3, g)
{
    caixa.setFillColor(Color::Red);
}

Militar1::~Militar1()
{
}
/*=============================================================================*/
/*Chefao::Chefao(Camarada* g):
    Inimigo(Vector2f(WINDOW_SIZEX - 200.f, WINDOW_SIZEY - 400.f), Vector2f(200.f, 200.f), 100, 0.3, g)
{
    caixa.setFillColor(Color::Red);
    camarada = g;
}*?