#include "FaseDeserto.h"
/*==================CONSTRUTORA E DESTRUTORA=========================*/

FaseDeserto::FaseDeserto(GerenciadorGrafico* pgg):
    Fase(pgg),
    camarada(),
    chefao(&camarada),
    //militar1(&camarada),
    militar2(&camarada),
    plataforma(Vector2f(0.f, WINDOW_SIZEY-70), "imagens/plataformaDeserto.png"),
    plataforma2(Vector2f(1500.f, WINDOW_SIZEY-500), "imagens/pltDeserto.png"),
    mina1(),
    barril()
{
    inicializa ();
}

FaseDeserto::~FaseDeserto()
{
}

/*===================================================================*/

/*==================INICIALIZA=========================*/


void FaseDeserto:: inicializa ()
{
    srand(time(NULL));
    vector<Vector2f> posicoes_m1;
    posicoes_m1.push_back(Vector2f(WINDOW_SIZEX - 500.f, WINDOW_SIZEY - 500.f));
    posicoes_m1.push_back(Vector2f(WINDOW_SIZEX - 700.f, WINDOW_SIZEY - 700.f));
    posicoes_m1.push_back(Vector2f(WINDOW_SIZEX - 1000.f, WINDOW_SIZEY - 900.f));
    posicoes_m1.push_back(Vector2f(WINDOW_SIZEX - 1300.f, WINDOW_SIZEY - 1100.f));

    int n_militares1 = 0;
    int n_militares2 = 0;
    Militar1* auxmilitar1;
    n_militares1 = rand() % 2 + 3;
    n_militares2 = rand() & 2 + 3;

    for (int i = 0; i < n_militares1; i++)
    {
        auxmilitar1 = new Militar1(&camarada);
        auxmilitar1->set_pos_caixa(posicoes_m1[i]);
        lista_ent.push_back(static_cast<Entidade*>(auxmilitar1));
        auxmilitar1->set_pGG(pGerenciadorGrafico);
        auxmilitar1->set_fase(static_cast<Fase*>(this));
    }

    lista_ent.push_back(static_cast<Entidade*>(&camarada));
    lista_ent.push_back(static_cast<Entidade*>(&chefao));
    //lista_ent.push_back(static_cast<Entidade*>(&militar1));
    lista_ent.push_back(static_cast<Entidade*>(&militar2));
    lista_obst.push_back(&barril);
    lista_ent.push_back(static_cast<Entidade*>(&barril));
    lista_ent.push_back(static_cast<Entidade*>(&plataforma));
    lista_ent.push_back(static_cast<Entidade*>(&plataforma2));
    lista_obst.push_back(&mina1);

    camarada.set_pGG(pGerenciadorGrafico);
    chefao.set_pGG(pGerenciadorGrafico);
    //militar1.set_pGG(pGerenciadorGrafico);
    militar2.set_pGG(pGerenciadorGrafico);
    barril.set_pGG(pGerenciadorGrafico);
    plataforma.set_pGG(pGerenciadorGrafico);
    plataforma2.set_pGG(pGerenciadorGrafico);
    mina1.set_pGG(pGerenciadorGrafico);


    camarada.set_fase(static_cast<Fase*>(this));
    chefao.set_fase(static_cast<Fase*>(this));
    plataforma.set_fase(static_cast<Fase*>(this));
    plataforma2.set_fase(static_cast<Fase*>(this));
    barril.set_fase(static_cast<Fase*>(this));
    //militar1.set_fase(static_cast<Fase*>(this));
    militar2.set_fase(static_cast<Fase*>(this));
    mina1.set_fase(static_cast<Fase*>(this));

}
/*===================================================================*/
