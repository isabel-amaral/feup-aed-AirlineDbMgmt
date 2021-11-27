#include "Aviao.h"
using namespace std;

Aviao::Aviao() {
    matricula = "";
    capacidade = 0;
    numLugaresReservados = 0;
    //milena: fiquei na duvida destas tres linhas de codigo; vi no fivheiro da TP5 (game()) e nao sei se é uma boa pratica
    //ou algo do genero; nao sei se é necessario colocar ou nao
    planoDeVoo.clear();
    // esvaziar servicosPorRealizar;
    //esvaziar servicosRealizados;

}

Aviao::Aviao(string m, unsigned int c, unsigned int nlr,list<Voo> &planVoo, queue <Servico> &servRealizados, queue <Servico> &servPorRealizar ){
    this->matricula = m;
    this->capacidade = c;
    this->numLugaresReservados = nlr;
    this->planoDeVoo=planVoo;
    this->servicosPorRealizar=servPorRealizar;
    this->servicosRealizados=servRealizados;

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

void Aviao::setPlanoDeVoo(const list<Voo> &pVoo) {
    this->planoDeVoo = pVoo;
}

void Aviao::setServicosPorRealizar(const queue<Servico> &servPorRealizar) {
    this->servicosPorRealizar = servPorRealizar;
}

void Aviao::setServicosRealizados(const queue<Servico> &servRealizados) {
    this->servicosRealizados = servRealizados;
}


//-------------------------------------------------------------------------------------------------------
string Aviao::getMatricula() const {
    return this-> matricula;
}

unsigned int Aviao::getCapacidade() const {
    return this->capacidade;
}

unsigned int Aviao::getNumLugaresReservados() const {
    return this->numLugaresReservados;
}

const list<Voo> &Aviao::getPlanoDeVoo() const {
    return planoDeVoo;
}

queue <Servico> Aviao::getServicosPorRealizar() const {
    return this->servicosPorRealizar;
}

queue <Servico> Aviao::getServicosRealizados() const{
    return this->servicosRealizados;
}


//TO DO:-------------------------------------------------------------------------
void Aviao:: addVoo(const Voo &voo){
    this->planoDeVoo.push_back(voo);
}

void Aviao::addServicoporRealizar(const Servico &servico) {
    this-> servicosPorRealizar.push(servico);
}

//milena: nao sei se o codigo esta certo e se devia ser passado algum parametro
void Aviao::realizarServico (){
    this->servicosRealizados.push(servicosPorRealizar.front());
    this->servicosPorRealizar.pop();
}




