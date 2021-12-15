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
     * nome do aeroporto
     */
    string nome;
    /**
     * cidade onde o aeroporto se localiza
     */
    string cidade;
    /**
     * transportes disponiveis na cidade onde o aeroporto se localiza
     */
     BST<LocalDeTransporte*> transportes;

public:
    Aeroporto();
    Aeroporto(const string& n, const string& c);
    /**
     *
     * @return nome do aeroporto
     */
    string getNome() const;
    /**
     *
     * @return cidade do aeroporto
     */
    string getCidade() const;
    /*
    void setNome(const string &nome);
    void setCidade(const string &cidade);
    void setVoosPartida(const list<Voo> &v);
    void setVoosChegada(const list<Voo> &v);
    */
    /**
     *
     * @return árvore binária com os locais de transportes próximos do aeroporto
     */
    BST<LocalDeTransporte*> getTransportes() const; //sofia: acrescentei pq precisei para os testes
    /**
     * Acrescenta um novo local de transporte à lista
     * @param lp é o novo local de transporte
     */
    void addTransporte (LocalDeTransporte* lp);
    /**
     * @return local de transporte mais próximo
     */
    LocalDeTransporte* getLocalTransporteProximo();
    /**
     * @return local de Metro mais próximo do aeroporto
     */
    LocalDeTransporte* getMetroProximo();
    /**
     *
     * @return local de Comboio mais próximo do aeroporto
    */
    LocalDeTransporte* getComboioProximo();
    /**
     * @return local de Autocarro mais próximo do aeroporto
     */
    LocalDeTransporte* getAutocarroProximo();
    /**
     * Mostra os detalhes sobre o local de transporte mais próximo, caso exista
     */
    void showLocalTransporteProximo();
    /**
     * Mostra detalhes sobre o Metro mais próximo, caso exista
     */
    void showMetroProximo();
    /**
     * Mostra detalhes sobre o Comboio mais próximo, caso exista
     */
    void showComboioProximo();
    /**
     * Mostra detalhes sobre o Autocarro mais próximo, caso exista
     */
    void showAutocarroProximo();
};

#endif //_AEROPORTO_H