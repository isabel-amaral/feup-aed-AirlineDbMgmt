#ifndef _COMPANHIAAEREA_H
#define _COMPANHIAAEREA_H

#include "Passageiro.h"
#include "Bilhete.h"
#include "Voo.h"
#include "Data.h"

class CompanhiaAerea {
private:
    /**
     * Vetor com todos os bilhetes que foram vendidos pela companhia
     */
    vector<Bilhete> bilhetesVendidos;
    //list<Aviao> avioes;

public:
    CompanhiaAerea();
    /**
     *
     * @return uma copia do vetor bilhetesVendidos
     */
    vector<Bilhete> getBilhetesVendidos() const;
    /**
     * @param p é um determinado passageiro
     * @return  vector com todos os bilhetes adquiridos pelo passageiro (@param p) num vetor.
     * Caso este passageiro não tenha adquirido nenhum bilhete, será retornado um vetor vazio.
     */
    vector<Bilhete> getBilhetesFromPassageiro(const Passageiro& p) const;
    /**
     * Imprime os dados de cada um dos bilhetes de um determinado passageiro.
     * Caso o passageiro não tenha adquirido nenhum bilhete,
     * a mensagem "Este passageiro ainda não adquiriu nenhum bilhete" é apresentada.
     * @param p é o passageiro
     */
    void mostrarBilhetesFromPassageiro(const Passageiro& p) const;
    /**
     * Acrescenta um bilhete no vetor de bilhetes vendidos caso seja possivel efetuar a sua compra (o voo v não esteja lotado).
     * @param p é o passageiro que pretende comprar o bilhete.
     * @param v é voo que o passageiro pretende adquirir o bilhete.
     * @param bagagem é a bagagem do passageiro.
     * @return true se a compra do bilheite foi realizada com sucesso.
     * Caso contrário retorna false (o voo está lotado).
     */
    bool adquirirBilhete(const Passageiro& p, Voo& v, bool bagagem);
    /**
     * Acrescenta bilhetes no vetor de bilhetes vendidos caso seja possivel
     * (os bilhetes disponíveis são suficientes para o grupo todo).
     * @param p lista de passageiros que pretendem comprar bilhetes.
     * @param v é voo para o qual os passageiros pretendem adquirir bilhetes.
     * @param bagagem indica se os passageiros têm ou não direito a levar bagagem de mão.
     * @return true se a compra dos bilheite foi realizada com sucesso.
     * Caso contrário retorna false (o voo está lotado/ não possui bilhetes suficientes).
     */
    bool adquirirConjuntoBilhetes(const list<Passageiro>& p, Voo& v, bool bagagem);
    //outros métodos
};

#endif //_COMPANHIAAEREA_H
