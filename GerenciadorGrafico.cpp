#include "GerenciadorGrafico.h"
#include "Entidade.h"
#include "Projetil.h"
#include "Obstaculo.h"



/*==================CONSTRUTORA E DESTRUTORA=========================*/

GerenciadorGrafico:: GerenciadorGrafico():
    janela(VideoMode(WINDOW_SIZEX, WINDOW_SIZEY), "GREG")
{

    janela.setPosition(Vector2i(0.f, 0.f));
    janela.setFramerateLimit(120);
}

GerenciadorGrafico:: ~GerenciadorGrafico()
{

}

/*===================================================================*/

/*==================IMPRIME=========================*/

void GerenciadorGrafico:: imprimeEntes()
{
    list<Ente*>::iterator ente;

    for (ente = entes.begin(); ente != entes.end(); ente++)
    {
        janela.draw((*ente)->get_caixa());
    }
}

void GerenciadorGrafico:: imprimeTextos()
{
    for (int i = 0; i < textos.size(); i++)
    {
        janela.draw(textos[i]);
    }
}


/*===================================================================*/

/*==================IMPRIME=========================*/

void GerenciadorGrafico:: atualizaJanela()
{

    janela.clear();
    imprimeEntes();
    imprimeTextos();
    janela.display();
}

/*===================================================================*/

/*===============================SETS===============================*/

void GerenciadorGrafico::incluiEnte(Ente* ente)
{
    entes.push_back(ente);
}
void GerenciadorGrafico::incluiEnte(list<Entidade*>* ple)
{
    list<Entidade*>:: iterator enti;
    for (enti = ple->begin(); enti != ple->end(); enti++)
    {
        entes.push_back(static_cast<Ente*>(*enti));
    }
}
void GerenciadorGrafico::incluiEnte(list<Projetil*>* plp)
{
    list<Projetil*>:: iterator proj;
    for (proj = plp->begin(); proj != plp->end(); proj++)
    {
        entes.push_back(static_cast<Ente*>(*proj));
    }
}
void GerenciadorGrafico::incluiEnte(list<Obstaculo*>* plo)
{
    list<Obstaculo*>:: iterator obst;
    for (obst = plo->begin(); obst != plo->end(); obst++)
    {
        entes.push_back(static_cast<Ente*>(*obst));
    }
}

void GerenciadorGrafico::incluiTexto(std::vector<Text>* t)
{
    for (int i = 0; i < t->size(); i++)
    {
        textos.push_back((*t)[i]);
    }
}


/*===================================================================*/

bool GerenciadorGrafico::get_JanelaAberta()
{
    return janela.isOpen();
}

bool GerenciadorGrafico::pega_evento(Event* ev)
{
    return janela.pollEvent(*ev);
}

void GerenciadorGrafico::fecha_janela()
{
    janela.close();
}

void GerenciadorGrafico::removeTodosEntes()
{
    entes.clear();
    textos.clear();
}