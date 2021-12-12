#include "Passageiro.h"
#include <iostream>

Passageiro::Passageiro(string n, unsigned id, unsigned i, bool menor) {
    this->nome = n;
    this->id = id;
    this->idade = i;
    if (idade >= 18)
        this->menorNaoAcompanhado = false;
    else
        this->menorNaoAcompanhado = menor;
}

string Passageiro::getNome() const {
    return this->nome;
}

int Passageiro::getId() const {
    return this->id;
}


unsigned int Passageiro::getIdade() const {
    return idade;
}

bool Passageiro::isMenorNaoAcompanhado() const {
    return menorNaoAcompanhado;
}

void Passageiro::mostrarBilehtesAdquiridos() const {
/*    list<Bilhete>::const_iterator it;
    for (it = bilhetesAdquiridos.begin(); it != bilhetesAdquiridos.end(); it++) {
        //necessário alterar depois da classe aeroporto estar associada à classe voo
        cout << "Bilhete para " << it->getVoo().getDestino() << " com partida de " << it->getVoo().getOrigem() << endl;
        cout << "Voo número " << it->getVoo().getNum() << endl;
        //data do voo
        cout << "Partida presvista às " << it->getVoo().getPartida() << " com chegada prevista às " << it->getVoo().getChegada() << endl;
        cout << "A duração do voo será aproximadamente " << it->getVoo().getDuracao() << endl;
        if (it->temBagagemDeMao())
            cout << this->nome << " tem direito a levar bagagem de mão" << endl;
        else
            cout << this->nome << " não tem direito a levar bagagem de mão" << endl;
        cout << endl;*/
    }
}

void Passageiro::adquirirBilhete(Bilhete& bilhete) {
    this->bilhetesAdquiridos.push_back(bilhete);
}
