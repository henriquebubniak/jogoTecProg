#include "Lista.h"

template<class Tipo>
Lista<Tipo>::Lista()
{
    primeiro_elemento = nullptr;
    ultimo_elemento = nullptr;
}

template<class Tipo>
Lista<Tipo>::~Lista()
{

}

template<class Tipo>
Tipo* Lista<Tipo>:: get_next ()
{

    if(conteudo_apontado->get_next() != nullptr)
    {

        return conteudo_apontado->get_next();
    }

    else
    {

        cout << "Ponteiro nulo!" << endl;

        return nullptr;
    }
}

template<class Tipo>
Tipo* Lista<Tipo>:: get_prev ()
{

    if(conteudo_apontado->get_prev() != nullptr)
    {

        return conteudo_apontado->get_prev();

    }

    else
    {

        cout << "Ponteiro nulo!" << endl;

        return nullptr;
    }

}

template<class Tipo>
Elemento<Tipo>* Lista<Tipo>:: get_prime_elem ()
{

    if (prineiro_elemento != nullptr)
    {

        return primeiro_elemento;
    }

    else
    {

        cout<< "Lista vazia" << endl;
        return nullptr;
    }

}



template<class Tipo>
Elemento<Tipo>* Lista<Tipo>:: get_ult_elem ()
{

    if(conteudo_apontado != nullptr)
    {

        Elemento<Tipo>* aux = conteudo_apontado;

        while(aux->get_next() != nullptr)
        {
            aux = aux->get_next();
        }

        return aux;
    }

    else
    {
        cout << "Lista Vazia." << endl;
        return nullptr;
    }

}

template<class Tipo>
void Lista<Tipo>:: delElemento(Elemento<Tipo>* el)
{

    if (el != nullptr)
    {

        bool achou = false;

        Elemento<Tipo>* aux = primeiro_ elemento;

        while (achou == false && aux != nullptr){

            if(aux == el){
                achou = true;

                (aux->get_prev())->set_prox(aux->get_prox);
                (aux->get_prox())->set_prev(aux->get_prev);

                delete (aux);
            }
        }

        if (!achou){
            cout << "O elemento não está na lista." << endl;
        }
    }


}

void Lista<Tipo>:: addElemento (Elemento<Tipo>* el){


    ultimo_elemento->set_prox(el);
    el->set_prev(ultimo_elemento);
    ultimo_elemento = el;

}
