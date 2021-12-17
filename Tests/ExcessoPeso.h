#ifndef _EXCESSOPESO_H
#define _EXCESSOPESO_H

#include "Bagagem.h"

class ExcessoPeso {
private:
    /**
     * peso máximo permitido para cada volume de bagagem
     */
    float pesoMaximo;
    /**
     * preço da multa por cada quilo extra de um volume de bagagem
     */
    float taxaPesoExtra;
    /**
     * preço da multa caso o passageiro tenha bagagem de mão e o seu bilhete não o permitir
     */
    float taxaBagagemDeMao;

public:
    ExcessoPeso();
    ExcessoPeso(float peso, float tp, float tb);
    /**
     *
     * @return peso máximo permitido para cada volume de bagagem
     */
    float getPesoMaximo() const;
    /**
     *
     * @return preço da multa por cada quilo extra de um volume de bagagem
     */
    float getTaxaPesoExtra() const;
    /**
     *
     * @return preço da multa caso o passageiro tenha bagagem de mão e o seu bilhete não o permitir
     */
    float getTaxaBagagemDeMao() const;
    /**
     *
     * @param b volume de bagagem a testar
     * @return true se o volume de bagagem exceder o peso permitide, false caso contrário
     */
    bool excedePeso(const Bagagem* b) const;
    /**
     *
     * @param b volume de bagagem que excede o peso permitido
     * @return preço extra a pagar (multa) para o passageiro poder levar esta bagagem no avião
     */
    float multaExcessoPeso(const Bagagem* b) const;
    /**
     *
     * @param b volume de bagagem de mão de um passageiro cujo bilhete não permitia bagagem de mão
     * @return preço extra a pagar (multa) para o passageiro poder levar esta bagagem no avião
     */
    float multaTaxaBagagemDeMao(const Bagagem* b) const;
};

#endif //_EXCESSOPESO_H
