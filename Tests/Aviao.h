
#ifndef _AVIAO_H
#define _AVIAO_H

#include <string>
using namespace std;

class Aviao{
private:
    string matricula;
    unsigned int capacidade;
    unsigned int numLugaresReservados;
    //plano de voo;
    //servicosRealizados;
    //servicosPorRealizar;
public:
    Aviao();
    Aviao(string m, unsigned int c, unsigned int nlr);
    string getMatricula() const;
    unsigned int getCapacidade() const;
    unsigned int getNumLugaresReservados() const;
    void setMatricula(string m);
    void setCapacidade(unsigned c);
    void setNumLugaresReservados(unsigned int lugares);

};
#endif //_AVIAO_H
