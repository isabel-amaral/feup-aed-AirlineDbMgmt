#include "Servico.h"

Servico::Servico() {
    tipoServico = Limpeza;
    data = Data();
    funcionarioResponsavel = Funcionario();
}

Servico::Servico(TipoServico tipo, Data d, Funcionario& funcionario) {
    this->tipoServico = tipo;
    this->data = d;
    this->funcionarioResponsavel = funcionario;
}

TipoServico Servico::getTipoServico() {
    return this->tipoServico;
}

Data Servico::getData() {
    return this->data;
}

Funcionario Servico::getFuncionarioResponsavel() const {
    return this->funcionarioResponsavel;
}

void Servico::setTipoServico(TipoServico tipo) {
    this->tipoServico = tipo;
}

void Servico::setData(const Data& d) {
    this->data = d;
}
void Servico::setFuncionarioResponsavel(const Funcionario& f) {
    this->funcionarioResponsavel = f;
}
