#ifndef _COMPANHIAAEREA_H
#define _COMPANHIAAEREA_H

#include "Passageiro.h"
#include "Bilhete.h"

class CompanhiaAerea {
private:
    vector<Bilhete> bilhetesVendidos;
    //list<Aviao> avioes;

public:
    CompanhiaAerea();
    const vector<Bilhete>& getBilhetesVendidos() const;
    const vector<Bilhete>& getBilhetesFromPassageiro() const;
    bool adquiriBilhete(const Passageiro& p, Voo& v, bool bagagem);
    //outros métodos
};

#endif //_COMPANHIAAEREA_H
