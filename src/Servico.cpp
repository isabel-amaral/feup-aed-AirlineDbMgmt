#include "Servico.h"

Servico::Servico() {
    tipoServico = Limpeza;
    data = Data();
    funcionarioResponsavel = Funcionario();
}

Servico::Servico(TipoServico tipo, const Data& d, Funcionario& funcionario) {
    this->tipoServico = tipo;
    this->data = d;
    this->funcionarioResponsavel = funcionario;
}

TipoServico Servico::getTipoServico() const {
    return this->tipoServico;
}

Data Servico::getData() const {
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


ostream &operator<<(ostream &os, const Servico &s) {
    os << "Tipo: ";
    if (s.getTipoServico() == Limpeza)
        os << "Limpeza" << endl;
    else
        os << "Manutencao" << endl;
    os << "Data de realizacao: " ;
    os << s.getData().getData() << endl;
    os << "Funcionario Responsavel: " << s.getFuncionarioResponsavel().getNomeFuncionario();
    os << " (Id- " << s.getFuncionarioResponsavel().getIdFuncionario() << ")"  << endl;
    return os;
}


