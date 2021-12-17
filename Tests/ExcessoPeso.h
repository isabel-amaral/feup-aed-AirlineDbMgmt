#ifndef _EXCESSOPESO_H
#define _EXCESSOPESO_H

#include "Bagagem.h"

class ExcessoPeso {
private:
    float pesoMaximo;
    float taxaPesoExtra;
    float taxaBagagemDeMao;

public:
    ExcessoPeso(float peso, float tp, float tb);
    float getPesoMaximo() const;
    float getTaxaPesoExtra() const;
    float getTaxaBagagemDeMao() const;
    bool excedePeso(const Bagagem& b) const;
    float multaExcessoPeso(const Bagagem& b) const;
    float multaTaxaBagagemDeMao(const Bagagem& b) const;
};

#endif //_EXCESSOPESO_H
