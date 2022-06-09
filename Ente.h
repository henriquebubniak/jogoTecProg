#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class GerenciadorGrafico;
class Ente
{
protected:    
    Sprite caixa;
    Texture textura;
    GerenciadorGrafico* pGerenciadorGrafico;
public:
    Ente(const char* caminhoTextura = "imagens/padrao.png");
    ~Ente();
    Sprite get_caixa ();
    void set_pGG(GerenciadorGrafico* pgg);
    virtual void inicializa(GerenciadorGrafico* pgg);
};


