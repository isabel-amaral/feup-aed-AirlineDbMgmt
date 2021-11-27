#ifndef _SERVICO_H
#define _SERVICO_H

#include <string>
using namespace std;

class Servico {
private:
    /**
     * um serviço pode ser de manutenção ou limpeza,
     * em cada caso será representado por uma string cujo valor será "manutenção "ou "limpeza"
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
    /**
     *
     * @return tipo do serviço
     */
    string getTipoServico();
    /**
     *
     * @return data na qual o serviço foi realizado/data para a qual o serviço está agendado
     */
    string getData();
    /**
     *
     * @return nome do funcionário responsável pelo serviço
     */
    string getFuncionarioResponsavel();
    /**
     * altera o tipo de serviço agendado para uma determinada data
     * @param tipo é o tipo do serviço a ser alterado
     */
    void setTipoServico(string& tipo);
    /**
     * altera a data para a qual o serviço está agendado, antecipações e adiamentos são possíveis
     * @param d é a data para qual o serviço vai ser reagendado
     */
    void setData(string& d);
    /**
     * altera o funcionário responsável pelo serviço
     * @param funcionario é o nome do funcionário responsável pelo serviço
     */
    void setFuncionarioResponsavel(string& funcionario);
};

#endif //_SERVICO_H
