#include "Entidade.h"
#include "Greg.h"
class Greca: public Entidade
{
private:
    Greg* greg;
    float vel;
    float vel_pulo;
public:
    Greca(Greg* g = NULL);
    ~Greca();
    void move();
};

