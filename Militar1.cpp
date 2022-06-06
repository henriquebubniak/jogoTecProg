#include "Militar1.h"
#include "Jogo.h"


/*=======================CONSTRUTORA E DESTRUTORA==============================*/
Militar1::Militar1(Camarada* g):
    Inimigo(Vector2f(WINDOW_SIZEX - 300.f, WINDOW_SIZEY - 300.f), "imagens/Militar1.png", 10, 0.4, g)
{
    camarada = g;
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
