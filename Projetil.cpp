#include "Projetil.h"
#include "Jogo.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Projetil::Projetil(int f, Vector2f pos, Vector2f tam_cx, float vel_x, float vel_y):
forca(f),
Entidade(pos, tam_cx)
{
    velocidade = Vector2f(vel_x, vel_y);
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


/*==============================GETS================================*/

int Projetil:: get_forca ()
{

    return forca;

}

/*===================================================================*/
