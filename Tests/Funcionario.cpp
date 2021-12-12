#include "Funcionario.h"

Funcionario::Funcionario() {
    this->idFuncionario = 0;
    this->nomeFuncionario = "";
}

Funcionario::Funcionario(unsigned id, string n) {
    this->idFuncionario = id;
    this->nomeFuncionario = n;
}

unsigned Funcionario::getIdFuncionario() const {
    return idFuncionario;
}

string Funcionario::getNomeFuncionario() const {
    return nomeFuncionario;
}

void Funcionario::setIdFuncionario(unsigned idFuncionario) {
    this->idFuncionario = idFuncionario;
}

void Funcionario::setNomeFuncionario(const string &nomeFuncionario) {
    this->nomeFuncionario = nomeFuncionario;
}
