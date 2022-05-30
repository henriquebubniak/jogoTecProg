#include "Personagem.h"
#include "Fase.h"

Personagem::Personagem(Vector2f p, Vector2f tam_cx, int h, float v):
Entidade(p, tam_cx),
tipo(1),
hp(h),
vel(v)
{
}

Personagem::~Personagem()
{
}

void Personagem::dano(int d)
{
    hp -= d;
    if (hp <= 0)
    {
        pfase->rm_ent(static_cast<Entidade*>(this));
    }
}
