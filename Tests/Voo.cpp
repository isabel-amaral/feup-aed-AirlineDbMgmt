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

Voo::Voo(unsigned n, const Aeroporto& ao, const Aeroporto& ad, float hp, float hc, float d, const Aviao& a, unsigned nlr) {
    this->numeroVoo = n;
    this->origem = ao;
    this->destino = ad;
    this->horaPartida = hp;
    this->horaChegada = hc;
    this->duracao = d;
    this->aviao = a;
    this->numLugaresReservados = nlr;
    this->passageiros = list<Passageiro>();
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

unsigned Voo::getNumeroVoo() const {
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

const Aeroporto& Voo::getOrigem() const {
    return origem;
}

const Aeroporto& Voo::getDestino() const {
    return destino;
}

const Aviao& Voo::getAviao() const {
    return aviao;
}

unsigned Voo::getNumLugaresReservados() const {
    return numLugaresReservados;
}

void Voo::setNumeroVoo(unsigned n) {
    numeroVoo = n;
}

void Voo::setOrigem(const Aeroporto& ao) {
    origem = ao;
}

void Voo::setHoraPartida(float p) {
    horaPartida = p;
}

void Voo::setDestino(const Aeroporto& ad) {
    destino = ad;
}

void Voo::setHoraChegada(float c) {
    horaChegada = c;
}

void Voo::setDuracao(float d) {
    duracao = d;
}

void Voo::setAviao(const Aviao& a) {
    this->aviao = a;
}

void Voo::setNumLugaresReservados(unsigned lr) {
    this->numLugaresReservados = lr;
}

const list<Passageiro>& Voo::getPassageiros() const {
    return passageiros;
}

bool Voo::addPassageiro(const Passageiro& p) {
    if (numLugaresReservados == aviao.getCapacidade)
        return false;
    passageiros.push_back(p);
    return true;
}