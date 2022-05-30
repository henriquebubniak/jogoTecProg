#include "GerenciadorDeColisoes.h"

GerenciadorDeColisoes:: GerenciadorDeColisoes(){}

GerenciadorDeColisoes:: ~GerenciadorDeColisoes(){

    //Destruir todas as entidades alocadas dinamicamente e limpar a lista

}

void GerenciadorDeColisoes:: testaColisoes (){

        /** 1-Criar dois iteradores para percorrer a lista
         *
         *  2- Criar um loop aninhado percorrendo cada elemento da lista a partir
         *      do atual e realizar os devidos testes de colisao
         *
         *
         */

}

void GerenciadorDeColisoes:: testaColisoesProjeteis(){

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

     for (proj = projeteis->begin(); proj != projeteis->end(); proj++){

        for (ent = entidades->begin(); ent != entidades->end(); ent++){
            if((*proj)->get_GlobalBounds().intersects((*ent)->get_GlobalBounds()))
            {
                (*ent)->dano((*proj)->get_forca());

                projeteis->remove((*proj));

                delete (*proj);
            }
        }
     }


}

void GerenciadorDeColisoes:: setListaEntidades(list<Entidade*>* ent){

    entidades = ent;
}

void GerenciadorDeColisoes:: setListaProjeteis(list<Projetil*>* proj){

    projeteis = proj;
}


