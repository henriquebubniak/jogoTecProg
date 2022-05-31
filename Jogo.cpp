#include "Jogo.h"

//Static
float Jogo::gravidade = 10.0;

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Jogo::Jogo(/* args */):
    janela(VideoMode(WINDOW_SIZEX, WINDOW_SIZEY), "GREG"),
    floresta(&janela)
{
    janela.setFramerateLimit(120);

    /*while (janela.isOpen())
    {
        Event event;
        while (janela.pollEvent(event))
            if (event.type == Event::Closed)
                janela.close();

        floresta.move_ents();
        floresta.ataca_ents();
        floresta.testa_colisao();
        janela.clear();
        floresta.imprime_ents();
        janela.display();


    }*/
    floresta.executa_fase();
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
