#ifndef _VOO_H
#define _VOO_H

#include <string>
using namespace std;

class Voo {
private:
    int num; // unsigned? isabel: sim unsigned e acho que ficava melhor se o nome da variável fosse qualuqer coisa como numeroDeVoo
    //isabel: essa partida e chegada são a data? se sim, tudo bem
    string partida;
    string chegada;
    string duracao; // string?
    //isabel: acho que a origem e o destino deviam ser alteradas para um aeroporto pq assim podemos aceder tanto ao nome do aeroporto como ao nome da cidade
    string origem;
    string destino;
    // hora de partida e chegada? isabel: acho que as horas devíamos representar em float
public:
    Voo();
    Voo(int n, string o, string p, string d, string c, string dur);
    int getNum() const;
    string getOrigem() const;
    string getPartida() const;
    string getDestino() const;
    string getChegada() const;
    string getDuracao() const;
    void setNum(const int &n);
    void setOrigem(const string &o);
    void setPartida(const string &p);
    void setDestino(const string &d);
    void setChegada(const string &c);
    void setDuracao(const string &dur);
};

#endif //_VOO_H
