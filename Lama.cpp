#include "Lama.h"

Lama::Lama():
 Obstaculo(Vector2f(0, WINDOW_SIZEY-75), Vector2f(100, 5))
{
    srand(time(NULL));
    int rand_x = rand()%(WINDOW_SIZEX-100);
    caixa.setPosition(Vector2f(rand_x, WINDOW_SIZEY-75));
    caixa.setFillColor(Color::Magenta);
}

Lama::~Lama()
{
}