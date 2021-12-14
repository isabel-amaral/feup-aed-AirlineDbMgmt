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
     BST<LocalDeTransporte> transportes;

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


    //list<LocalDeTransporte> getTransportes() const;
    void addTransporte (const LocalDeTransporte &lp);
    LocalDeTransporte getMeioTransporteProximo();
    LocalDeTransporte getMetroProximo();
    LocalDeTransporte getComboioProximo();
    LocalDeTransporte getAutocarroProximo();

    void showMeioTransporteProximo();
    void showMetroProximo();
    void showComboioProximo();
    void showAutocarroProximo();
};

#endif //_AEROPORTO_H