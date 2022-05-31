#include "Chefao.h"
#include "Jogo.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Chefao::Chefao(Camarada* g):
    Inimigo(Vector2f(WINDOW_SIZEX - 200.f, WINDOW_SIZEY - 400.f), Vector2f(200.f, 200.f), 100, 0.3)
{
    caixa.setFillColor(Color::Red);
    camarada = g;
}


Chefao::~Chefao()
{
}

/*===================================================================*/

/*======================MOVE==============================*/

void Chefao::move()
{
    if (caixa.getPosition().x < camarada->get_pos().x)
    {
        velocidade.x += vel*0.01;
    }
    else if (caixa.getPosition().x > camarada->get_pos().x)
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
