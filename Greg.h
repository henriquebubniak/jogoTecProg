#pragma once
#include "Jogador.h"
#include <list>
using namespace std;
class Greg: public Jogador
{
private:
    int nvl_greg;
public:
    Greg();
    ~Greg();
    RectangleShape get_caixa() {return caixa;}
    const Vector2f get_pos() { return pos; }
    void testa_colisao (Entidade* ent);
};