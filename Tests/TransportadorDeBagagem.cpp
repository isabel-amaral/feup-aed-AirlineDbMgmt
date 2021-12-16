#include "TransportadorDeBagagem.h"

TransportadorDeBagagem::TransportadorDeBagagem() {
    this->numCarruagens = 0;
    this->numPilhas = 0;
    this->numMalas = 0;
    this->tapeteRolante = queue<Bagagem*>();
    this->carrinho = list<list<stack<Bagagem*>>>();
}

TransportadorDeBagagem::TransportadorDeBagagem(unsigned c, unsigned n, unsigned m) {
    this->numCarruagens = c;
    this->numPilhas = n;
    this->numMalas = m;
    this->tapeteRolante = queue<Bagagem*>();

    for (int i = 0; i < c; i++) {
        list<stack<Bagagem*>> carruagemAux;
        for (int j = 0; j < n; j++) {
            stack<Bagagem*> s;
            carruagemAux.push_back(s);
        }
        this->carrinho.push_back(carruagemAux);
    }
}

void TransportadorDeBagagem::adicionarAoTapete(Bagagem* bagagem) {
    tapeteRolante.push(bagagem);
}

void TransportadorDeBagagem::despejarTapete() {
    while (!tapeteRolante.empty()) {
        adicionarAoCarrinho(tapeteRolante.front());
        tapeteRolante.pop();
    }
}

void TransportadorDeBagagem::despejarTapete(unsigned n) {
    for (int i = 0; i < n && !tapeteRolante.empty(); i++) {
        adicionarAoCarrinho(tapeteRolante.front());
        tapeteRolante.pop();
    }
}

void TransportadorDeBagagem::adicionarAoCarrinho(Bagagem* bagagem){
    bool adicionado = false;
    list<list<stack<Bagagem*>>>::iterator it1;
    list<stack<Bagagem*>>::iterator it2;

    for (it1 = carrinho.begin(); it1 != carrinho.end(); it1++) {
        for (it2 = it1->begin(); it2 != it1->end(); it2++) {
            if (it2->size() < numMalas) {
                it2->push(bagagem);
                adicionado = true;
                break;
            }
        }
        if (adicionado)
            break;
    }
}

void TransportadorDeBagagem::despejarCarrinho() {
    list<list<stack<Bagagem*>>>::iterator it1;
    list<stack<Bagagem*>>::iterator it2;

    for (it1 = carrinho.begin(); it1 != carrinho.end(); it1++) {
        for (it2 = it1->begin(); it2 != it1->end(); it2++) {
            while(!it2->empty())
                it2->pop();  //fazer alguma coisa depois das malas sairem do transportador?
        }
    }
}