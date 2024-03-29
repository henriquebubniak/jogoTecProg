#include "Inimigo.h"
#include "Fase.h"
#include "Jogo.h"
#include <math.h>

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Inimigo::Inimigo(Vector2f p, const char* caminhoTextura, int h, float v, Camarada* c):
Personagem(p, caminhoTextura, h, v),
pode_atirar(true),
auxt(0.f),
tiros_tambor(6),
cam(c)
{
}

Inimigo::~Inimigo()
{
}

/*===================================================================*/

/*==============================FUNCOES==============================*/

void Inimigo::ataca()
{
    Vector2f aux_tiro = Vector2f(cam->get_pos().x - caixa.getPosition().x, cam->get_pos().y + 30 - caixa.getPosition().y);
    float mod = sqrt(aux_tiro.x*aux_tiro.x + aux_tiro.y*aux_tiro.y);
    aux_tiro.x = aux_tiro.x*20.0/mod;
    aux_tiro.y = aux_tiro.y*20.0/mod;
    if (pode_atirar)
    {

        if (velocidade.x >= 0)
        {
            Projetil* proj = new Projetil(10, Vector2f(caixa.getPosition().x + dim.x + 1, caixa.getPosition().y), "imagens/projetild.png", aux_tiro.x, aux_tiro.y);
            pfase->ad_proj(proj);
            proj->set_fase(pfase);
            proj->set_pGG(pGerenciadorGrafico);
            pGerenciadorGrafico->incluiEnte(static_cast<Ente*>(proj));
        }
        else if (velocidade.x < 0)
        {

            Projetil* proj = new Projetil(10, Vector2f(caixa.getPosition().x - 21, caixa.getPosition().y),"imagens/projetile.png", aux_tiro.x, aux_tiro.y - (abs(cam->get_pos().x - caixa.getPosition().x)/WINDOW_SIZEX) );
            pfase->ad_proj(proj);
            proj->set_fase(pfase);
            proj->set_pGG(pGerenciadorGrafico);
            pGerenciadorGrafico->incluiEnte(static_cast<Ente*>(proj));
        }
        pode_atirar = false;
        auxt = pfase->get_tempo();
        tiros_tambor--;
    }

    else if ((pfase->get_tempo() - auxt) > 1000.0)
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
