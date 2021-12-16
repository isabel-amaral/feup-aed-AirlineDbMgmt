#ifndef _FUNCIONARIO_H
#define _FUNCIONARIO_H

#include <string>
using namespace std;

class Funcionario {
private:
    /**
     * Número de identificação do funcionário.
     */
    unsigned idFuncionario;
    /**
     * Nome do funcionário.
     */
    string nomeFuncionario;

public:
    Funcionario();
    Funcionario(unsigned id, string n);
    /**
     *
     * @return número de identificação do funcionário.
     */
    unsigned getIdFuncionario() const;
    /**
     *
     * @return nome do funcionário.
     */
    string getNomeFuncionario() const;
    /**
     * Altera o número de identificação do funcionário.
     * @param idFuncionario é o novo id.
     */
    void setIdFuncionario(unsigned idFuncionario);
    /**
     * Modifica o nome do funcionário.
     * @param nomeFuncionario é o novo nome do funcionário.
     */
    void setNomeFuncionario(const string &nomeFuncionario);
};

#endif //_FUNCIONARIO_H
