#include "Jogo.h"

//Static
float Jogo::gravidade = 10.0;

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Jogo::Jogo(/* args */):
    floresta(&gg),
    menu(&gg),
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