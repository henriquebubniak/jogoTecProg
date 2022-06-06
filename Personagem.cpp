#include "Personagem.h"
#include "Fase.h"
#include <iostream>

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Personagem::Personagem(Vector2f p, Vector2f tam_cx, int h, float v):
    Entidade(p, tam_cx),
    tipo(1),
    hp(h),
    vel(v),
    vel_slow(vel/2.0),
    vel_max(vel)
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


/*==============================SETS================================*/

void Personagem:: set_podepular (bool p){

    pode_pular = p;
}

void Personagem::set_slowpersonagem ()
{
    vel = vel_slow;  
    std::cout << vel << endl; 
}
void Personagem::set_velmaxpersonagem()
{
    vel = vel_max;
}

/*===================================================================*/
