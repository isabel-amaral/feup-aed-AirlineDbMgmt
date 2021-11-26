#include "Passageiro.h"

Passageiro::Passageiro(string n, int id) {
    nome = n;
    this->id = id;
}

string Passageiro::getNome() const {
    return nome;
}

int Passageiro::getId() const {
    return id;
}
