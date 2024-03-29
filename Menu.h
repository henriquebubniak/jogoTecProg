#pragma once

#include "FaseFloresta.h"
class Jogo;
class Menu: public Ente
{
private:

    int pos;
    bool apertado;
    bool enter;

    GerenciadorGrafico* pGerenciadorGrafico;
    Font fonte;
    Ente planoDeFundo;
    Vector2f pos_mouse;
    Jogo* jogo;

    std::vector<string> nomes_botoes;
    std::vector<Vector2f> pos_botoes;
    std::vector<Text> textos;
    std::vector<std::size_t> tam_fontes;

public:

    //construtora e destrutora
    Menu(GerenciadorGrafico* pgg, Jogo* j);
    ~Menu();

    //metodos
    void loop_eventos();
    void imprime();
    void executa_menu();

    //sets
    void set_valores();

};
