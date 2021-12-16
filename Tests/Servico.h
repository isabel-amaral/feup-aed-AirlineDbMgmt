#ifndef _SERVICO_H
#define _SERVICO_H

#include "Data.h"
#include "Funcionario.h"
#include <string>
using namespace std;

enum TipoServico {Manutencao, Limpeza};

class Servico {
private:
    /**
     * Um serviço pode ser de manutenção ou limpeza,
     * em cada caso será representado por uma string cujo valor será "manutenção "ou "limpeza"
     */             //***************** ALTERAR A DOCUMENTADACAO ACIMA******************************
    TipoServico tipoServico;
    /**
     * A data para a qual o serviço foi agendado é armazenada numa string no formato DD-MM-AAAA,
     * pode ser uma data passada ou futura conforme o serviço já tenha sido realizado ou não
     */
    Data data;
    /**
     * nome do funcionário responsável pelo serviço
     */
    Funcionario funcionarioResponsavel;
public:
    Servico();
    Servico(TipoServico tipo, Data d, Funcionario& funcionario);
    /**
     *
     * @return tipo do serviço.
     */
    TipoServico getTipoServico();
    /**
     *
     * @return data na qual o serviço foi realizado/data para a qual o serviço está agendado.
     */
    Data getData();
    /**
     *
     * @return nome do funcionário responsável pelo serviço.
     */
    const Funcionario& getFuncionarioResponsavel();
    /**
     * Altera o tipo de serviço agendado para uma determinada data.
     * @param tipo é o tipo do serviço a ser alterado.
     */
    void setTipoServico(TipoServico tipo);
    /**
     * Define a data para a qual o serviço está agendado.
     * @param d é a data para qual o serviço vai ser reagendado.
     */
    void setData(const Data& d);
    /**
     * Altera o funcionário responsável pelo serviço.
     * @param f é o nome do funcionário responsável pelo serviço.
     */
    void setFuncionarioResponsavel(const Funcionario& f);
};

#endif //_SERVICO_H
