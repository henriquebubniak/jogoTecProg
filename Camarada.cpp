#include "Camarada.h"
#include "Jogo.h"
#include <iostream>

using namespace std;


/*==================CONSTRUTORA E DESTRUTORA=========================*/

Camarada::Camarada():
Jogador(Vector2f(0.f, WINDOW_SIZEY-200), Vector2f(40.f,80.f), 10, 1),
nvl_Camarada(10)
{
    caixa.setFillColor(Color::White);
}

Camarada::~Camarada(){}


/*===================================================================*/

/*==============================GETS================================*/

RectangleShape Camarada:: get_caixa(){

    return caixa;
}

const Vector2f Camarada:: get_pos(){

    return pos;
}
/*===================================================================*/


