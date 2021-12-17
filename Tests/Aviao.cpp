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

Aviao::Aviao(const string& m, unsigned c, const list<Voo>& planVoo, const queue<Servico>& servRealizar) {
    this->matricula = m;
    this->capacidade = c;
    this->planoDeVoo = planVoo;
    this->servicosPorRealizar = servRealizar;
    this->servicosRealizados = queue<Servico>();
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

bool Aviao::addServicoPorRealizar(const Servico& servico) {
    if (servicosPorRealizar.empty() || servicosPorRealizar.back().getData() < servico.getData()) {
        this->servicosPorRealizar.push(servico);
        return true;
    }
    return false;
}

bool Aviao::realizarServico (){
    if (servicosPorRealizar.empty())
        return false;
    this->servicosRealizados.push(servicosPorRealizar.front());
    this->servicosPorRealizar.pop();
    return true;
}
