#include "Jogo.h"

//Static
float Jogo::gravidade = 10.0;

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Jogo::Jogo(/* args */):
    janela(VideoMode(WINDOW_SIZEX, WINDOW_SIZEY), "GREG"),
    floresta(&janela),
    menu(&janela)
{
    janela.setPosition(Vector2i(0.f, 0.f));
    janela.setFramerateLimit(120);

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
