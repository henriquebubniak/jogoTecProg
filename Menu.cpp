#include "Menu.h"

bool bfloresta (Vector2f v, Vector2i i);

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
    pos = 1;
    clicou = false;
    enter = false;
    fonte.loadFromFile("./fontes/Wargate-Normal.otf");
    imagem.loadFromFile("./imagens/menu.png");
    bg.setTexture(imagem);
    pos_mouse = Vector2f(0, 0);
    nomes_botoes.push_back("GREGVENTURES");
    nomes_botoes.push_back("FLORESTA");
    pos_botoes.push_back(Vector2f(1400.f, 70.f));
    pos_botoes.push_back(Vector2f(1400.f, 400.f));
    tam_fontes.push_back(60);
    tam_fontes.push_back(80);
    textos.resize(2);
    for (int i = 0; i < textos.size(); i++)
    {
        textos[i].setFont(fonte);
        textos[i].setString(nomes_botoes[i]);
        textos[i].setCharacterSize(tam_fontes[i]);
        textos[i].setOutlineColor(Color::Black);
        textos[i].setPosition(pos_botoes[i]);
    }
    textos[1].setOutlineThickness(5.0);
}

/*===================================================================*/

/*===========================LOOP EVENTOS============================*/

void Menu::loop_eventos()
{
    Vector2i pos_mouse_aux;
    FaseFloresta* faseflor = NULL;
    pos_mouse_aux = Mouse::getPosition();
    pos_mouse = janela->mapPixelToCoords(pos_mouse_aux);
    FloatRect botao_floresta;
    botao_floresta.left = 894.f;
    botao_floresta.top = 244.f;
    botao_floresta.width = 292.f;
    botao_floresta.height = 92.f;
    while (janela->isOpen())
    {
        Event event;
        while (janela->pollEvent(event))
            if (event.type == Event::Closed)
                janela->close();
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            pos++;
            textos[pos].setOutlineThickness(5);
            textos[pos].setOutlineColor(Color::Red);
            textos[pos - 1].setOutlineThickness(1);
            textos[pos - 1].setOutlineColor(Color::Black);
        }
        if (/*Keyboard::isKeyPressed(Keyboard::Enter) &&*/ pos == 1)
        {
            faseflor = new FaseFloresta(janela);
            faseflor->executa_fase();
        }
        imprime();
    }
}

/*===================================================================*/

/*============================IMPRIME================================*/

void Menu::imprime()
{
    janela->clear();
    janela->draw(bg);
    for (int i = 0; i < textos.size(); i++)
        janela->draw(textos[i]);
    janela->display();
}

/*===================================================================*/

/*============================EXECUTA================================*/

void Menu::executa_menu()
{
    loop_eventos();
}

bool bfloresta (Vector2f v, Vector2i i)
{
    v = Vector2f(0.f, 0.f);
    cout << v.x << ", " << v.y << endl;
    cout << i.x << ", " << i.y << endl;
    /*if (v.x > 894 && v.y > 664 && v.x < 1186 && v.y < 756)
    {
        cout << "true" << endl;*/
        return false;
    /*}
    else
    {
        cout << "false" << endl;
        return false;
    }*/
}
