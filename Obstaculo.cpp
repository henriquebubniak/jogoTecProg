#include "Obstaculo.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Obstaculo::Obstaculo(Vector2f pos, const char* caminhoTextura,  bool tipo):
Entidade(pos, caminhoTextura)
{

}

Obstaculo::~Obstaculo()
{
}

/*===================================================================*/

bool Obstaculo:: get_tipo(){

    return tipo;

}
