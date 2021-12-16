#ifndef _PASSAGEIRO_H
#define _PASSAGEIRO_H

#include <string>
#include <list>
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

public:
    Passageiro();
    Passageiro(const string& n, unsigned id, unsigned i, bool menor);
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
};

#endif //_PASSAGEIRO_H
