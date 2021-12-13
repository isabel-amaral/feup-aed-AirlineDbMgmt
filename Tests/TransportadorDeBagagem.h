#ifndef _TRANSPORTADORDEBAGAGEM_H
#define _TRANSPORTADORDEBAGAGEM_H

#include "Bagagem.h"
#include <list>
#include <queue>
#include <stack>
using namespace std;

class TransportadorDeBagagm {
private:
    unsigned numCarruagens;
    unsigned numPilhas;
    unsigned numMalas;
    queue<Bagagem*> tapeteRolante;
    list<list<stack<Bagagem*>>> carrinho;

public:
    TransportadorDeBagagm(unsigned c, unsigned n, unsigned m);
    void adicionarAoTapete(Bagagem* bagagem);
    void despejarTapete();
    void despejarTapete(unsigned n);
    void adicionarAoCarrinho(Bagagem* bagagem);
    void despejarCarrinho();
};

#endif //_TRANSPORTADORDEBAGAGEM_H
