#include "Personagem.h"
#include "Fase.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Personagem::Personagem(Vector2f p, const char* caminhoTextura, int h, float v):
    Entidade(p, caminhoTextura),
    tipo(1),
    hp(h),
    vel(v),
    vel_max(vel),
    vel_slow(vel/2.0)
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
        pGerenciadorGrafico->removeEnte(static_cast<Ente*>(this));
    }
    velocidade = Vector2f(0.f, 0.f);
}

/*===================================================================*/


/*==============================DANO================================*/

void Personagem:: set_podepular (bool p){

    pode_pular = p;
}

void Personagem::set_slowpersonagem()
{
    vel = vel_slow;
}

void Personagem::set_velmaxpersonagem()
{
    vel = vel_max;
}
/*===================================================================*/
