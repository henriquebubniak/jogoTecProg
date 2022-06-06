#include "FaseFloresta.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

FaseFloresta::FaseFloresta(RenderWindow* j):
    Fase(j),
    camarada(),
    //chefao(&camarada),
    //militar(&camarada),
    chao(Vector2f(0.f, WINDOW_SIZEY-70), Vector2f(WINDOW_SIZEX, 70)),
    plataforma1(Vector2f(WINDOW_SIZEX / 2.0, WINDOW_SIZEY / 2.0 + 500), Vector2f(400, 70))
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
    //lista_ent.push_back(static_cast<Entidade*>(&chefao));
    //lista_ent.push_back(static_cast<Entidade*>(&militar));
    //lista_obst.push_back(&lama1);
    lista_ent.push_back(static_cast<Entidade*>(&chao));
    lista_ent.push_back(static_cast<Entidade*>(&plataforma1));


    camarada.setJanela(janela);
    //chefao.setJanela(janela);
    //militar.setJanela(janela);
    chao.setJanela(janela);
    plataforma1.setJanela(janela);
    //lama1.setJanela(janela);


    camarada.set_fase(static_cast<Fase*>(this));
    //chefao.set_fase(static_cast<Fase*>(this));
    chao.set_fase(static_cast<Fase*>(this));
    plataforma1.set_fase(static_cast<Fase*>(this));
    //lama1.set_fase(static_cast<Fase*>(this));
    //militar.set_fase(static_cast<Fase*>(this));

    geraInimigos1();

}
/*===================================================================*/

void FaseFloresta::geraInimigos1()
{
    Militar1* auxini;
    vector<Vector2f> pos_padrao;
    pos_padrao.push_back(Vector2f(WINDOW_SIZEX / 2.0, WINDOW_SIZEY / 2.0 + 200));

    srand(time(NULL));
    int n_inimigos = rand() % 3 + 2;

    for (int i = 0; i < n_inimigos; i++)
    {
        auxini = new Militar1(&camarada, Vector2f (WINDOW_SIZEX / 2.0 + (200*(n_inimigos - 3)), WINDOW_SIZEY / 2.0 + 200));
        lista_ent.push_back(auxini);
        auxini->setJanela(janela);
        auxini->set_fase(static_cast<Fase*>(this));
    }
    Lama* lama2 = new Lama();
    lama2->setJanela(janela);
    lama2->set_fase(static_cast<Fase*>(this));
    lista_obst.push_back(lama2);


}