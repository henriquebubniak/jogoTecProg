#include "GerenciadorGrafico.h"


/*==================CONSTRUTORA E DESTRUTORA=========================*/

GerenciadorGrafico:: GerenciadorGrafico(list<Entidade*>* ple, list<Projetil*>* plp, RenderWindow* j)
{
    entidades = ple;
    projeteis = plp;
    janela = j;
}

GerenciadorGrafico:: ~GerenciadorGrafico()
{

}

/*===================================================================*/

/*==================IMPRIME=========================*/

void GerenciadorGrafico:: imprimeEntes()
{

    /**
     *  Chama as Funcoes imprimeProjeteis e imprimeEntidades
     *
     */

     imprimeProjeteis();
     imprimeEntidades();

}


void GerenciadorGrafico:: imprimeProjeteis()
{

    /**
     *  Percorre a lista de projeteis e os imprime
     *
     */

    list<Projetil*>::iterator proj;

    if (projeteis != NULL)
    {

        for (proj = projeteis->begin(); proj != projeteis->end(); proj++)
        {

            janela->draw((*proj)->get_caixa());
        }
    }

}

void GerenciadorGrafico:: imprimeEntidades()
{

    /**
     *  Percorre a lista de entidades e os imprime
     *
     */

    list<Entidade*>::iterator ent;

    if (entidades != NULL)
    {

        for (ent = entidades->begin(); ent != entidades->end(); ent++)
        {

            janela->draw((*ent)->get_caixa());
        }
    }
}

/*===================================================================*/

/*==================IMPRIME=========================*/

void GerenciadorGrafico:: atualizaJanela()
{

    janela->clear();
    imprimeEntes();
    janela->display();
}

/*===================================================================*/

/*===============================SETS===============================*/

void GerenciadorGrafico:: setListaEntidades (list<Entidade*>* ent)
{
    entidades = ent;
}

void GerenciadorGrafico:: setListaProjeteis (list<Projetil*>* proj)
{
    projeteis = proj;
}

void GerenciadorGrafico:: setJanela (RenderWindow* j)
{
    janela = j;
}

/*===================================================================*/
