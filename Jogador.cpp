#include "Jogador.h"
#include "Jogo.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Jogador::Jogador(Vector2f p, const char* caminhoTextura, int h, float v):
    Personagem(p, caminhoTextura, h, v),
    pode_atirar(true),
    auxt(0),
    tiros_tambor(6)
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
        velocidade.x += vel*0.1;
    }
    else if (Keyboard::isKeyPressed(Keyboard::A))
    {
        velocidade.x -= vel*0.1;
    }
    else
        velocidade.x -= velocidade.x*0.1;
    if (Keyboard::isKeyPressed(Keyboard::Space) && pode_pular)
    {
        velocidade.y = -7*vel;
    }
    if (velocidade.x > 2*vel)
        velocidade.x = 2*vel;
    if (velocidade.x < -2*vel)
        velocidade.x = -2*vel;
    caixa.move(velocidade);
    velocidade.y += Jogo::get_g() * (0.016);
    pos = caixa.getPosition();
    //cout << Jogo::get_g() * (0.016) << "vel.y: " << velocidade.y << endl;
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
            Projetil* proj = new Projetil(7, Vector2f(caixa.getPosition().x +  41, caixa.getPosition().y + 15), "imagens/projetil.png", 20.f);
            pfase->ad_proj(proj);
            proj->set_fase(pfase);
            proj->setJanela(janela);
        }
        else if (velocidade.x < 0)
        {

            Projetil* proj = new Projetil(7, Vector2f(caixa.getPosition().x - 1, caixa.getPosition().y + 15), "imagens/projetil.png", -20.f);
            pfase->ad_proj(proj);
            proj->set_fase(pfase);
            proj->setJanela(janela);
        }
        pode_atirar = false;
        auxt = pfase->get_tempo();
        tiros_tambor--;
    }

    else if ((pfase->get_tempo() - auxt) > 300.0 && !Keyboard::isKeyPressed(Keyboard::F))
    {
        if (tiros_tambor <= 0 && (pfase->get_tempo() - auxt) > 2000.0)
        {
            pode_atirar = true;
            tiros_tambor = 6;
        }
        if (tiros_tambor > 0)
            pode_atirar = true;
    }
}

/*===================================================================*/
