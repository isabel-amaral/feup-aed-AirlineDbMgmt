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

Aviao::Aviao(const string& m, unsigned c) {
    this->matricula = m;
    this->capacidade = c;
    /*
    this->planoDeVoo = planVoo;
    this->servicosPorRealizar = servPorRealizar;
    this->servicosRealizados = servRealizados;*/
}

string Aviao::getMatricula() const {
    return this->matricula;
}

unsigned Aviao::getCapacidade() const {
    return this->capacidade;
}

list<Voo> Aviao::getPlanoDeVoo() const {
    return this->planoDeVoo;
}

queue<Servico> Aviao::getServicosPorRealizar() const {
    return this->servicosPorRealizar;
}

queue<Servico> Aviao::getServicosRealizados() const{
    return this->servicosRealizados;
}

void Aviao::setMatricula(const string& m) {
    this->matricula=m;
}

void Aviao::setCapacidade(const unsigned& c) {
    this->capacidade=c;
}

void Aviao::setPlanoDeVoo(const list<Voo>& planVoo) {
    this->planoDeVoo = planVoo;
}

void Aviao::setServicosPorRealizar(const queue<Servico>& servPorRealizar) {
    this->servicosPorRealizar = servPorRealizar;
}

void Aviao::setServicosRealizados(const queue<Servico>& servRealizados) {
    this->servicosRealizados = servRealizados;
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
