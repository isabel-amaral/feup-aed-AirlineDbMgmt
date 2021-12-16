#ifndef _PASSAGEIRO_H
#define _PASSAGEIRO_H

#include "Bagagem.h"
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
    /**
     * Lista de bagagens do passgeiro.
     */
    list<Bagagem*> bagagem;

public:
    Passageiro();
    Passageiro(const string& n, unsigned id, unsigned i, bool menor, const list<Bagagem*>& b = list<Bagagem*>());
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
     * @return lista com todas as bagagens do passageiro.
     */
    const list<Bagagem*>& getBagagem() const;
    /**
     * Define as bagagens que o passageiro possui.
     * @param b são as bagagens.
     */
    void setBagagem(const list<Bagagem*>& b);
};

#endif //_PASSAGEIRO_H
