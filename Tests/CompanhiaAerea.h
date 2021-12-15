#ifndef _COMPANHIAAEREA_H
#define _COMPANHIAAEREA_H

#include "Passageiro.h"
#include "Bilhete.h"
#include "Voo.h"
#include "Data.h"

class CompanhiaAerea {
private:
    vector<Bilhete> bilhetesVendidos;
    //list<Aviao> avioes;

public:
    CompanhiaAerea();
    vector<Bilhete> getBilhetesVendidos() const;
    vector<Bilhete> getBilhetesFromPassageiro(const Passageiro& p) const;
    void mostrarBilhetesFromPassageiro(const Passageiro& p) const;
    bool adquirirBilhete(const Passageiro& p, Voo& v, bool bagagem);
    bool adquirirConjuntoBilhetes(const list<Passageiro>& p, Voo& v, bool bagagem);
    //outros métodos
};

#endif //_COMPANHIAAEREA_H
