#include "GerenciadorDeColisoes.h"

GerenciadorDeColisoes:: GerenciadorDeColisoes() {}

GerenciadorDeColisoes:: ~GerenciadorDeColisoes()
{

    //Destruir todas as entidades alocadas dinamicamente e limpar a lista

}

void GerenciadorDeColisoes:: testaColisoes ()
{

    /** 1-Criar dois iteradores para percorrer a lista
     *
     *  2- Criar um loop aninhado percorrendo cada elemento da lista a partir
     *      do atual e realizar os devidos testes de colisao
     *
     *
     */

}

void GerenciadorDeColisoes:: testaColisoesProjeteis()
{

    /** 1- Criar dois iteradores, um para a lista de entidades e outro para a lista de projeteis
     *
     *  2- Testar se houve colisão
     *
     *  3- Em caso positivo, testar se a entidade é viva ou não (pode sofrer dano)
     *
     *  4- Caso o seja, aplicar o dano.
     */

    list<Entidade*>::iterator ent;
    list<Projetil*>::iterator proj;

    for (proj = projeteis->begin(); proj != projeteis->end(); proj++)
    {

        for (ent = entidades->begin(); ent != entidades->end(); ent++)
        {
            if((*proj)->get_GlobalBounds().intersects((*ent)->get_GlobalBounds()))
            {
                (*ent)->dano((*proj)->get_forca());

                projeteis->remove((*proj));

                delete (*proj);
            }
        }
    }


}

void GerenciadorDeColisoes:: testaColisoesEntidades ()
{

    /** 1- Criar dois iteradores para rodar a lista de entidades
     *
     *  2- Loop aninhado
     *
     *  3- testar colisões sem repetições!!!
     *
     */

    list<Entidade*>::iterator i;
    list<Entidade*>::iterator j;

    for (i = entidades->begin(); i != entidades->end(); i++)
    {

        for (j = i++; j != entidades->end(); j++)
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
                        posJog.top + posJog.height > posObst.top) //colisão a esquerda.
                {
                    (*i)->set_velocidade_x (0.f);
                    (*i)->set_pos_caixa (Vector2f(posObst.left - posJog.width, posJog.top));
                }
                if (posJog.left > posObst.left                                 &&
                        posJog.left + posJog.width > posObst.left + posObst.width &&
                        posJog.top < posObst.top + posObst.height                  &&
                        posJog.top + posJog.height > posObst.top) //colisão a direita.
                {
                    (*i)->set_velocidade_x (0.f);
                    (*i)->set_pos_caixa(Vector2f(posObst.left + posObst.width, posJog.top));
                }
                if (posJog.left < posObst.left + posObst.width                 &&
                        posJog.left + posJog.width > posObst.left                 &&
                        posJog.top < posObst.top                                   &&
                        posJog.top + posJog.height < posObst.top + posObst.height) //colisão acima.
                {
                    (*i)->set_velocidade_y (0.f);
                    (*i)->set_pos_caixa(Vector2f(posJog.left, posObst.top - posJog.height));
                    (*i)->set_podepular (true);
                }
                if (posJog.left < posObst.left + posObst.width                 &&
                        posJog.left + posJog.width > posObst.left                 &&
                        posJog.top > posObst.top                                   &&
                        posJog.top + posJog.height > posObst.top + posObst.height) //colisão acima.
                {
                    (*i)->set_velocidade_y (0.f);
                    (*i)->set_pos_caixa(Vector2f(posJog.left, posObst.top + posObst.height));
                }

            }
        }
    }





}

void GerenciadorDeColisoes:: setListaEntidades(list<Entidade*>* ent)
{

    entidades = ent;
}

void GerenciadorDeColisoes:: setListaProjeteis(list<Projetil*>* proj)
{

    projeteis = proj;
}


