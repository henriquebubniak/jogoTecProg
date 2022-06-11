#pragma once

#include "Obstaculo.h"

using namespace sf;

class Barril: public Obstaculo {

private:

public:

    Barril (Vector2f pos = Vector2f(200, WINDOW_SIZEY - 150));
    ~Barril ();

    void aplica_efeito(Entidade *ent);

};
