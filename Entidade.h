#pragma once
#include <SFML/Graphics.hpp>
#define WINDOW_SIZEX 2000
#define WINDOW_SIZEY 1000
using namespace sf;
class Entidade
{
protected:
    Vector2f pos;
    Vector2f dim;
    Vector2f velocidade;
    RectangleShape caixa;
    RenderWindow* janela;
    int hp;
    char estado;
public:
    Entidade(Vector2f p = Vector2f(0.f, 0.f), Vector2f tam_cx = Vector2f(100.f, 100.f), int h = 10);
    ~Entidade();
    void imprime();
    void setJanela(RenderWindow* j = NULL) { janela = j; }
    virtual void move() = 0;
    void testa_colisao (Entidade* ent);
    Vector2f get_dim() { return dim; }
    Vector2f get_pos() { return pos; }
};




