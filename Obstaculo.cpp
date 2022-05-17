#include "Obstaculo.h"
Obstaculo::Obstaculo(Vector2f pos, Vector2f dim):
Entidade(pos, dim)
{
    caixa.setFillColor(Color::Green);
}

Obstaculo::~Obstaculo()
{
}
