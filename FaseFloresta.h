#include "Fase.h"
#include "Greca.h"
#include "Obstaculo.h"
class FaseFloresta: public Fase
{
private:
    Greg greg;
    Greca greca;
    Obstaculo plataforma;
public:
    FaseFloresta(RenderWindow* j = NULL);
    ~FaseFloresta();
};

