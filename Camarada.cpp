#include "Camarada.h"
#include "Jogo.h"
#include <iostream>

using namespace std;


/*==================CONSTRUTORA E DESTRUTORA=========================*/

Camarada::Camarada():
Jogador(Vector2f(0.f, WINDOW_SIZEY-200), "imagens/Camarada.png", 50000, 1),
nvl_Camarada(10)
{

}

Camarada::~Camarada(){}


/*===================================================================*/

/*==============================GETS================================*/

Sprite Camarada:: get_caixa(){

    return caixa;
}

const Vector2f Camarada:: get_pos(){

    return pos;
}
/*===================================================================*/


