#pragma once
#define NULL 0

template<class Tipo>
class Lista
{

public:
    Lista(/* args */);
    ~Lista();
    class Elemento
    {
    private:
        Tipo* conteudo_apontado;
        Elemento* prox_elemento;
        Elemento* prev_elemento;
    public:
        Elemento()
        {
            conteudo_apontado = NULL;
            prox_elemento = NULL;
            prev_elemento = NULL;
        }
        ~Elemento() {}
        Tipo* get_conteudo() { return conteudo_apontado; }
        Elemento* get_prox() { return prox_elemento; }
        Elemento* get_prev() { return prev_elemento; }
    };
    Elemento* get_prime_elem();
    Elemento* get_ult_elem();
private:
    Elemento* primeiro_elemento;
    Elemento* ultimo_elemento;

};

