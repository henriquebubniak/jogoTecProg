#include "Projetil.h"
#include "Jogo.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Projetil::Projetil(int f, Vector2f pos, Vector2f tam_cx, float vel_x):
forca(f),
Entidade(pos, tam_cx)
{
    velocidade = Vector2f(vel_x, 0.f);
    caixa.setFillColor(Color::White);
}

Projetil::~Projetil()
{
    pfase->rm_proj(this);
}

/*===================================================================*/

/*==============================MOVE================================*/

void Projetil::move()
{
    caixa.move(velocidade);
    velocidade.y += Jogo::get_g() * (0.001);
}

bool Projetil::colide(Entidade* ent)
{
    if (caixa.getGlobalBounds().intersects(ent->get_GlobalBounds()))
        return true;
    else
        return false;
}

/*===================================================================*/

/*==============================TESTA COLISAO================================*/
/*
void Projetil::testa_colisao(Entidade* ent)
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
        }
        if (posJog.left < posObst.left + posObst.width                 &&
            posJog.left + posJog.width > posObst.left                 &&
            posJog.top > posObst.top                                   &&
            posJog.top + posJog.height > posObst.top + posObst.height) //colisão abaixo.
        {
            velocidade.y = 0;
            caixa.setPosition(Vector2f(posJog.left, posObst.top + posObst.height));
        }
        ent->dano(forca);
        //p_lista_ent->remove(static_cast<Entidade*>(this));
        //delete this;
    }
}
*/
/*===================================================================*/

/*==============================GETS================================*/

int Projetil:: get_forca ()
{

    return forca;

}

/*===================================================================*/
