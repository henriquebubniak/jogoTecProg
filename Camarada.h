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
    const Vector2f get_pos();
};
