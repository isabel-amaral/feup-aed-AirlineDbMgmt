#include "Voo.h"
using namespace std;

//isabel: tive de implementar o construtor defualt para conseguir fazer build
Voo::Voo() {
    num = 0;
    partida = "";
    chegada = "";
    duracao = "";
    origem = "";
    destino = "";
}

Voo::Voo(int n, string o, string p, string d, string c, string dur) {
    this->num = n;
    this->origem = o;
    this->partida = p;
    this->destino = d;
    this->chegada = c;
    this->duracao = dur;
}

int Voo::getNum() const {
    return num;
}

string Voo::getPartida() const {
    return partida;
}

string Voo::getChegada() const {
    return chegada;
}

string Voo::getDuracao() const {
    return duracao;
}

string Voo::getOrigem() const {
    return origem;
}

string Voo::getDestino() const {
    return destino;
}

void Voo::setNum(const int &n) {
    num = n;
}

void Voo::setOrigem(const string &o) {
    origem = o;
}

void Voo::setPartida(const string &p) {
    partida = p;
}

void Voo::setDestino(const string &d) {
    destino = d;
}

void Voo::setChegada(const string &c) {
    chegada = c;
}

void Voo::setDuracao(const string &dur) {
    duracao = dur;
}


