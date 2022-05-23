#pragma once
#include "Personagem.h"
#include <iostream>
using namespace std;
class Jogador: public Personagem
{
protected:
public:
    Jogador(Vector2f p = Vector2f(0.f, 0.f), Vector2f tam_cx = Vector2f(100.f, 100.f), int h = 10, float v = 1);
    ~Jogador();
    virtual void move();
};
