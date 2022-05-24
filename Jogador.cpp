#include "Jogador.h"
#include "Jogo.h"
Jogador::Jogador(Vector2f p, Vector2f tam_cx, int h, float v):
Personagem(p, tam_cx, h, v)
{
}

Jogador::~Jogador()
{
}

void Jogador::move()
{
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        velocidade.x += 0.01*vel;
    }    
    else if (Keyboard::isKeyPressed(Keyboard::A))
    {
        velocidade.x -= 0.01*vel;
    }
    else
        velocidade.x -= velocidade.x*0.1;
    if (Keyboard::isKeyPressed(Keyboard::Space) && pode_pular)
    {
        velocidade.y = -2*vel;
    }
    //if (Keyboard::isKeyPressed(Keyboard::F))
    //{
        ataca();
    //}
    if (velocidade.x > 0.3)
        velocidade.x = 0.3;
    if (velocidade.x < -0.3)
        velocidade.x = -0.3;
    caixa.move(velocidade);   
    velocidade.y += Jogo::get_g() * (0.001);
    pos = caixa.getPosition();
    cout << Jogo::get_g() * (0.001) << "vel.y: " << velocidade.y << endl;
    pode_pular = false;
}
void Jogador::ataca()
{
    if (velocidade.x > 0)
    {
        Projetil* proj = new Projetil(7, Vector2f(caixa.getPosition().x + dim.x, caixa.getPosition().y), 
                                                                             Vector2f(10.f, 10.f), 0.1);
        p_lista_ent->push_back(static_cast<Entidade*>(proj));
                                      
    }
}