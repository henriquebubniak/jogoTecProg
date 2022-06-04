#include "Militar1.h"
#include "Jogo.h"


/*=======================CONSTRUTORA E DESTRUTORA==============================*/
Militar1::Militar1(Camarada* g):
    Inimigo(Vector2f(WINDOW_SIZEX - 100.f, WINDOW_SIZEY - 400.f), Vector2f(50.f, 50.f), 100, 0.3, g)
{
    caixa.setFillColor(Color::Blue);
}

Militar1::~Militar1()
{

}
/*=============================================================================*/


/*======================MOVE==============================*/

void Militar1::move()
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
