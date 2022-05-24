#include "Projetil.h"
#include "Jogo.h"
Projetil::Projetil(int f, Vector2f pos, Vector2f tam_cx, float vel_x):
forca(f),
Entidade(pos, tam_cx)
{
    velocidade.x = vel_x;
}

Projetil::~Projetil()
{
}



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
