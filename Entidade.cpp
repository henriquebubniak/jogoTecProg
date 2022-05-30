#include "Entidade.h"

Entidade::Entidade(Vector2f p, Vector2f tam_cx, list<Entidade*>* ple):
pos(p), caixa(tam_cx), dim(tam_cx), p_lista_ent(ple)
{
    velocidade = Vector2f(0.f, 0.f);
    caixa.setPosition(pos);
}
Entidade::~Entidade()
{

    janela = nullptr;
    p_lista_ent = nullptr;

}

void Entidade::imprime()
{
    janela->draw(caixa);
}

void Entidade::testa_colisao(Entidade* ent)
{
    FloatRect proxPos, posJog;

    posJog = caixa.getGlobalBounds();
    proxPos = caixa.getGlobalBounds();
    proxPos.left += velocidade.x;
    proxPos.top += velocidade.y;

    FloatRect posObst;
    posObst = ent->caixa.getGlobalBounds();

    if (proxPos.intersects(posObst))
    {
        if (posJog.left < posObst.left                                 &&
            posJog.left + posJog.width < posObst.left + posObst.width &&
            posJog.top < posObst.top + posObst.height                  &&
            posJog.top + posJog.height > posObst.top) //colisão a esquerda.
        {
            velocidade.x = 0;
            caixa.setPosition(Vector2f(posObst.left - posJog.width, posJog.top));
        }
        if (posJog.left > posObst.left                                 &&
            posJog.left + posJog.width > posObst.left + posObst.width &&
            posJog.top < posObst.top + posObst.height                  &&
            posJog.top + posJog.height > posObst.top) //colisão a direita.
        {
            velocidade.x = 0;
            caixa.setPosition(Vector2f(posObst.left + posObst.width, posJog.top));
        }
        if (posJog.left < posObst.left + posObst.width                 &&
            posJog.left + posJog.width > posObst.left                 &&
            posJog.top < posObst.top                                   &&
            posJog.top + posJog.height < posObst.top + posObst.height) //colisão acima.
        {
            velocidade.y = 0;
            caixa.setPosition(Vector2f(posJog.left, posObst.top - posJog.height));
        }
        if (posJog.left < posObst.left + posObst.width                 &&
            posJog.left + posJog.width > posObst.left                 &&
            posJog.top > posObst.top                                   &&
            posJog.top + posJog.height > posObst.top + posObst.height) //colisão acima.
        {
            velocidade.y = 0;
            caixa.setPosition(Vector2f(posJog.left, posObst.top + posObst.height));
        }

    }
}
