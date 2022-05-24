#include "Jogo.h"

float Jogo::gravidade = 7.0;
Jogo::Jogo(/* args */):
janela(VideoMode(WINDOW_SIZEX, WINDOW_SIZEY), "GREG"), 
floresta(&janela)
{
    
    while (janela.isOpen())
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
    }
}

Jogo::~Jogo()
{
}