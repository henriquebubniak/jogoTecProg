#pragma once
#define NULL 0

template<class Tipo>
class Lista
{


public:
    Lista(/* args */);
    ~Lista();

    template<class Tipo2>
    class Elemento
    {
    private:
        Tipo2* conteudo_apontado;
        Elemento<Tipo2>* prox_elemento;
        Elemento<Tipo2>* prev_elemento;
    public:
        Elemento()
        {
            conteudo_apontado = NULL;
            prox_elemento = NULL;
            prev_elemento = NULL;
        }
        ~Elemento() {}
        Tipo2* get_conteudo() { return conteudo_apontado; }
        Elemento<Tipo2>* get_prox() { return prox_elemento; }
        Elemento<Tipo2>* get_prev() { return prev_elemento; }

        void set_prox (Elemento<Tipo2>* el){ prox_elemento = el;}
        void set_prev (Elemento<Tipo2>* el) {prev_elemento = el;}
    };

    Elemento<Tipo>* get_prime_elem();
    Elemento<Tipo>* get_ult_elem();
    Tipo* get_next ();
    Tipo* get_prev ();

    void delElemento (Elemento<Tipo>* el);
    void addElemento (Elemento<Tipo>* el);

private:
    Elemento<Tipo>* primeiro_elemento;
    Elemento<Tipo>* ultimo_elemento;

};

