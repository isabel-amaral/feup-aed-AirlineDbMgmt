#include "Voo.h"
using namespace std;

Voo::Voo() {
    numeroVoo = 0;
    origem = Aeroporto();
    destino = Aeroporto();
    dataPartida = Data();
    horaPartida = 0.0;
    horaChegada = 0.0;
    duracao = 0.0;
    lotacao = 0;
    numLugaresReservados = 0;
    passageiros = list<Passageiro>();
    passageirosCheckedIn = list<Passageiro>();
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

list<Passageiro> Voo::getPassageiros() const {
    return passageiros;
}

list<Passageiro> Voo::getPassageirosCheckedIn() const {
    return passageirosCheckedIn;
}

TransportadorDeBagagem Voo::getTransportador() const {
    return transportador;
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

bool Voo::addPassageiro(const Passageiro& b) {
    if (numLugaresReservados == lotacao)
        return false;
    passageiros.push_back(b);
    numLugaresReservados++;
    return true;
}

bool Voo::addConjuntoPassageiros(const list<Passageiro> &b) {
    if (numLugaresReservados + (unsigned)b.size() > lotacao)
        return false;

    list<Passageiro>::const_iterator it;
    for (it = b.begin(); it != b.end(); it++) {
        passageiros.push_back(*it);
        numLugaresReservados++;
    }
    return true;
}

void Voo::realizarCheckIn(const Passageiro& p) {
    passageirosCheckedIn.push_back(p);
}

bool Voo::operator<(const Voo &v) const {
    if (this->dataPartida < v.dataPartida)
        return true;
    else if (this->dataPartida == v.dataPartida){
        if ( this->horaPartida == v.horaPartida)
            return this->getOrigem().getCidade() < v.getOrigem().getCidade();
        else
            return this->horaPartida < v.horaPartida;
    }
    return false;

}

ostream &operator<<(ostream &os, const Voo &v) {
    os << "Voo número " << v.getNumeroVoo() << endl;
    os << "Partida prevista às " << v.getHoraPartida() << " com chegada prevista às " << v.getHoraChegada() << endl;
    os << " no dia " << v.getDataPartida().getData() << endl;
    os << "A duração do voo será aproximadamente " << v.getDuracao() << endl;
    return os;
}


