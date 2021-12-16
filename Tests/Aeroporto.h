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
    void addTransporte (LocalDeTransporte lp);
    /**
     * @return local de transporte mais próximo, caso exista algum.
     */
    LocalDeTransporte getLocalTransporteProximo();
    /**
     * @return local de Metro mais próximo do aeroporto, caso exista algum Metro na cidade em questão.
     */
    LocalDeTransporte getMetroProximo();
    /**
     *
     * @return local de Comboio mais próximo do aeroporto, caso exista algum Comboio na cidade em questão.
    */
    LocalDeTransporte getComboioProximo();
    /**
     * @return local de Autocarro mais próximo do aeroporto, caso exista algum Autocarro na ciade em questão.
     */
    LocalDeTransporte getAutocarroProximo();
    /**
     * Imprime os detalhes sobre o local de transporte mais próximo, caso exista.
     */
    void showLocalTransporteProximo();
    /**
     * Imprime os detalhes sobre o Metro mais próximo, caso exista.
     */
    void showMetroProximo();
    /**
     * Imprime os detalhes sobre o Comboio mais próximo, caso exista.
     */
    void showComboioProximo();
    /**
     * Imprime os detalhes sobre o Autocarro mais próximo, caso exista.
     */
    void showAutocarroProximo();
};

#endif //_AEROPORTO_H