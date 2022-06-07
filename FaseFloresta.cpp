#include "FaseFloresta.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

FaseFloresta::FaseFloresta(RenderWindow* j, GerenciadorGrafico* pgg):
    Fase(j, pgg),
    camarada(),
    chefao(&camarada),
    militar(&camarada),
    plataforma(Vector2f(0.f, WINDOW_SIZEY-70), "imagens/Plataforma.png"),
    mina1()
{
    inicializa ();
}

FaseFloresta::~FaseFloresta()
{
}

/*===================================================================*/

/*==================INICIALIZA=========================*/


void FaseFloresta:: inicializa ()
{

    lista_ent.push_back(static_cast<Entidade*>(&camarada));
    lista_ent.push_back(static_cast<Entidade*>(&chefao));
    lista_ent.push_back(static_cast<Entidade*>(&militar));
    //lista_obst.push_back(&lama1);
    lista_ent.push_back(static_cast<Entidade*>(&plataforma));
    lista_obst.push_back(&mina1);


    camarada.setJanela(janela);
    chefao.setJanela(janela);
    militar.setJanela(janela);
    plataforma.setJanela(janela);
    lama1.setJanela(janela);
    mina1.setJanela(janela);


    camarada.set_fase(static_cast<Fase*>(this));
    chefao.set_fase(static_cast<Fase*>(this));
    plataforma.set_fase(static_cast<Fase*>(this));
    lama1.set_fase(static_cast<Fase*>(this));
    militar.set_fase(static_cast<Fase*>(this));
    mina1.set_fase(static_cast<Fase*>(this));

}
/*===================================================================*/
