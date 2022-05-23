#include "Personagem.h"
Personagem::Personagem(Vector2f p, Vector2f tam_cx, int h, float v):
Entidade(p, tam_cx),
tipo(1),
hp(h),
vel(v)
{
}

Personagem::~Personagem()
{
}