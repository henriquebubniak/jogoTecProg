#include <SFML/Graphics.hpp>
#include "Entidade.h"
using namespace sf;
class Obstaculo: public Entidade
{
private:
    RectangleShape caixa;
public:
    Obstaculo(Vector2f pos, Vector2f dim);
    ~Obstaculo();
    void move(){}
};
