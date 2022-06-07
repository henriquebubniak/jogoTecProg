#include "Obstaculo.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Obstaculo::Obstaculo(Vector2f pos, const char* caminhoTextura,  bool t):
Entidade(pos, caminhoTextura)
{
    tipo = t;
    posicoes_padrao.push_back(Vector2f(WINDOW_SIZEX - 1000, WINDOW_SIZEY-75));
    posicoes_padrao.push_back(Vector2f(WINDOW_SIZEX - 1500, WINDOW_SIZEY-75));

}

Obstaculo::~Obstaculo()
{
}

/*===================================================================*/

bool Obstaculo:: get_tipo(){

    return tipo;

}
