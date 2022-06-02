#include "Personagem.h"
#include "Fase.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

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

/*===================================================================*/

/*==============================DANO================================*/

void Personagem::dano(int d)
{
    hp -= d;
    if (hp <= 0)
    {
        pfase->rm_ent(static_cast<Entidade*>(this));
    }
    velocidade = Vector2f(0.f, 0.f);
}

/*===================================================================*/


/*==============================DANO================================*/

void Personagem:: set_podepular (bool p){

    pode_pular = p;
}

/*===================================================================*/
