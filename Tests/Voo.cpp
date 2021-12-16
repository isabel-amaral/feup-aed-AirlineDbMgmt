#include "Voo.h"
using namespace std;

Voo::Voo() {
    numeroVoo = 0;
    dataPartida = Data();
    horaPartida = 0.0;
    horaChegada = 0.0;
    duracao = 0.0;
    origem = Aeroporto();
    destino = Aeroporto();
    numLugaresReservados = 0;
}

Voo::Voo(unsigned n, const Aeroporto& ao, const Aeroporto& ad, const Data& dp, float hp, float hc, float d, unsigned l, unsigned nlr) {
    this->numeroVoo = n;
    this->origem = ao;
    this->destino = ad;
    this->dataPartida = dp;
    this->horaPartida = hp;
    this->horaChegada = hc;
    this->duracao = d;
    this->lotacao = l;
    this->numLugaresReservados = nlr;
    this->passageiros = list<Passageiro>();
    this->passageirosCheckedIn = list<Passageiro>();
}

unsigned Voo::getNumeroVoo() const {
    return numeroVoo;
}

Data Voo::getDataPartida() const {
    return dataPartida;
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

unsigned int Voo::getLotacao() const {
    return lotacao;
}

unsigned Voo::getNumLugaresReservados() const {
    return numLugaresReservados;
}

const list<Passageiro>& Voo::getPassageiros() const {
    return passageiros;
}

void Voo::setNumeroVoo(unsigned n) {
    numeroVoo = n;
}

void Voo::setOrigem(const Aeroporto& ao) {
    origem = ao;
}

void Voo::setDataPartida(const Data& dp) {
    dataPartida = dp;
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

void Voo::setLotacao(unsigned lotacao) {
    lotacao = lotacao;
}

void Voo::setNumLugaresReservados(unsigned lr) {
    this->numLugaresReservados = lr;
}

//transportador apenas será requisitado no dia do voo
void Voo::setTransportador(unsigned int c, unsigned int n, unsigned int m) {
    this->transportador = TransportadorDeBagagem(c, n, m);
}

bool Voo::addPassageiro(const Passageiro& p) {
    if (numLugaresReservados == lotacao)
        return false;
    passageiros.push_back(p);
    numLugaresReservados++;
    return true;
}

bool Voo::addConjuntoPassageiros(const list<Passageiro> &p) {
    if (numLugaresReservados + (unsigned)p.size() > lotacao)
        return false;

    list<Passageiro>::const_iterator it;
    for (it = p.begin(); it != p.end(); it++) {
        passageiros.push_back(*it);
        numLugaresReservados++;
    }
    return true;
}

/*void Voo::realizarCheckIn(const Passageiro& p) {
    //acrescentar restrições de peso, o que acontece se o passageiro tiver bagagem de mão e o seu bilhete não permitir?
    list<Bagagem*>::const_iterator it;
    for (it = p.getBagagem().begin(); it != p.getBagagem().end(); it++)
        if (!(*it)->isBagagemDeMao() && (*it)->isCheckInAutomatico())
            transportador.adicionarAoTapete(*it);
    passageirosCheckedIn.push_back(p);
}*/
