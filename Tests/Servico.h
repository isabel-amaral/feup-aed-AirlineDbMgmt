#ifndef _SERVICO_H
#define _SERVICO_H

#include <string>
using namespace std;

class Servico {
private:
    string tipoServico;
    string data;
    string funcionarioResponsavel;
public:
    Servico(string tipo, string d, string funcionario);
    string getTipoServico();
    string getData();
    string getFuncionarioResponsavel();
    void setTipoServico(string tipo);
    void setData(string d);
    void setFuncionarioResponsavel(string funcionario);
};

#endif //_SERVICO_H
