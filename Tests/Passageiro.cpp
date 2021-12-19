#include "Passageiro.h"

Passageiro::Passageiro() {
    this->nome = "";
    this->id = 0;
    this->idade = 0;
    this->menorNaoAcompanhado = false;
}

Passageiro::Passageiro(const string& n, unsigned id, unsigned i, bool menor) {
    this->nome = n;
    this->id = id;
    this->idade = i;
    if (idade >= 18)
        this->menorNaoAcompanhado = false;
    else
        this->menorNaoAcompanhado = menor;
    multaBagagem = 0.0;
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

float Passageiro::getMultaBagagem() const {
    return multaBagagem;
}

void Passageiro::incrementarMulta(float multa) {
    multaBagagem += multa;
}

bool Passageiro::operator==(const Passageiro &p) const {
    return this->id == p.getId();
}

ostream &operator << (ostream &os, const Passageiro &p) {
    os << "NOME: " << p.getNome() << endl;
    os << "IDENTIFICAÇÃO: " << p.getId() << endl;
    os << "IDADE: " << p.getIdade() << endl;
    if (p.menorNaoAcompanhado){
        os << "OBS.: Menor de idade e não acompanhado." << endl;
    }
    return os;
}
