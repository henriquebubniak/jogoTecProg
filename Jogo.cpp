#include "Jogo.h"

//Static
float Jogo::gravidade = 10.0;

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Jogo::Jogo(/* args */):
    floresta(&gg),
    deserto(&gg),
    menu(&gg, this),
    gg()
{

    menu.executa_menu();
}

Jogo::~Jogo()
{
}

/*===================================================================*/


/*==================GETS=========================*/

float Jogo::get_g(){

    return gravidade;
}

/*===================================================================*/

void Jogo::executa_fase_floresta()
{
    floresta.executa_fase();
}

void Jogo::executa_fase_deserto()
{
    deserto.executa_fase();
}