#pragma once
#include "Jogador.h"
#include <list>
using namespace std;
class Greg: public Jogador
{
private:
    int nvl_greg;

public:

    //const destr
    Greg();
    ~Greg();

    //Fun��es
    RectangleShape get_caixa();
    const Vector2f get_pos();
    void testa_colisao (Entidade* ent);
};
