#include "GerenciadorDeColisoes.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

GerenciadorDeColisoes:: GerenciadorDeColisoes(list<Entidade*>* ple, list<Projetil*>* plp)
{
    entidades = ple;
    projeteis = plp;
}

GerenciadorDeColisoes:: ~GerenciadorDeColisoes()
{

    //Destruir todas as entidades alocadas dinamicamente e limpar a lista

}

/*===================================================================*/

/*==================TESTES=========================*/

void GerenciadorDeColisoes:: testaColisoes ()
{

    /** 1-Criar dois iteradores para percorrer a lista
     *
     *  2- Criar um loop aninhado percorrendo cada elemento da lista a partir
     *      do atual e realizar os devidos testes de colisao
     *
     *
     */
    testaColisoesProjeteis();
    testaColisoesEntidades();
}

void GerenciadorDeColisoes:: testaColisoesProjeteis()
{
    list<Projetil*> plista_rm;
    /** 1- Criar dois iteradores, um para a lista de entidades e outro para a lista de projeteis
     *
     *  2- Testar se houve colis�o
     *
     *  3- Em caso positivo, testar se a entidade � viva ou n�o (pode sofrer dano)
     *
     *  4- Caso o seja, aplicar o dano.
     */

    list<Entidade*>::iterator ent;
    list<Projetil*>::iterator proj;
    list<Projetil*>::iterator proj_rm;
    if (projeteis != NULL)
    {
        for (proj = projeteis->begin(); proj != projeteis->end(); proj++)
        {
            for (ent = entidades->begin(); ent != entidades->end(); ent++)
            {
                if((*proj)->get_GlobalBounds().intersects((*ent)->get_GlobalBounds()))
                {
                    (*ent)->dano((*proj)->get_forca());
                    plista_rm.push_back(*proj);
                    break;
                }
            }
        }
        proj_rm = plista_rm.begin();

        while(proj_rm != plista_rm.end())
        {
            projeteis->remove(*proj_rm);
            proj_rm++;
            delete(*prev(proj_rm, 1));
        }
        //delete (*plista_rm.end());
    }

}

void GerenciadorDeColisoes:: testaColisoesEntidades ()
{

    /** 1- Criar dois iteradores para rodar a lista de entidades
     *
     *  2- Loop aninhado
     *
     *  3- testar colis�es sem repeti��es!!!
     *
     */

    list<Entidade*>::iterator i;
    list<Entidade*>::iterator j;

    for (i = entidades->begin(); i != entidades->end(); i++)
    {

        for (j = next(i, 1); j != entidades->end(); j++)
        {
            FloatRect proxPos, posJog;

            posJog = (*i)->get_GlobalBounds();
            proxPos = (*i)->get_GlobalBounds();
            proxPos.left += ((*i)->get_velocidade()).x;
            proxPos.top += ((*i)->get_velocidade()).y;

            FloatRect posObst;
            posObst = (*j)->get_GlobalBounds();

            if (proxPos.intersects(posObst))
            {
                if (posJog.left < posObst.left                                 &&
                        posJog.left + posJog.width < posObst.left + posObst.width &&
                        posJog.top < posObst.top + posObst.height                  &&
                        posJog.top + posJog.height > posObst.top) //colis�o a esquerda.
                {
                    (*i)->set_velocidade_x (0.f);
                    (*i)->set_pos_caixa (Vector2f(posObst.left - posJog.width, posJog.top));
                    (*j)->set_velocidade_x (0.f);
                    (*j)->set_pos_caixa (Vector2f(posObst.left, posObst.top));
                }
                if (posJog.left > posObst.left                                 &&
                        posJog.left + posJog.width > posObst.left + posObst.width &&
                        posJog.top < posObst.top + posObst.height                  &&
                        posJog.top + posJog.height > posObst.top) //colis�o a direita.
                {
                    (*i)->set_velocidade_x (0.f);
                    (*i)->set_pos_caixa(Vector2f(posObst.left + posObst.width, posJog.top));
                    (*j)->set_velocidade_x (0.f);
                    (*j)->set_pos_caixa (Vector2f(posObst.left, posObst.top));
                }
                if (posJog.left < posObst.left + posObst.width                 &&
                        posJog.left + posJog.width > posObst.left                 &&
                        posJog.top < posObst.top                                   &&
                        posJog.top + posJog.height < posObst.top + posObst.height) //colis�o acima.
                {
                    (*i)->set_velocidade_y (0.f);
                    (*i)->set_pos_caixa(Vector2f(posJog.left, posObst.top - posJog.height));
                    (*j)->set_velocidade_y (0.f);
                    (*j)->set_pos_caixa (Vector2f(posObst.left, posObst.top));
                    (*i)->set_podepular (true);
                }
                if (posJog.left < posObst.left + posObst.width                 &&
                        posJog.left + posJog.width > posObst.left                 &&
                        posJog.top > posObst.top                                   &&
                        posJog.top + posJog.height > posObst.top + posObst.height) //colis�o abaixo.
                {
                    (*i)->set_velocidade_y (0.f);
                    (*i)->set_pos_caixa(Vector2f(posJog.left, posObst.top + posObst.height));
                    (*j)->set_velocidade_y (0.f);
                    (*j)->set_pos_caixa (Vector2f(posObst.left, posObst.top));
                }

            }
        }
    }


/*===================================================================*/


/*===============================SETS===============================*/

}

void GerenciadorDeColisoes:: setListaEntidades(list<Entidade*>* ent)
{

    entidades = ent;
}

void GerenciadorDeColisoes:: setListaProjeteis(list<Projetil*>* proj)
{

    projeteis = proj;
}

/*===================================================================*/


