#pragma once

#include "Ente.h"


#include<list>

using namespace std;
class Entidade;
class Obstaculo;
class Projetil;
class GerenciadorGrafico{

private:

    list<Ente*> entes;
    std::vector<Text> textos;

    RenderWindow janela;

public:

    //construtora e destrutora
    GerenciadorGrafico();
    ~GerenciadorGrafico();

    //Draw
    void imprimeEntes();
    void imprimeTextos();
    void atualizaJanela();

    //sets
    void incluiEnte(Ente* ente);
    void incluiEnte(list<Entidade*>* ple);
    void incluiEnte(list<Projetil*>* plp);
    void incluiEnte(list<Obstaculo*>* plo);
    void incluiTexto(std::vector<Text>* t);
    void removeEnte(Ente* ente);
    void removeTodosEntes();    
    void removeTodosTextos();

    bool get_JanelaAberta();
    bool pega_evento(Event* ev);
    void fecha_janela();



};
