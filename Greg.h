#pragma once
#include "Entidade.h"
#include <list>
using namespace std;
class Greg: public Entidade
{
private:
    int nvl_greg;
    float vel;
    list<Entidade*>* p_lista_ent;
    bool pode_pular;
public:
    Greg(list<Entidade*>* le = NULL);
    ~Greg();
    void move();
    RectangleShape get_caixa() {return caixa;}
    const Vector2f get_pos() { return pos; }
    void testa_colisao (Entidade* ent);
};