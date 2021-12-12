#include "Aviao.h"
using namespace std;

Aviao::Aviao() {
    matricula = "";
    capacidade = 0;
    planoDeVoo.clear();
    while(!servicosPorRealizar.empty()) {
        servicosPorRealizar.pop();
    }
    while (!servicosRealizados.empty()) {
        servicosRealizados.pop();
    }
}

Aviao::Aviao(const string& m, unsigned c, const list<Voo>& planVoo, const queue<Servico>& servRealizados, const queue<Servico>& servPorRealizar) {
    this->matricula = m;
    this->capacidade = c;
    this->planoDeVoo = planVoo;
    this->servicosPorRealizar = servPorRealizar;
    this->servicosRealizados = servRealizados;
}

string Aviao::getMatricula() const {
    return this->matricula;
}

unsigned Aviao::getCapacidade() const {
    return this->capacidade;
}

const list<Voo>& Aviao::getPlanoDeVoo() const {
    return this->planoDeVoo;
}

const queue<Servico>& Aviao::getServicosPorRealizar() const {
    return this->servicosPorRealizar;
}

const queue<Servico>& Aviao::getServicosRealizados() const{
    return this->servicosRealizados;
}

void Aviao::setMatricula(const string& m) {
    this->matricula=matricula;
}

void Aviao::setCapacidade(const unsigned & c) {
    this->capacidade=capacidade;
}

void Aviao::setPlanoDeVoo(const list<Voo>& planVoo) {
    this->planoDeVoo = planoDeVoo;
}

void Aviao::setServicosPorRealizar(const queue<Servico>& servPorRealizar) {
    this->servicosPorRealizar = servicosPorRealizar;
}

void Aviao::setServicosRealizados(const queue<Servico>& servRealizados) {
    this->servicosRealizados = servicosRealizados;
}

void Aviao:: addVoo(const Voo& voo){
    this->planoDeVoo.push_back(voo);
}

void Aviao::addServicoPorRealizar(const Servico& servico) {
    this->servicosPorRealizar.push(servico);
}

void Aviao::realizarServico (){
    this->servicosRealizados.push(servicosPorRealizar.front());
    this->servicosPorRealizar.pop();
}
