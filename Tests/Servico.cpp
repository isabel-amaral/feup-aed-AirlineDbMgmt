#include "Servico.h"

Servico::Servico(string tipo, string d, string funcionario) {
    tipoServico = tipo;
    data = d;
    funcionarioResponsavel = funcionario;
}

string Servico::getTipoServico() {
    return tipoServico;
}

string Servico::getData() {
    return data;
}

string Servico::getFuncionarioResponsavel() {
    return funcionarioResponsavel;
}

void Servico::setTipoServico(string tipo) {
    tipoServico = tipo;
}

void Servico::setData(string d) {
    data = d;
}
void Servico::setFuncionarioResponsavel(string funcionario) {
    funcionarioResponsavel = funcionario;
}
