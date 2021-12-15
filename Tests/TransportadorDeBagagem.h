#ifndef _TRANSPORTADORDEBAGAGEM_H
#define _TRANSPORTADORDEBAGAGEM_H

#include "Bagagem.h"
#include <list>
#include <queue>
#include <stack>
using namespace std;

class TransportadorDeBagagem {
    //, cada carruagem dispõe de n pilhas onde colocar bagagem (na
    //figura, n=3) e cada pilha pode levar m malas (na figura, m=4).
private:
    /**
     * Número de carruagens que o carrinho de transporte possui.
     */
    unsigned numCarruagens;
    /**
     * Número de pilhas que cada carruagem tem.
     */
    unsigned numPilhas;
    /**
     * Número máximo de malas que cada pilha pode conter.
     */
    unsigned numMalas;
    /**
     * Fila com todas as bagagens que são depositadas no tapete rolante
     * para a posterior colocação no carrinho.
     */
    queue<Bagagem*> tapeteRolante;
    /**
     * Carrinho que transporta as malas dos passageiros
     */
    list<list<stack<Bagagem*>>> carrinho;

public:
    TransportadorDeBagagem();
    TransportadorDeBagagem(unsigned c, unsigned n, unsigned m);
    /**
     * Acrescenta uma nova bagegem ao tapete rolante
     * @param bagagem é a nova bagagem
     */
    void adicionarAoTapete(Bagagem* bagagem);
    /**
     *
     */
    void despejarTapete();
    void despejarTapete(unsigned n);
    void adicionarAoCarrinho(Bagagem* bagagem);
    void despejarCarrinho();
};

#endif //_TRANSPORTADORDEBAGAGEM_H
