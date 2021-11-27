#include "Aeroporto.h"
using namespace std;

Aeroporto::Aeroporto() {
    this->nome = "";
    this->cidade = "";
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

void Aeroporto::setNome(const string &n) {
    this->nome = nome;
}

void Aeroporto::setCidade(const string &c) {
    this->cidade = c;
}
