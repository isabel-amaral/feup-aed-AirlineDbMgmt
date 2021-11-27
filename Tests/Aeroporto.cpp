#include "Aeroporto.h"
using namespace std;

Aeroporto::Aeroporto() {
    this->nome = "";
    this->cidade = "";
    this->voos = {};
}

Aeroporto::Aeroporto(string n, string c) {
    this->nome = n;
    this->cidade = c;
}

string Aeroporto::getNome() const {
    return nome;
}

string Aeroporto::getCidade() const {
    return cidade;
}

list<Voo> Aeroporto::getVoos() const {
    return voos;
}

void Aeroporto::setNome(const string &n) {
    this->nome = nome;
}

void Aeroporto::setCidade(const string &c) {
    this->cidade = c;
}

void Aeroporto::setVoos(const list<Voo> &v) {
    this->voos = v;
}