#include "Lama.h"

Lama::Lama():
 Obstaculo(Vector2f(0, WINDOW_SIZEY-75), "imagens/Lama.png", true)
{
    srand(time(NULL));
    int rand_x = rand()%(WINDOW_SIZEX-100);
    caixa.setPosition(posicoes_padrao[0]);
}

Lama::~Lama()
{
}


void Lama::aplica_efeito(Entidade* ent)
{
    ent->set_slowpersonagem();

}
