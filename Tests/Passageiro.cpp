#include "Passageiro.h"

Passageiro::Passageiro(string n, int id) {
    this->nome = n;
    this->id = id;
}

string Passageiro::getNome() const {
    return this->nome;
}

int Passageiro::getId() const {
    return this->id;
}

void Passageiro::adquirirBilhete(Bilhete& bilhete) {
    this->bilhetesAdquiridos.push_back(bilhete);
}