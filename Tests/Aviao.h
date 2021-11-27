#ifndef _AVIAO_H
#define _AVIAO_H

#include "Voo.h"
#include "Servico.h"
#include <string>
#include <list>
#include <queue>
using namespace std;

class Aviao{
private:
    string matricula;
    //isabel: não acaham que os atributos capacidade de numLugaresReservados faz mais sentido ir para a classe voo?
    unsigned int capacidade;
    unsigned int numLugaresReservados;
    list<Voo> planoDeVoo;
    queue <Servico> servicosRealizados;
    queue <Servico> servicosPorRealizar;
public:
    Aviao();
    Aviao(string m, unsigned int c, unsigned int nlr,list<Voo> &planVoo, queue <Servico> &sRealizados, queue <Servico> &sPorRealizar );
    void setMatricula(const string &m);
    void setCapacidade(const unsigned int &c);
    void setNumLugaresReservados(const unsigned int &lugares);

    string getMatricula() const;
    unsigned int getCapacidade() const;
    unsigned int getNumLugaresReservados() const;
    queue <Servico> getServicosRealizados() const;
    queue <Servico> getServicosPorRealizar() const;

    void addVoo(const Voo &voo);
    void addServico (const Servico &servico);
    void addServicoRealizado (const Servico &srvico);

    //isabel: método que adiciona um novo serviço a realizar
    //isabel: método que passa um serviço da queue dos serviços por realizar para os serviços realizados
};
#endif //_AVIAO_H
