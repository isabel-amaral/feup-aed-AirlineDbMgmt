#ifndef _AEROPORTO_H
#define _AEROPORTO_H

#include <string>
#include <list>
#include "LocalDeTransporte.h"
#include "bst.h"
using namespace std;

class Aeroporto {
private:
    /**
     * Nome do aeroporto.
     */
    string nome;
    /**
     * Cidade onde o aeroporto se localiza.
     */
    string cidade;
    /**
     * Transportes disponiveis na cidade onde o aeroporto se localiza.
     */
     BST<LocalDeTransporte> transportes;

public:
    Aeroporto();
    Aeroporto(const string& n, const string& c);
    /**
     *
     * @return nome do aeroporto.
     */
    string getNome() const;
    /**
     *
     * @return cidade do aeroporto.
     */
    string getCidade() const;
    /**
     *
     * @return árvore binária com os locais de transportes próximos do aeroporto.
     */
    BST<LocalDeTransporte> getTransportes() const;
    /*
    void setNome(const string &nome);
    void setCidade(const string &cidade);
    */
    /**
     * Acrescenta um novo local de transporte à lista.
     * @param lp é o novo local de transporte.
     */
    void addTransporte (const LocalDeTransporte& lp);
    /**
     * @return local de transporte mais próximo, caso exista algum.
     */
    LocalDeTransporte getLocalTransporteProximo() const;
    /**
    *
    * @return todos os locais de metro da cidade, caso existam na mesma.
    */
    vector<LocalDeTransporte> getMetros() const;
    /**
     *
     * @return todos locais de Comboio da cidade, caso existam na mesma.
     */
    vector<LocalDeTransporte> getComboios() const;
    /**
     *
     * @return todos locais de Autocarro da cidade, caso existam na mesma.
     */
    vector<LocalDeTransporte> getAutocarros() const;
    /**
     * @return local de Metro mais próximo do aeroporto, caso exista algum Metro na cidade em questão.
     */
    LocalDeTransporte getMetroProximo() const;
    /**
     *
     * @return local de Comboio mais próximo do aeroporto, caso exista algum Comboio na cidade em questão.
    */
    LocalDeTransporte getComboioProximo() const;
    /**
     * @return local de Autocarro mais próximo do aeroporto, caso exista algum Autocarro na ciade em questão.
     */
    LocalDeTransporte getAutocarroProximo() const;
    /**
     * Imprime na tela todos os meios de transporte terrestre disponíveis segundo uma ordenação escolhida pelo utilizador.
     * @param ordenacao é o critério escolhido pelo utilizador.
     */
    void showTransportes(int ordenacao) const;
    /**
     * Imprime na tela todos os locais de Metro disponíveis na cidade, segundo uma ordenação escolhida pelo utilizador.
     * @param ordenacao é o critério escolhido pelo utilizador.
     */
    void showMetros(int ordenacao) const;
    /**
     * Imprime na tela todos os locais de Comboio disponíveis na cidade, segundo uma ordenação escolhida pelo utilizador.
     * @param ordenacao é o critério escolhido pelo utilizador.
     */
    void showComboios(int ordenacao) const;
    /**
     * Imprime na tela todos os locais de Autocarro disponíveis na cidade, segundo uma ordenação escolhida pelo utilizador.
     * @param ordenacao é o critério escolhido pelo utilizador.
     */
    void showAutocaros(int ordenacao) const;
    /**
     * Imprime os detalhes sobre o local de transporte mais próximo.
     */
    void showLocalTransporteProximo() const;
    /**
     * Imprime os detalhes sobre o Metro mais próximo.
     */
    void showMetroProximo() const;
    /**
     * Imprime os detalhes sobre o Comboio mais próximo.
     */
    void showComboioProximo() const;
    /**
     * Imprime os detalhes sobre o Autocarro mais próximo.
     */
    void showAutocarroProximo() const;
    /**
     * Um aeroporto é tanto menor quanto menor é o seu nome.
     * @param a1 é o aeroporto a ser comparado com esta instância.
     * @return true se a1 é maior que esta instância.
     */
    bool operator <(const Aeroporto& a1) const;
    /**
    * Critério de ordenação de transportes terrestres por ordem decrescente de diponibilidade,
    * em caso de empate, os locais são ordenados por distância (ordem crescente), caso haja empate,
    * são ordenados pelo tipo seguindo o critério Metro < Comboio < Autocarro.
    * @param l1 é um local de transporte
    * @param l2 é outro local de transporte
    * @return true se l1 < l2 de acordo com o critério, caso contrário false.
    */
    static bool criterioComparacao2 (const LocalDeTransporte& l1, const LocalDeTransporte& l2 );
    /**
     * Critério de ordenação de transportes terrestres por tipo seguindo o critério Metro < Comboio < Autocarro,
     * em caso de empate, os locais são ordenados por distância (distância), caso haja empate,
     * são ordenados por ordem decrescente de disponibilidade.
     * @param l1 é um local de transporte
     * @param l2 é outro local de transporte
     * @return true se l1 < l2 de acordo com o critério, caso contrário false.
     */
    static bool criterioComparacao3 (const LocalDeTransporte& l1, const LocalDeTransporte& l2);
    /**
     * Ordena um conjunto de locais de transporte segundo um critério específico
     * @param locais conjunto de locais a ordenar
     * @param ordenacao critério a ser utilizado na ordenação
     */
    vector<LocalDeTransporte> ordenarLocais(const vector<LocalDeTransporte>& locais, const int ordenacao) const;
};

#endif //_AEROPORTO_H