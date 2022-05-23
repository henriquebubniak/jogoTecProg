#pragma once
#include "Inimigo.h"
#include "Greg.h"
class Greca: public Inimigo
{
private:
    Greg* greg;
public:
    Greca(Greg* g = NULL);
    ~Greca();
    void move();
};

