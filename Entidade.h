#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

#define WINDOW_SIZEX 3000
#define WINDOW_SIZEY 1500

using namespace std;
using namespace sf;

class Fase;

class Entidade
{
protected:

    Vector2f pos;
    Vector2f dim;
    Vector2f velocidade;

    Sprite caixa;
    Texture textura;
    RenderWindow* janela;

    Fase* pfase;


public:

    //construtora e Destrutora
    Entidade(Vector2f p = Vector2f(0.f, 0.f), const char* caminhoTextura = "imagens/padrao.png", Fase* f = NULL);
    virtual ~Entidade();

    //Fun��es
    void setJanela(RenderWindow* j = NULL);

    //virtuais puras
    virtual void move() = 0;
    virtual void ataca() = 0;
    virtual void dano(int d) = 0;


    //gets
    Vector2f get_dim();
    Vector2f get_pos();
    Vector2f get_velocidade ();
    FloatRect get_GlobalBounds();
    RenderWindow* get_janela ();
    Sprite get_caixa ();

    //sets
    void set_fase(Fase* f);
    void set_velocidade_x(float x);
    void set_velocidade_y(float y);
    void set_pos_caixa (Vector2f pos);
    virtual void set_podepular (bool p);
    virtual void set_slowpersonagem() {}
    virtual void set_velmaxpersonagem() {}
};




