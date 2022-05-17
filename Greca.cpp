#include "Greca.h"
Greca::Greca(Greg* g):
Entidade(Vector2f(WINDOW_SIZEX - 200.f, WINDOW_SIZEY - 400.f), Vector2f(200.f, 200.f), 100), 
vel(0.3),
vel_pulo(0)
{ 
    caixa.setFillColor(Color::Red);
    greg = g;
}
Greca::~Greca()
{
}
void Greca::move()
{
    if (pos.x < greg->get_pos().x)
    {
        caixa.move(Vector2f(vel*0.1f, 0.f));
        pos.x += vel*0.1f;
        estado = 'd';
    }    
    else if (pos.x > greg->get_pos().x)
    {
        caixa.move(Vector2f(-vel*0.1f, 0.f));
        pos.x -= vel*0.1f;
        estado = 'e';
    }
    caixa.move(Vector2f(0.f, -vel_pulo*0.1f));
    pos.y -= vel_pulo*0.1;
    vel_pulo -= 0.002;
    if (caixa.getPosition().y > WINDOW_SIZEY-200)
        vel_pulo = 0;
}