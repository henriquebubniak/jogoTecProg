#include "Camarada.h"
#include "Jogo.h"
#include <iostream>

using namespace std;


/*==================CONSTRUTORA E DESTRUTORA=========================*/

Camarada::Camarada():
Jogador(Vector2f(0.f, WINDOW_SIZEY-200), Vector2f(40.f,56.f), 10, 1),
nvl_Camarada(10)
{
    imagem.loadFromFile("./imagens/Camarada.png");
    caixa.setTexture(imagem);
}

Camarada::~Camarada(){}


/*===================================================================*/

/*==============================GETS================================*/


const Vector2f Camarada:: get_pos(){

    return pos;
}
/*===================================================================*/


