#pragma once

#include "Obstaculo.h"


class Mina : public Obstaculo
{
    private:

        int dano;

    public:

        //construtora e destrutora
        Mina(int d = 10);
        ~Mina();

        //Funcoes
        void aplica_efeito (Entidade* ent);





};


