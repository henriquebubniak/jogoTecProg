#include "Greca.h"
#include "Jogo.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Greca::Greca(Greg* g):
    Inimigo(Vector2f(WINDOW_SIZEX - 200.f, WINDOW_SIZEY - 400.f), Vector2f(200.f, 200.f), 100, 0.3)
{
    caixa.setFillColor(Color::Red);
    greg = g;
}


Greca::~Greca()
{
}

/*===================================================================*/

/*======================MOVE==============================*/

void Greca::move()
{
    if (caixa.getPosition().x < greg->get_pos().x)
    {
        velocidade.x += vel*0.01;
    }
    else if (caixa.getPosition().x > greg->get_pos().x)
    {
        velocidade.x -= vel*0.01;
    }
    if (velocidade.x > vel*2)
        velocidade.x = vel*2;
    else if (velocidade.x < -vel*2)
        velocidade.x = -vel*2;
    caixa.move(velocidade);
    velocidade.y += Jogo::get_g() * 0.016;
}

/*===================================================================*/
