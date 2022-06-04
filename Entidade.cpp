#include "Entidade.h"
#include "Fase.h"


/*==================CONSTRUTORA E DESTRUTORA=========================*/

Entidade::Entidade(Vector2f p, Vector2f tam_cx, Fase* f):
pos(p), caixa(tam_cx), dim(tam_cx), pfase(f)
{
    velocidade = Vector2f(0.f, 0.f);
    caixa.setPosition(pos);
}


Entidade::~Entidade()
{

    janela = nullptr;
    pfase = nullptr;

}

/*===================================================================*/

/*==================SETS=========================*/

void Entidade:: setJanela (RenderWindow* j){

    janela = j;
}

void Entidade:: set_fase(Fase* f){

    pfase = f;
}

void Entidade:: set_velocidade_x (float x){

    velocidade.x = x;
}

void Entidade:: set_velocidade_y (float y){

    velocidade.y = y;
}

void Entidade:: set_pos_caixa (Vector2f pos){

    caixa.setPosition(pos);
}

void Entidade:: set_podepular (bool p){

}

/*===================================================================*/


/*==================GETS=========================*/

Vector2f Entidade:: get_dim (){

    return dim;
}

Vector2f Entidade:: get_pos (){

    return pos;
}

Vector2f Entidade:: get_velocidade (){

    return velocidade;
}

FloatRect Entidade:: get_GlobalBounds (){

    return caixa.getGlobalBounds();
}

RenderWindow* Entidade:: get_janela (){

    return janela;
}

RectangleShape Entidade:: get_caixa (){

    return caixa;
}

/*===================================================================*/


