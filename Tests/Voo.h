#ifndef AIRLINEDATABASEMANAGEMENT_VOO_H
#define AIRLINEDATABASEMANAGEMENT_VOO_H

#include <string>
using namespace std;

class Voo {
private:
    int num; // unsigned?
    string partida;
    string chegada;
    string duracao; // string?
    string origem;
    string destino;
    // hora de partida e chegada?
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

#endif //AIRLINEDATABASEMANAGEMENT_VOO_H
