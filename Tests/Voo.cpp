#include "Voo.h"
using namespace std;

Voo::Voo() {
    numeroVoo = 0;
    horaPartida = 0.0;
    horaChegada = 0.0;
    duracao = 0.0;
    origem = Aeroporto();
    destino = Aeroporto();
    aviao = Aviao();
    numLugaresReservados = 0;
}

Voo::Voo(unsigned int n, Aeroporto& ao, Aeroporto& ad, float hp, float hc, float d, Aviao& a, unsigned int nlr) {
    this->numeroVoo = n;
    this->origem = ao;
    this->destino = ad;
    this->horaPartida = hp;
    this->horaChegada = hc;
    this->duracao = d;
    this->aviao = a;
    this->numLugaresReservados = nlr;
}

Voo::Voo(const Voo& v) {
    this->numeroVoo = v.numeroVoo;
    this->origem = v.origem;
    this->horaPartida = v.horaPartida;
    this->destino = v.destino;
    this->horaChegada = v.horaChegada;
    this->duracao = v.duracao;
    this->aviao = v.aviao;
}

int Voo::getNum() const {
    return numeroVoo;
}

float Voo::getHoraPartida() const {
    return horaPartida;
}

float Voo::getHoraChegada() const {
    return horaChegada;
}

float Voo::getDuracao() const {
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

unsigned int Voo::getNumLugaresReservados() const {
    return numLugaresReservados;
}

void Voo::setNum(const unsigned int& n) {
    numeroVoo = n;
}

void Voo::setOrigem(const Aeroporto& ao) {
    origem = ao;
}

void Voo::setHoraPartida(const float p) {
    horaPartida = p;
}

void Voo::setDestino(const Aeroporto& ad) {
    destino = ad;
}

void Voo::setHoraChegada(const float c) {
    horaChegada = c;
}

void Voo::setDuracao(const float d) {
    duracao = d;
}

void Voo::setAviao(const Aviao& a) {
    this->aviao = a;
}

void Voo::setNumLugaresReservados(const unsigned int& lr) {
    this->numLugaresReservados = lr;
}