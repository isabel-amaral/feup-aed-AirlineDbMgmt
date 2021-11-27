#ifndef _SERVICO_H
#define _SERVICO_H

#include <string>
using namespace std;

class Servico {
private:
    /**
     * um serviço pode ser de manutenção ou limpeza,
     * em cada caso será representado por uma string cujo valor será o respetivo tipo de seerviço
     */
    string tipoServico;
    /**
     * a data para a qual o serviço foi agendado é armazenada numa string no formato DD-MM-AAAA,
     * pode ser uma data passada ou futura conforme o serviço já tenha sido realizado ou não
     */
    string data;
    /**
     * nome do funcionário responsável pelo serviço
     */
    string funcionarioResponsavel; //classe funcionário?
public:
    Servico(string tipo, string d, string funcionario);
    string getTipoServico();
    string getData();
    string getFuncionarioResponsavel();
    void setTipoServico(string& tipo);
    void setData(string& d);
    void setFuncionarioResponsavel(string& funcionario);
};

#endif //_SERVICO_H
