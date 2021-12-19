#ifndef _COMPANHIAAEREA_H
#define _COMPANHIAAEREA_H

#include "Passageiro.h"
#include "Bilhete.h"
#include "Voo.h"
#include "Data.h"
#include "ExcessoPeso.h"
#include "Aviao.h"

class CompanhiaAerea {
private:
    /**
     * Todos os bilhetes que foram vendidos pela companhia.
     */
    vector<Bilhete> bilhetesVendidos;
    /**
     * Todos os voos que a companhia tem por realizar.
     */
    vector<Voo> voos;
    /**
     * Objeto que contém as restrições de peso definidas pela companhia aérea e multas associadas.
     */
    ExcessoPeso excessoPeso;
    /**
     * Todos os avioes da companhia area.
     */
    list<Aviao> avioes;
    /**
     * Todos os aeroportos onde os aviões da companhia operam.
     */
     vector<Aeroporto> aeroportos;

public:
    CompanhiaAerea();
    CompanhiaAerea(float pesoMaximo, float taxaPesoExtra, float taxaBagagemDeMao);
    /**
     *
     * @return uma copia dos bilhetes que a companhia vendeu.
     */
    vector<Bilhete> getBilhetesVendidos() const;
    /**
     *
     * @return todos os voos que a companhia tem por realizar.
     */
    vector<Voo> getVoos() const;
    /**
     *
     * @return todos os avioes da companhia area.
     */
    list<Aviao> getAvioes() const;
    /**
     *
     * @return todos os aeroportos onde os aviões da companhia operam
     */
    vector<Aeroporto> getAeroportos() const;
    /**
     * Define os voos da companhia aérea.
     * @param voos são os novos voos da companhia.
     */
    void setVoos(const vector<Voo>& voos);
    /**
     * Acrescenta um voo ao demais voos que a companhia tem por realizar.
     * @param v novo voo a acrescentar.
     */
    void addVoo(const Voo &v);
    /**
     * Adiciona um novo a avião à lista de aviões.
     * @param aviao é o novo avião a ser adicionado.
     */
    void addAviao( const Aviao &aviao);
    /**
     * Adiciona um novo aeroporto ao vector se este ainda não existir no mesmo.
     * @param aeroporto é o aeroporto a ser acrescentado
     */
    void addAeroporto (const Aeroporto &aeroporto);
    /**
     * Procura um determinado aeroporto no vector aeroportos usando pesquisa binária.
     * @param aeroporto é o elemento a ser pesquisado.
     * @return a posição do aeroporto vo vector caso ele exista. Casp contrário retorna
     * o índice do maior elemento menor que aeroporto ou o menor elemento maior que aeroporto
     */
    unsigned binarySearchAeroporto (const Aeroporto &aeroporto);
    /**
     *
     * @param bId é o id do bilhete
     * @return bilhete com id bId
     */
    Bilhete getBilheteID(unsigned bId) const;
    /**
     *
     * @param pId é o id de um determinado passageiro
     * @return vector com todos os bilhetes adquiridos pelo passageiro p num vetor.
     * Caso este passageiro não tenha adquirido nenhum bilhete, será retornado um vetor vazio.
     */
    vector<Bilhete> getBilhetesFromPassageiro(unsigned pId) const;
    /**
     * Imprime os dados de cada um dos bilhetes de um determinado passageiro.
     * Caso o passageiro não tenha adquirido nenhum bilhete, é apresentada a
     * mensagem "Este passageiro ainda não adquiriu nenhum bilhete".
     * @param pId é o id do passageiro
     */
    void showBilhetesFromPassageiro(unsigned pId) const;
    /**
     *
     * @param numVoo é o número do voo
     * @return todos os passageiros do voo indicado
     */
    vector<Passageiro> getPassageirosFromVoo(unsigned numVoo) const;
    /**
     * Mostra todos os passageiros que adquiriram bilhete para um determinado voo
     * @param numVoo é o número do voo
     */
    void showPassageirosFromVoo(unsigned numVoo) const;
    /**
     * Procura o bilhete de um determinado passageiro para um determinado voo
     * @param pId é o id do passageiro
     * @param numVoo é o número do voo
     * @return bilhete do passageiro para o voo em questão
     */
    Bilhete getBilhetePassageiroVoo(unsigned pId, unsigned numVoo) const;
    /**
     * Acrescenta um bilhete ao conjunto dos demais bilhetes vendidos caso seja possivel efetuar a sua compra (o voo v não está lotado).
     * @param p é o passageiro que pretende comprar o bilhete.
     * @param v é voo que o passageiro pretende adquirir o bilhete.
     * @param bagagem é a bagagem do passageiro.
     * @return true se a compra do bilheite foi realizada com sucesso.
     * Caso contrário retorna false (o voo está lotado).
     */
    bool adquirirBilhete(const Passageiro& p, Voo& v, bool bagagem);
    /**
     * Acrescenta bilhetes no vetor de bilhetes vendidos caso seja possivel
     * (os bilhetes disponíveis são suficientes para o todos membros do grupo).
     * @param p lista de passageiros que pretendem comprar bilhetes.
     * @param v é voo para o qual os passageiros pretendem adquirir bilhetes.
     * @param bagagem indica se os passageiros têm ou não direito a levar bagagem de mão.
     * @return true se a compra dos bilheite foi realizada com sucesso.
     * Caso contrário retorna false (o voo está lotado/ não possui bilhetes suficientes para todos).
     */
    bool adquirirConjuntoBilhetes(list<Passageiro>& p, Voo& v, bool bagagem);
    /**
     * Cancela a compra feita por um determinado passsageiro de um bilhete para um determinado voo.
     * Esta operação não é possível se o passageiro nunca tiver comprado nenhum bilhete para o voo em questão
     * ou se o check-in para o voo em questão já tiver sido realizado.
     * @param p é o passageiro que pretende cancelar viagem
     * @param v é o voo da viagem em questão
     * @return true se o cancelamento for possível, false caso contrário
     */
    bool cancelarViagem(const Passageiro& p, Voo& v);
    /**
     * Realiza o check-in de um determinado passageiro com bilhete referente a um certo voo
     * @param bId é o id do bilhete do passageiro para o voo para o qual pretende realizar check-in
     */
    void realizarCheckIn(unsigned bId) const;
    /**
     *
     * @param cidadeChegada é a cidade de destino
     * @param d1 é a data
     * @return voos que vão aterrar numa determinada cidade numa determinada data
     */
    vector<Voo> getVoosChegada (const string& cidadeChegada, const Data& d1=Data()) const;
    /**
     *
     * @param cidadePartida é a cidade de origem
     * @param d1 é a data
     * @return voos que vão partir de uma determinada cidade numa determinada data
     */
    vector <Voo> getVoosPartida (const string& cidadePartida, const Data& d1=Data()) const;
    /**
     *
     * @param cidadePartida é a cidade de origem
     * @param cidadeChegada é a cidade de destino
     * @param d1 é uma data
     * @param d2 é uma data
     * @return voos que vão ser realizados de uma determinada cidade para outra entre duas determinadas datas
     */
    vector <Voo> getVoosCidades (const string& cidadePartida, const string& cidadeChegada, const Data& d1, const Data& d2) const;
    /**
     *
     * @param d1 é uma data
     * @param d2 é uma data
     * @return todos os voos que vão ser realizados entre duas determinadas datas
     */
    vector <Voo> getVoosDatas (const Data& d1, const Data& d2=Data()) const;
    /**
     * Mostra todos os voos que vão aterrar numa determinada cidade numa determinada data
     */
    void showVoos() const;
    /**
     * Mostra os voos que vão partir de uma determinada cidade numa determinada data
     * @param cidadePartida é a cidade de origem
     * @param d1 é a data
     */
    void showVoosPartida (const string& cidadePartida, const Data& d1=Data()) const;
    /**
     * Mostra os voos que vão aterrar numa determinada cidade numa determinada data
     * @param cidadeChegada é a cidade de destino
     * @param d1  é a data
     */
    void showVoosChegada(const string& cidadeChegada, const Data& d1=Data()) const;
    /**
     * Mostra os voos que vão ser realizados entre duas determinadas datas
     * @param cidadePartida é a cidade de origem
     * @param cidadeChegada é a cidade de destino
     * @param d1 é uma data
     * @param d2 é uma data
     */
    void showVoosCidades(const string& cidadePartida, const string& cidadeChegada, const Data& d1, const Data& d2) const;
    /**
     * Mostra todos os voos que vão ser realizados entre duas determinadas datas
     * @param d1 é uma data
     * @param d2 é uma data
     */
    void showVoosDatas(const Data& d1, const Data& d2=Data()) const;
    /**
     *
     * @param ficheiroAvioes é o nome de um ficheiro com os aviões
     * @param ficheiroVoos é o nome de um ficheiro com os voos
     * @param ficheiroBilhetes é o nome de um ficheiro com os bilhetes
     */
    void loadData(string ficheiroAvioes, string ficheiroVoos, string ficheiroBilhetes);
};

#endif //_COMPANHIAAEREA_H
