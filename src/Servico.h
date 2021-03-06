#ifndef _SERVICO_H
#define _SERVICO_H

#include "Data.h"
#include "Funcionario.h"
#include <string>
#include <iostream>
using namespace std;
using namespace std;

enum TipoServico {Manutencao, Limpeza};

class Servico {
private:
    /**
     * Um serviço pode ser de manutenção ou limpeza,
     * em cada caso será representado por um enum cujo valor será Manutencao ou Limpeza
     */
    TipoServico tipoServico;
    /**
     * A data para a qual o serviço foi agendado é armazenada numa string no formato DD-MM-AAAA,
     * pode ser uma data passada ou futura conforme o serviço já tenha sido realizado ou não.
     */
    Data data;
    /**
     * funcionário responsável pelo serviço
     */
    Funcionario funcionarioResponsavel;
public:
    Servico();
    Servico(TipoServico tipo, const Data& d, Funcionario& funcionario);
    /**
     *
     * @return tipo do serviço.
     */
    TipoServico getTipoServico() const;
    /**
     *
     * @return data na qual o serviço foi realizado/data para a qual o serviço está agendado.
     */
    Data getData() const;
    /**
     *
     * @return nome do funcionário responsável pelo serviço.
     */
    Funcionario getFuncionarioResponsavel() const;
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
     * @param f é o funcionário responsável pelo serviço.
     */
    void setFuncionarioResponsavel(const Funcionario& f);

    /**
     * Este operador envia para uma outputstream toda a informação sobre um serviço que deverá ser mostrada ao utilizador.
     * @param os outputstream que conterá informação sobre o serviço.
     * @param s serviço sobre o qual se pretende obter informação.
     * @return outputstream com a informação sobre o serviço.
     */
    friend ostream& operator<< (ostream& os, const Servico& s);
};

#endif //_SERVICO_H
