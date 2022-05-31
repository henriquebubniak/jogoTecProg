#include "Menu.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Menu::Menu(RenderWindow* j):
janela(j)
{
    set_valores();
}

Menu::~Menu()
{
}

/*===================================================================*/

/*==================SETS E GETS=========================*/
void Menu::set_valores()
{
    pos = 0;
    clicou = false;
    enter = false;
    fonte.loadFromFile("./fontes/Wargate-Normal.otf");
    imagem.loadFromFile("./imagens/menu.png");
    sprite.setTexture(imagem);
    pos_mouse = Vector2f(0.f, 0.f);
}
