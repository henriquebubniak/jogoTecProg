#include "Menu.h"
#include "Jogo.h"


/*==================CONSTRUTORA E DESTRUTORA=========================*/

Menu::Menu(GerenciadorGrafico* pgg, Jogo* j):
pGerenciadorGrafico(pgg),
jogo(j),
planoDeFundo("./imagens/menu.png")
{
    set_valores();
    planoDeFundo.set_pGG(pgg);
    pGerenciadorGrafico->incluiEnte(&planoDeFundo);
    pGerenciadorGrafico->incluiTexto(&textos);
}

Menu::~Menu()
{
}

/*===================================================================*/

/*==================SETS E GETS=========================*/
void Menu::set_valores()
{
    pos = 1;
    apertado = false;
    enter = false;
    fonte.loadFromFile("./fontes/Wargate-Normal.otf");
    pos_mouse = Vector2f(0, 0);
    nomes_botoes.push_back("GREGVENTURES");
    nomes_botoes.push_back("FLORESTA");
    nomes_botoes.push_back("DESERTO");
    pos_botoes.push_back(Vector2f(1400.f, 70.f));
    pos_botoes.push_back(Vector2f(1400.f, 400.f));
    pos_botoes.push_back(Vector2f(1400.f, 570.f));
    tam_fontes.push_back(60);
    tam_fontes.push_back(80);
    tam_fontes.push_back(80);
    textos.resize(3);
    for (int i = 0; i < textos.size(); i++)
    {
        textos[i].setFont(fonte);
        textos[i].setString(nomes_botoes[i]);
        textos[i].setCharacterSize(tam_fontes[i]);
        textos[i].setOutlineColor(Color::Black);
        textos[i].setPosition(pos_botoes[i]);
    }
    textos[1].setOutlineThickness(5.0);
    textos[1].setOutlineColor(Color::Red);
}

/*===================================================================*/

/*===========================LOOP EVENTOS============================*/

void Menu::loop_eventos()
{
    Vector2i pos_mouse_aux;
    FaseFloresta* faseflor = NULL;
    while (pGerenciadorGrafico->get_JanelaAberta())
    {
        Event event;
        while (pGerenciadorGrafico->pega_evento(&event))
            if (event.type == Event::Closed)
                pGerenciadorGrafico->fecha_janela();
        if (Keyboard::isKeyPressed(Keyboard::Down) && !apertado && pos < 2)
        {
            pos++;
            textos[pos].setOutlineThickness(5);
            textos[pos].setOutlineColor(Color::Red);
            textos[pos - 1].setOutlineThickness(1);
            textos[pos - 1].setOutlineColor(Color::Black);
            apertado = true;
        }
        else if (!Keyboard::isKeyPressed(Keyboard::Down))
        {
            apertado = false;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up) && !apertado && pos > 1)
        {
            pos--;
            textos[pos].setOutlineThickness(5);
            textos[pos].setOutlineColor(Color::Red);
            textos[pos + 1].setOutlineThickness(1);
            textos[pos + 1].setOutlineColor(Color::Black);
            apertado = true;
        }
        else if (!Keyboard::isKeyPressed(Keyboard::Down))
        {
            apertado = false;
        }
        if (Keyboard::isKeyPressed(Keyboard::Enter) && pos == 1)
        {
            jogo->executa_fase_floresta();
        }
        if (Keyboard::isKeyPressed(Keyboard::Enter) && pos == 2)
        {
            jogo->executa_fase_deserto();
        }
        pGerenciadorGrafico->incluiTexto(&textos);
        imprime();
    }
}

/*===================================================================*/

/*============================IMPRIME================================*/

void Menu::imprime()
{
    pGerenciadorGrafico->atualizaJanela();
}

/*===================================================================*/

/*============================EXECUTA================================*/

void Menu::executa_menu()
{
    loop_eventos();
}

