#include "Aviao.h"
using namespace std;

Aviao::Aviao(string m, unsigned int c, unsigned int nlr){
    this->matricula=m;
    this->capacidade=c;
    this->numLugaresReservados=nlr;
}

string Aviao::getMatricula() const {return matricula; }

unsigned int Aviao::getCapacidade() const {return capacidade; }

unsigned int Aviao::getNumLugaresReservados() const {return numLugaresReservados; }

void Aviao::setMatricula(string m) {
    this->matricula=m;
}

void Aviao::setCapacidade(unsigned int c) {
    this->capacidade=c;
}

void Aviao::setNumLugaresReservados(unsigned int lugares) {
    this->numLugaresReservados=lugares;
}

