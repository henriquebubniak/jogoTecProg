#include "Entidade.h"

Entidade::Entidade(Vector2f p, Vector2f tam_cx, int h):
pos(p), caixa(tam_cx), hp(h), estado('p'), dim(tam_cx)
{
    velocidade = Vector2f(0.f, 0.f);
    caixa.setPosition(pos);
}
Entidade::~Entidade()
{}

void Entidade::imprime()
{
    janela->draw(caixa);
}

void Entidade::testa_colisao(Entidade* ent)
{
    /*if (ent->get_pos().x <= pos.x + dim.x && 
        ent->get_pos().x + ent->get_dim().x > pos.x + dim.x &&
        ent->get_pos().y <= pos.y + dim.y &&
        ent->get_pos().y + dim.y >= pos.y )
        caixa.setPosition(Vector2f(ent->get_pos().x - get_dim().x, caixa.getPosition().y));

    if (ent->get_pos().x + ent->get_dim().x >= pos.x && 
        ent->get_pos().x < pos.x                     &&
        ent->get_pos().y <= pos.y + dim.y            &&
        ent->get_pos().y + dim.y >= pos.y )
        caixa.setPosition(Vector2f(ent->get_pos().x + ent->get_dim().x, caixa.getPosition().y));
    if (ent->get_pos().x + ent->get_dim().x >= caixa.getPosition().x && 
        ent->get_pos().x <= caixa.getPosition().x + caixa.getGlobalBounds().width       &&
        ent->get_pos().y <= caixa.getPosition().y + caixa.getGlobalBounds().height            &&
        ent->get_pos().y + ent->get_dim().y >= pos.y)
        caixa.setPosition(Vector2f(caixa.getPosition().x, ent->get_pos().y - get_dim().y));
    if (ent->get_pos().x + ent->get_dim().x >= pos.x && 
        ent->get_pos().x <= pos.x + dim.x            &&
        ent->get_pos().y + ent->get_dim().y >= pos.y &&
        ent->get_pos().y <= pos.y)
        caixa.setPosition(Vector2f(caixa.getPosition().x, ent->get_pos().y + ent->get_dim().y));*/
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
