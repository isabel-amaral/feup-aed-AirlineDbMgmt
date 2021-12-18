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
     * Objeto que contém as restrições de peso definidas pela companhia aérea e multas associadas
     */
    ExcessoPeso excessoPeso;
    list<Aviao> avioes;

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
     * @param p é um determinado passageiro.
     * @return  vector com todos os bilhetes adquiridos pelo passageiro (@param p) num vetor.
     * Caso este passageiro não tenha adquirido nenhum bilhete, será retornado um vetor vazio.
     */
    vector<Bilhete> getBilhetesFromPassageiro(const Passageiro& p) const;
    /**
     * Imprime os dados de cada um dos bilhetes de um determinado passageiro.
     * Caso o passageiro não tenha adquirido nenhum bilhete, é apresentada a
     * mensagem "Este passageiro ainda não adquiriu nenhum bilhete".
     * @param p é o passageiro.
     */
    void showBilhetesFromPassageiro(const Passageiro& p) const;
    /**
     *
     * @param v é um voo
     * @return todos os passageiros do voo indicado
     */
    vector<Passageiro> getPassageirosFromVoo(const Voo& v) const;
    /**
     * Imprime os dados do bilhete de cada passageiro que irá viajar no voo.
     * @param v é o voo para o qual se pretende obter a lista de passageiros com bilhete
     */
    void showPassageirosFromVoo(const Voo& v) const;
    /**
     * Retorna o bilhete de um dterminado passageiro para um determinado voo.
     * @param p passageiro em questão
     * @param v voo em questão
     * @return o bilhete do passageiro p para o voo v, objeto default caso o passageiro ainda não tenho adquirido bilhete para o voo
     */
    Bilhete getBilhetePassageiroVoo(const Passageiro& p, const Voo& v) const;
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
    bool cancelarViagem(const Passageiro& p, Voo& v);
    /**
     * Realiza o check-in de um determinado passageiro com bilhete referente a um certo voo
     * @param p
     * @param v
     */
    void realizarCheckIn(Passageiro& p, Voo& v) const;
    /**
     * Retorna os voos que chegam a uma determinada cidade num determinado dia.
     * @param cidadeChegada é a cidade em questão
     * @param d é a data em questão
     * @return voos que chegam à cidade em questão no dia d
     */
    vector<Voo> getVoosChegada(const string& cidadeChegada, const Data& d=Data()) const;
    /**
     * Retorna os voos que partem de uma determinada cidade num determinado dia.
     * @param cidadePartida é a cidade em quastão
     * @param d é a data em questão
     * @return voos que partem da cidade em questão no dia d
     */
    vector<Voo> getVoosPartida(const string& cidadePartida, const Data& d=Data()) const;
    //TODO: DOCUMENTACAO
    vector<Voo> getVoosCidades(const string& cidadePartida, const string& cidadeChegada, const Data& d1, const Data& d2) const;
    //TODO: DOCUMENTACAO
    vector<Voo> getVoosDatas(const Data& d1, const Data& d2=Data()) const;

    //TODO: DOCUMENTACAO
    void showVoos() const;
    //TODO: DOCUMENTACAO
    void showVoosPartida (const string& cidadePartida, const Data& d1=Data()) const;
    //TODO: DOCUMENTACAO
    void showVoosChegada(const string& cidadeChegada, const Data& d1=Data()) const;
    //TODO: DOCUMENTACAO
    void showVoosCidades(const string& cidadePartida, const string& cidadeChegada, const Data& d1, const Data& d2) const;
    //TODO: DOCUMENTACAO
    void showVoosDatas(const Data& d1, const Data& d2=Data()) const;
    //TODO: DOCUMENTACAO
    void loadData(string ficheiroAvioes, string ficheiroVoos, string ficheiroBilhetes);

};

#endif //_COMPANHIAAEREA_H
