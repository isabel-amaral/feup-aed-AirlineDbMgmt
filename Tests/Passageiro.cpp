#include "Passageiro.h"
#include <iostream>

Passageiro::Passageiro() {
    this->nome = "";
    this->id = 0;
    this->idade = 0;
    this->menorNaoAcompanhado = false;
}

Passageiro::Passageiro(const string& n, unsigned id, unsigned i, bool menor, const list<Bagagem*>& b) {
    this->nome = n;
    this->id = id;
    this->idade = i;
    if (idade >= 18)
        this->menorNaoAcompanhado = false;
    else
        this->menorNaoAcompanhado = menor;
    this->bagagem = b;
}

string Passageiro::getNome() const {
    return this->nome;
}

unsigned Passageiro::getId() const {
    return this->id;
}


unsigned Passageiro::getIdade() const {
    return idade;
}

bool Passageiro::isMenorNaoAcompanhado() const {
    return menorNaoAcompanhado;
}

const list<Bagagem*>& Passageiro::getBagagem() const {
    return bagagem;
}

void Passageiro::setBagagem(const list<Bagagem*>& b) {
    this->bagagem = b;
}

