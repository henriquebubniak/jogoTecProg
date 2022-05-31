#include "Jogador.h"
#include "Jogo.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Jogador::Jogador(Vector2f p, Vector2f tam_cx, int h, float v):
    Personagem(p, tam_cx, h, v)
{
}

Jogador::~Jogador()
{
}

/*===================================================================*/

/*========================MOVE===================================*/

void Jogador::move()
{
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        velocidade.x += vel;
    }
    else if (Keyboard::isKeyPressed(Keyboard::A))
    {
        velocidade.x -= vel;
    }
    else
        velocidade.x -= velocidade.x*0.1;
    if (Keyboard::isKeyPressed(Keyboard::Space) && pode_pular)
    {
        velocidade.y = -7*vel;
    }
    if (velocidade.x > 2)
        velocidade.x = 2;
    if (velocidade.x < -2)
        velocidade.x = -2;
    caixa.move(velocidade);
    velocidade.y += Jogo::get_g() * (0.016);
    pos = caixa.getPosition();
    cout << Jogo::get_g() * (0.016) << "vel.y: " << velocidade.y << endl;
    pode_pular = false;
}

/*===================================================================*/

/*==================CONSTRUTORA E DESTRUTORA=========================*/

void Jogador::ataca()
{
    if (Keyboard::isKeyPressed(Keyboard::F) && pode_atirar)
    {
        if (velocidade.x >= 0)
        {
            Projetil* proj = new Projetil(7, Vector2f(caixa.getPosition().x + dim.x + 1, caixa.getPosition().y), Vector2f(10.f, 10.f), 20.f);
            pfase->ad_proj(proj);
            proj->set_fase(pfase);
            proj->setJanela(janela);
        }
        else if (velocidade.x < 0)
        {

            Projetil* proj = new Projetil(7, Vector2f(caixa.getPosition().x - dim.x - 1, caixa.getPosition().y), Vector2f(10.f, 10.f), -20.f);
            pfase->ad_proj(proj);
            proj->set_fase(pfase);
            proj->setJanela(janela);
        }
        pode_atirar = false;
    }

    else if (!(Keyboard::isKeyPressed(Keyboard::F)))
        pode_atirar = true;
}

/*===================================================================*/
