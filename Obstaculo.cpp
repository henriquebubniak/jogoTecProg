#include "Obstaculo.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Obstaculo::Obstaculo(Vector2f pos, Vector2f dim):
Entidade(pos, dim)
{
    caixa.setColor(Color::Yellow);
}

Obstaculo::~Obstaculo()
{
}

/*===================================================================*/
