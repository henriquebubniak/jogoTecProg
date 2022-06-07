#include "Militar2.h"
#include "Jogo.h"

Militar2::Militar2(Camarada* g):
Inimigo(Vector2f(WINDOW_SIZEX - 500.f, WINDOW_SIZEY - 200.f), "imagens/Militar2.png", 10, 1.2, g)
{
    camarada = g;
}

Militar2::~Militar2()
{
}

void Militar2::move()
{
    if (caixa.getPosition().x < camarada->get_pos().x)
    {
        velocidade.x += vel*0.01;
    }
    else if (caixa.getPosition().x > camarada->get_pos().x)
    {
        velocidade.x -= vel*0.01;
    }
    if (velocidade.x > vel*2)
        velocidade.x = vel*2;
    else if (velocidade.x < -vel*2)
        velocidade.x = -vel*2;
    caixa.move(velocidade);
    velocidade.y += Jogo::get_g() * 0.016;
    cout << "MILITAR@ VIVO" << endl;
}

void Militar2:: ataca()
{  
    FloatRect area_ataque = caixa.getGlobalBounds();
    area_ataque.left -= 20;
    area_ataque.top += 20;
    area_ataque.width += 40;
    area_ataque.height += 40;

    if (area_ataque.intersects(camarada->get_GlobalBounds()) && (pfase->get_tempo() - auxt) > 1000)
    {     
        camarada->dano(5);   
        auxt = pfase->get_tempo();
    }
}