#include "Greg.h"
#include "Jogo.h"
#include <iostream>

using namespace std;


/*==================CONSTRUTORA E DESTRUTORA=========================*/

Greg::Greg():
Jogador(Vector2f(0.f, WINDOW_SIZEY-200), Vector2f(40.f,80.f), 10, 1),
nvl_greg(10)
{
    caixa.setFillColor(Color::White);
}

Greg::~Greg(){}


/*===================================================================*/

/*==============================GETS================================*/

RectangleShape Greg:: get_caixa(){

    return caixa;
}

const Vector2f Greg:: get_pos(){

    return pos;
}
/*===================================================================*/

/*==============================TESTA COLISÃO================================*/


void Greg::testa_colisao (Entidade* ent)
{
    FloatRect proxPos, posJog;

    posJog = caixa.getGlobalBounds();
    proxPos = caixa.getGlobalBounds();
    proxPos.left += velocidade.x;
    proxPos.top += velocidade.y;

    FloatRect posObst;
    posObst = ent->get_GlobalBounds();

    if (proxPos.intersects(posObst))
    {
        if (posJog.left < posObst.left                                 &&
            posJog.left + posJog.width < posObst.left + posObst.width &&
            posJog.top < posObst.top + posObst.height                  &&
            posJog.top + posJog.height > posObst.top) //colisão a esquerda.
        {
            velocidade.x = 0;
            caixa.setPosition(Vector2f(posObst.left - posJog.width, posJog.top));
        }
        if (posJog.left > posObst.left                                 &&
            posJog.left + posJog.width > posObst.left + posObst.width &&
            posJog.top < posObst.top + posObst.height                  &&
            posJog.top + posJog.height > posObst.top) //colisão a direita.
        {
            velocidade.x = 0;
            caixa.setPosition(Vector2f(posObst.left + posObst.width, posJog.top));
        }
        if (posJog.left < posObst.left + posObst.width                 &&
            posJog.left + posJog.width > posObst.left                 &&
            posJog.top < posObst.top                                   &&
            posJog.top + posJog.height < posObst.top + posObst.height) //colisão acima.
        {
            velocidade.y = 0;
            caixa.setPosition(Vector2f(posJog.left, posObst.top - posJog.height));
            pode_pular = true;
        }
        if (posJog.left < posObst.left + posObst.width                 &&
            posJog.left + posJog.width > posObst.left                 &&
            posJog.top > posObst.top                                   &&
            posJog.top + posJog.height > posObst.top + posObst.height) //colisão acima.
        {
            velocidade.y = 0;
            caixa.setPosition(Vector2f(posJog.left, posObst.top + posObst.height));
        }

    }
}


/*===================================================================*/
