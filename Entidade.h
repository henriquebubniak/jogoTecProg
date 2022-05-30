#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#define WINDOW_SIZEX 2000
#define WINDOW_SIZEY 1000
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

    //bool podepular;

public:
    Entidade(Vector2f p = Vector2f(0.f, 0.f), Vector2f tam_cx = Vector2f(100.f, 100.f), Fase* f = NULL);
    virtual ~Entidade();
    void imprime();
    void setJanela(RenderWindow* j = NULL) { janela = j; }
    virtual void move() = 0;
    virtual void testa_colisao (Entidade* ent);
    virtual void ataca() = 0;
    virtual void dano(int d) = 0;
    Vector2f get_dim() { return dim; }
    Vector2f get_pos() { return pos; }
    FloatRect get_GlobalBounds() { return caixa.getGlobalBounds(); }
    void set_fase(Fase* f) { pfase = f; }
    Vector2f get_velocidade (){return velocidade;}

    void set_velocidade_x(float x){velocidade.x = x;}
    void set_velocidade_y(float y){velocidade.y = y;}

    void set_pos_caixa (Vector2f pos){caixa.setPosition(pos);}

    virtual void set_podepular (bool p) {};
};




