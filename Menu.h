#pragma once

#include "FaseFloresta.h"
class Menu
{
private:

    int pos;
    bool clicou;
    bool enter;

    RenderWindow* janela;
    GerenciadorGrafico* pGerenciadorGrafico;
    Font fonte;
    Texture imagem;
    Sprite bg;
    Vector2f pos_mouse;

    std::vector<string> nomes_botoes;
    std::vector<Vector2f> pos_botoes;
    std::vector<Text> textos;
    std::vector<std::size_t> tam_fontes;

public:

    //construtora e destrutora
    Menu(RenderWindow* j, GerenciadorGrafico* pgg);
    ~Menu();

    //metodos
    void loop_eventos();
    void imprime();
    void executa_menu();

    //sets
    void set_valores();

};
