#ifndef _PASSAGEIRO_H
#define _PASSAGEIRO_H

#include <string>
using namespace std;

class Passageiro {
private:
    string nome;
    int id;
    //bilhetesAdquiridos

public:
    Passageiro(string n, int id);
    string getNome() const;
    int getId() const;
    //adquirirBilhete
};

#endif //_PASSAGEIRO_H
