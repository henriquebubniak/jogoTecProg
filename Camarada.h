#pragma once
#include "Jogador.h"
#include <list>
using namespace std;
class Camarada: public Jogador
{
private:
    int nvl_Camarada;

public:

    //const destr
    Camarada();
    ~Camarada();

    //Fun��es
    RectangleShape get_caixa();
    const Vector2f get_pos();
    void testa_colisao (Entidade* ent);
};
