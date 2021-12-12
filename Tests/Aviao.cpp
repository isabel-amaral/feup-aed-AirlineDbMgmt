#include "Aviao.h"
using namespace std;

Aviao::Aviao() {
    matricula = "";
    capacidade = 0;
    //milena: fiquei na duvida destas tres linhas de codigo; vi no fivheiro da TP5 (game()) e nao sei se é uma boa pratica
    //ou algo do genero; nao sei se é necessario colocar ou nao isabel: parece-me bem
    planoDeVoo.clear();
    while(!servicosPorRealizar.empty()) {
        servicosPorRealizar.pop();
    }
    while (!servicosRealizados.empty()) {
        servicosRealizados.pop();
    }
}

Aviao::Aviao(string m, unsigned int c,list<Voo>& planVoo, queue<Servico>& servRealizados, queue<Servico>& servPorRealizar) {
    this->matricula = m;
    this->capacidade = c;
    this->planoDeVoo = planVoo;
    this->servicosPorRealizar = servPorRealizar;
    this->servicosRealizados = servRealizados;
}

string Aviao::getMatricula() const {
    return this-> matricula;
}

unsigned int Aviao::getCapacidade() const {
    return this->capacidade;
}

const list<Voo> &Aviao::getPlanoDeVoo() const {
    return this->planoDeVoo;
}

queue <Servico> Aviao::getServicosPorRealizar() const {
    return this->servicosPorRealizar;
}

queue <Servico> Aviao::getServicosRealizados() const{
    return this->servicosRealizados;
}

void Aviao::setMatricula(const string &m) {
    this->matricula=matricula;
}

void Aviao::setCapacidade(const unsigned int &c) {
    this->capacidade=capacidade;
}

void Aviao::setPlanoDeVoo(const list<Voo> &planVoo) {
    this->planoDeVoo = planoDeVoo;
}

void Aviao::setServicosPorRealizar(const queue<Servico> &servPorRealizar) {
    this->servicosPorRealizar = servicosPorRealizar;
}

void Aviao::setServicosRealizados(const queue<Servico> &servRealizados) {
    this->servicosRealizados = servicosRealizados;
}

void Aviao:: addVoo(const Voo &voo){
    this->planoDeVoo.push_back(voo);
}

void Aviao::addServicoPorRealizar(const Servico &servico) {
    this->servicosPorRealizar.push(servico);
}

//milena: nao sei se o codigo esta certo e se devia ser passado algum parametro
//isabel: acho que está bem
void Aviao::realizarServico (){
    this->servicosRealizados.push(servicosPorRealizar.front());
    this->servicosPorRealizar.pop();
}
