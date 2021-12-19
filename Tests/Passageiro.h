#ifndef _PASSAGEIRO_H
#define _PASSAGEIRO_H

#include <string>
#include <list>
#include <iostream>
using namespace std;

class Passageiro {
private:
    /**
     * Nome completo do passageiro.
     */
    string nome;
    /**
     * Número de identificação do passageiro.
     */
    unsigned int id;
    /**
     * Idade do passageiro.
     */
    unsigned int idade;
    /**
     * Se o passageiro é um menor não acompanhado.
     */
    bool menorNaoAcompanhado;
    /**
     * Preço que o passageiro deve pagar em multas de excesso de bagagem ou uso de bagagem de mão indevido.
     * Este parâmetro encontra-se inicialmente a 0 e é incrementado com o valor da multa à medida que as infrações são cometidas.
     */
    float multaBagagem;

public:
    Passageiro();
    Passageiro(const string& n, unsigned id, unsigned i, bool menor = false);
    /**
     *
     * @return nome do passageiro.
     */
    string getNome() const;
    /**
     *
     * @return número de identificação do passageiro.
     */
    unsigned getId() const;
    /**
     *
     * @return idade do passageiro.
     */
    unsigned getIdade() const;
    /**
     *
     * @return true se o passageiro for menor de idade e estiver a vaigem sem um adulto responsável, falso caso contrário.
     */
    bool isMenorNaoAcompanhado() const;
    /**
     *
     * @return o preço que o passageiro deve pagar em multas de excesso de bagagem ou uso indevido de bagagem de mão
     */
    float getMultaBagagem() const;
    /**
     * Atualiza o valor que o passageiro deve pagar em multas de excesso de bagagem ou uso indevido de bagagem de mão
     * @param multa preço a pagar pela nova infração cometida
     */
    void incrementarMulta(float multa);
    bool operator== (const Passageiro& p) const;
    //TODO: DOCUMENTACAO
    friend ostream& operator<< (ostream& os, const Passageiro& p);
};

#endif //_PASSAGEIRO_H
