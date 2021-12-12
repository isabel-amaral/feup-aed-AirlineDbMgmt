#include "Servico.h"

Servico::Servico() {
    tipoServico = "";
    data = "";
    funcionarioResponsavel = Funcionario();
}

Servico::Servico(string tipo, string d, Funcionario& funcionario) {
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

const Funcionario& Servico::getFuncionarioResponsavel() {
    return this->funcionarioResponsavel;
}

void Servico::setTipoServico(string& tipo) {
    this->tipoServico = tipo;
}

void Servico::setData(string& d) {
    this->data = d;
}
void Servico::setFuncionarioResponsavel(const Funcionario& f) {
    this->funcionarioResponsavel = f;
}
