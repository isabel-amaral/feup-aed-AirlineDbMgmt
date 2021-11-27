#ifndef _PASSAGEIRO_H
#define _PASSAGEIRO_H

#include "Bilhete.h"
#include <string>
#include <list>
using namespace std;

class Passageiro {
private:
    /**
     * nome completo do passageiro
     */
    string nome;
    /**
     * número de identificação do passageiro
     */
    unsigned int id;
    /**
     * idade do passageiro
     */
    unsigned int idade;
    /**
     * se o passageiro é um menor não acompanhado
     */
    bool menorNaoAcompanhado;
    /**
     * todos os bilhetes adquiridos pelo passageiro,
     * cada passageiro pode ter várias viagem planeadas
     */
    list<Bilhete> bilhetesAdquiridos;

public:
    Passageiro(string n, unsigned id, unsigned i, bool menor);
    /**
     *
     * @return nome do passageiro
     */
    string getNome() const;
    /**
     *
     * @return número de identificação do passageiro
     */
    int getId() const;
    /**
     *
     * @return idade do passageiro
     */
    unsigned int getIdade() const;
    /**
     *
     * @return true se o passageiro for menor de idade e estiver a vaigem sem um adulto responsável, falso caso contrário
     */
    bool isMenorNaoAcompanhado() const;
    /**
     * este método mostra (efetua print) os bilhetes adquiridos pelo passageiro
     */
    void mostrarBilehtesAdquiridos() const;
    /**
     * este método acrescenta um novo bilhete aos bilhetes adquiridos do passageiro,
     * não é possível adquirir um bilhete para um voo num data passada
     * @param bilhete é o bilhete que o passageiro pretende adquirir
     */
    void adquirirBilhete(Bilhete& bilhete);
};

#endif //_PASSAGEIRO_H
