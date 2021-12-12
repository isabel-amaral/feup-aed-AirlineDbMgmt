#ifndef _FUNCIONARIO_H
#define _FUNCIONARIO_H

#include <string>
using namespace std;

class Funcionario {
private:
    unsigned idFuncionario;
    string nomeFuncionario;

public:
    Funcionario();
    Funcionario(unsigned id, string n);
    unsigned getIdFuncionario() const;
    string getNomeFuncionario() const;
    void setIdFuncionario(unsigned idFuncionario);
    void setNomeFuncionario(const string &nomeFuncionario);
};

#endif //_FUNCIONARIO_H
