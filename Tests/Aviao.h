#ifndef _AVIAO_H
#define _AVIAO_H

#include <string>
using namespace std;

class Aviao{
private:
    string matricula;
    //isabel: não acaham que os atributos capacidade de numLugaresReservados faz mais sentido ir para a classe voo?
    unsigned int capacidade;
    unsigned int numLugaresReservados;
    //isabel: estes atributos já podem ser escritos
    //plano de voo;
    //isabel: usar queues para os serviços
    //servicosRealizados;
    //servicosPorRealizar;
public:
    Aviao();
    Aviao(string m, unsigned int c, unsigned int nlr);
    string getMatricula() const;
    unsigned int getCapacidade() const;
    unsigned int getNumLugaresReservados() const;
    //isabel: nos setters passar parâmetros por referência
    void setMatricula(string m);
    void setCapacidade(unsigned c);
    void setNumLugaresReservados(unsigned int lugares);
    //isabel: método que adiciona um novo serviço a realizar
    //isabel: método que passa um serviço da queue dos serviços por realizar para os serviços realizados
};
#endif //_AVIAO_H
