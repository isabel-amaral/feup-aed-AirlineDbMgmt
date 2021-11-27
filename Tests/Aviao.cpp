#include "Aviao.h"
using namespace std;

//isabel: tive de implementar o construtor defualt para conseguir fazer build
Aviao::Aviao() {
    matricula = "";
    capacidade = 0;
    numLugaresReservados = 0;
}

Aviao::Aviao(string m, unsigned int c, unsigned int nlr,list<Voo> &planVoo, queue <Servico> &sRealizados, queue <Servico> &sPorRealizar ){
    this->matricula = m;
    this->capacidade = c;
    this->numLugaresReservados = nlr;
    this->planoDeVoo=planVoo;
    this->servicosRealizados=sRealizados;
    this->servicosPorRealizar=sPorRealizar;
}

void Aviao::setMatricula(const string &m) {
    this->matricula=m;
}

void Aviao::setCapacidade(const unsigned int &c) {
    this->capacidade=c;
}

void Aviao::setNumLugaresReservados(const unsigned int &lugares) {
    this->numLugaresReservados=lugares;
}
string Aviao::getMatricula() const {
    return this-> matricula;
}

unsigned int Aviao::getCapacidade() const {
    return this->capacidade;
}

unsigned int Aviao::getNumLugaresReservados() const {
    return this->numLugaresReservados;
}

queue <Servico> Aviao::getServicosRealizados() const{
    return this->servicosRealizados;
}

queue <Servico> Aviao::getServicosPorRealizar() const {
    return this->servicosPorRealizar;
}

void Aviao:: addVoo(const Voo &voo){

}

void Aviao:: addServico (const Servico &servico){}
void Aviao::addServicoRealizado (const Servico &srvico){
}