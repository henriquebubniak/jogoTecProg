#include "FaseFloresta.h"

FaseFloresta::FaseFloresta(RenderWindow* j):
Fase(j),
greg(),
greca(&greg),
plataforma(Vector2f(0.f, WINDOW_SIZEY-70), Vector2f(WINDOW_SIZEX, 70))
{
    lista_ent.push_back(static_cast<Entidade*>(&greg));
    lista_ent.push_back(static_cast<Entidade*>(&greca));
    lista_ent.push_back(static_cast<Entidade*>(&plataforma));
    greg.setJanela(janela);
    greca.setJanela(janela);
    plataforma.setJanela(janela);
    greg.set_ple(&lista_ent);
    greca.set_ple(&lista_ent);
    plataforma.set_ple(&lista_ent);
}

FaseFloresta::~FaseFloresta()
{
}