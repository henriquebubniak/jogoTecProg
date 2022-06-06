#pragma once

#include "Obstaculo.h"

class Lama: public Obstaculo
{
private:
    /* data */
public:
    Lama();
    ~Lama();
    void aplica_efeito(Entidade* ent);
};


