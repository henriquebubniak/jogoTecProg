#include "Ente.h"

Ente::Ente(const char* caminhoTextura):
pGerenciadorGrafico(NULL)
{
    if (caminhoTextura){

        if(!textura.loadFromFile(caminhoTextura))
        {
            cerr << "ERRO: Nao foi possivel carregar a textura"<< endl;
        }

        caixa.setTexture(textura);
    }

}
Ente::~Ente(){}
Sprite Ente::get_caixa ()
{
    return caixa;
}
void Ente::set_pGG(GerenciadorGrafico* pgg)
{
    pGerenciadorGrafico = pgg;
}
void Ente::inicializa(GerenciadorGrafico* pgg)
{
    set_pGG(pgg);
}