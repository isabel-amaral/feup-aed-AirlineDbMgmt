#ifndef _TRANSPORTADORDEBAGAGEM_H
#define _TRANSPORTADORDEBAGAGEM_H

#include "Bagagem.h"
#include <list>
#include <queue>
#include <stack>
using namespace std;

class TransportadorDeBagagem {
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
     * Tapete rolante no qual as malas são depositadas para a posterior colocação no carrinho.
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
     * Retira as malas do tapete rolante e as coloca no carrinho.
     */
    void despejarTapete();
    /**
     * Tranfere (remove) as primeiras n malas do tapete rolante para o carrinho.
     * @param n é o número de malas que devem ser retiradas.
     */
    void despejarTapete(unsigned n);
    /**
     * Adiciona mais uma bagagem ao carrinho que transporta as malas.
     * @param bagagem
     */
    void adicionarAoCarrinho(Bagagem* bagagem);
    /**
     * Retira todas as malas que se env«contram no acrrinho.
     */
    void despejarCarrinho();
};

#endif //_TRANSPORTADORDEBAGAGEM_H
