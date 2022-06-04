#pragma once
#include <SFML/Graphics.hpp>
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

    RectangleShape caixa;
    RenderWindow* janela;

    Fase* pfase;


public:

    //construtora e Destrutora
    Entidade(Vector2f p = Vector2f(0.f, 0.f), Vector2f tam_cx = Vector2f(100.f, 100.f), Fase* f = NULL);
    virtual ~Entidade();

    //Fun��es
    void imprime();
    void setJanela(RenderWindow* j = NULL);
    virtual void testa_colisao (Entidade* ent);

    //virtuais puras
    virtual void move() = 0;
    virtual void ataca() = 0;
    virtual void dano(int d) = 0;


    //gets
    Vector2f get_dim() { return dim; }
    Vector2f get_pos() { return pos; }
    Vector2f get_velocidade (){return velocidade;}
    FloatRect get_GlobalBounds() { return caixa.getGlobalBounds(); }
    RenderWindow* get_janela (){return janela;}
    RectangleShape get_caixa (){return caixa;}

    //sets
    void set_fase(Fase* f) { pfase = f; }
    void set_velocidade_x(float x){velocidade.x = x;}
    void set_velocidade_y(float y){velocidade.y = y;}
    void set_pos_caixa (Vector2f pos){caixa.setPosition(pos);}
    virtual void set_podepular (bool p) {};
};




