#include "Mina.h"

Mina::Mina(int d):
    Obstaculo(Vector2f(0, WINDOW_SIZEY-75), "imagens/mina.png", false)
{
    srand(time(NULL));
    int rand_x = rand()% (WINDOW_SIZEX-100);
    caixa.setPosition(Vector2f(rand_x, WINDOW_SIZEY-75));

    dano = d;

}

Mina::~Mina()
{

}

void Mina:: aplica_efeito(Entidade* ent){

        ent->dano(dano);



        ent->set_velocidade_y(-10.0f);

}
