#include "Greca.h"
#include "Jogo.h"
Greca::Greca(Greg* g):
Inimigo(Vector2f(WINDOW_SIZEX - 200.f, WINDOW_SIZEY - 400.f), Vector2f(200.f, 200.f), 100, 0.3)
{ 
    caixa.setFillColor(Color::Red);
    greg = g;
}
Greca::~Greca()
{
}
void Greca::move()
{
    if (caixa.getPosition().x < greg->get_pos().x)
    {
        velocidade.x += 0.01;
    }    
    else if (caixa.getPosition().x > greg->get_pos().x)
    {
        velocidade.x -= 0.01;
    }
    if (velocidade.x > 0.07)
        velocidade.x = 0.07;
    else if (velocidade.x < -0.07)
        velocidade.x = -0.07;
    caixa.move(velocidade);
    velocidade.y += Jogo::get_g() * 0.001;
}