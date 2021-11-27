#ifndef _PASSAGEIRO_H
#define _PASSAGEIRO_H

#include "Bilhete.h"
#include <string>
#include <list>
using namespace std;

class Passageiro {
private:
    string nome;
    int id;
    list<Bilhete> bilhetesAdquiridos;

public:
    Passageiro(string n, int id);
    string getNome() const;
    int getId() const;
    void adquirirBilhete(Bilhete& bilhete);
};

#endif //_PASSAGEIRO_H
