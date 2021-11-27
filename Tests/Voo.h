#ifndef _VOO_H
#define _VOO_H

#include "Aeroporto.h"
#include "Aviao.h"
#include <string>
using namespace std;

class Voo {
private:
    unsigned int num; //isabel: acho que ficava melhor se o nome da variável fosse qualuqer coisa como numeroDeVoo
    // sofia: cm estamos na classe voo ja ano é obvio que o numero e o de voo? dps quando usarmos voo.numerodeVoo nao fica um bocado repetitivo?
    string partida;
    string chegada;
    string duracao; // sofia: string?
    Aeroporto origem;
    Aeroporto destino;
    Aviao aviao;
    // hora de partida e chegada? isabel: acho que as horas devíamos representar em float
public:
    Voo();
    Voo(unsigned int n, Aeroporto ao, string p, Aeroporto ad, string c, string d, Aviao a);
    Voo(const Voo &v2);
    int getNum() const;
    Aeroporto getOrigem() const;
    string getPartida() const;
    Aeroporto getDestino() const;
    string getChegada() const;
    string getDuracao() const;
    Aviao getAviao() const;
    void setNum(const unsigned int &n);
    void setOrigem(const Aeroporto &ao);
    void setPartida(const string &p);
    void setDestino(const Aeroporto &ad);
    void setChegada(const string &c);
    void setDuracao(const string &dur);
    void setAviao(const Aviao &a);
};

#endif //_VOO_H