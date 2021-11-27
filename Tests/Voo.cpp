#include "Voo.h"
using namespace std;

//isabel: tive de implementar o construtor defualt para conseguir fazer build
Voo::Voo() {
    num = 0;
    partida = "";
    chegada = "";
    duracao = "";
    origem = Aeroporto();
    destino = Aeroporto();
    aviao = Aviao();
}

Voo::Voo(unsigned int n, Aeroporto ao, string p, Aeroporto ad, string c, string d, Aviao a) {
    this->num = n;
    this->origem = ao;
    this->partida = p;
    this->destino = ad;
    this->chegada = c;
    this->duracao = d;
    this->aviao = a;
}

Voo::Voo(const Voo &v2) {
    this->num = v2.num;
    this->origem = v2.origem;
    this->partida = v2.partida;
    this->destino = v2.destino;
    this->chegada = v2.chegada;
    this->duracao = v2.duracao;
    this->aviao = v2.aviao;
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

Aeroporto Voo::getOrigem() const {
    return origem;
}

Aeroporto Voo::getDestino() const {
    return destino;
}

Aviao Voo::getAviao() const {
    return aviao;
}

void Voo::setNum(const unsigned int &n) {
    num = n;
}

void Voo::setOrigem(const Aeroporto &ao) {
    origem = ao;
}

void Voo::setPartida(const string &p) {
    partida = p;
}

void Voo::setDestino(const Aeroporto &ad) {
    destino = ad;
}

void Voo::setChegada(const string &c) {
    chegada = c;
}

void Voo::setDuracao(const string &d) {
    duracao = d;
}

void Voo::setAviao(const Aviao &a) {
    this->aviao = a;
}