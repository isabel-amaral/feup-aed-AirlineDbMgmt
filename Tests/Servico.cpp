#include "Servico.h"

Servico::Servico(string tipo, string d, string funcionario) {
    this->tipoServico = tipo;
    this->data = d;
    this->funcionarioResponsavel = funcionario;
}

string Servico::getTipoServico() {
    return this->tipoServico;
}

string Servico::getData() {
    return this->data;
}

string Servico::getFuncionarioResponsavel() {
    return this->funcionarioResponsavel;
}

void Servico::setTipoServico(string& tipo) {
    this->tipoServico = tipo;
}

void Servico::setData(string& d) {
    this->data = d;
}
void Servico::setFuncionarioResponsavel(string& funcionario) {
    this->funcionarioResponsavel = funcionario;
}
