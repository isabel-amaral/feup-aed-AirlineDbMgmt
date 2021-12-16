#ifndef _AVIAO_H
#define _AVIAO_H

#include "Voo.h"
#include "Servico.h"
#include "LocalDeTransporte.h"
#include <string>
#include <list>
#include <queue>

using namespace std;

class Aviao {
private:
    /**
     * Matrícula do avião.
     */
    string matricula;
    /**
     * Capacidade do avião.
     */
    unsigned int capacidade;
    /**
     * Todos os voos que o avião tem agendados/por realizar.
     */
    list<Voo> planoDeVoo; //sofia: nao acham que deviamos dizer a lista tem os voos por exemplo do mês e que vai sendo atualizada mensalmente?
    /**
    * Todos os serviços aos quais o avião está sujeito.
    */
    queue <Servico> servicosPorRealizar;
    /**
    * Todos os serviços concluídos.
    */
    queue <Servico> servicosRealizados;

public:
    Aviao();
    Aviao(const string& m, unsigned c);
    /**
     *
     * @return matricula do avião.
     */
    string getMatricula() const;
    /**
     *
     * @return capacidade do avião.
     */
    unsigned getCapacidade() const;
    /**
    *
    * @return todos os voos que o avião tem agendados/por realizar.
    */
    list<Voo> getPlanoDeVoo() const;
    /**
    *
    * todos os serviços aos quais o avião está sujeito.
    */
    queue<Servico> getServicosPorRealizar() const;
    /**
    *
    * @return todos os serviços concluídos.
    */
    queue<Servico> getServicosRealizados() const;
    /**
    * Modifica a matrícula do avião.
    * @param m é a matricula do aviao.
    */
    void setMatricula(const string& m);
    /**
    * Modifica a capacidade do avião.
    * @param c é a capacidade do aviao
    */
    void setCapacidade(const unsigned& c);
    /**
    * Define a lista de voos que o avião tem por realizar.
    * @param planVoo é o plano de voos do avião.
    */
    void setPlanoDeVoo(const list<Voo>& planVoo);
    /**
    * Define os serviços aos quais o avião está sujeito.
    * @param servPorRealizar são os serviços a realizar.
    */
    void setServicosPorRealizar(const queue<Servico>& servPorRealizar);
    /**
    * Define os serviços concluídos.
    * @param servRealizados são os serviços realizados.
    */
    void setServicosRealizados(const queue<Servico>& servRealizados);
    /**
     *
     * Acrescenta mais um voo aos demais voos que o avião tem como agendados.
     * @param voo é o novo voo que o avião deverá realizar.
     */
    void addVoo(const Voo& voo);
    /**
     *
     * Acrescenta um novo serviço a realizar.
     * @param servico é o serviço a ser adicionado.
     */
    void addServicoPorRealizar(const Servico& servico);
    /**
     *
     * Marca um serviço da lista dos serviços agendados (por realizar) como concluído, ou seja,
     * remove-o da fila dos agendados e acrescenta-o na dos realizados.
     */
    void realizarServico();
};
#endif //_AVIAO_H
