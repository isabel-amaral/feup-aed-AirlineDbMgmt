#include "TransportadorDeBagagem.h"

TransportadorDeBagagm::TransportadorDeBagagm(unsigned int c, unsigned int n, unsigned m) {
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

void TransportadorDeBagagm::adicionarAoTapete(Bagagem* bagagem) {
    tapeteRolante.push(bagagem);
}

void TransportadorDeBagagm::despejarTapete() {
    while (!tapeteRolante.empty()) {
        adicionarAoCarrinho(tapeteRolante.front());
        tapeteRolante.pop();
    }
}

void TransportadorDeBagagm::despejarTapete(unsigned int n) {
    for (int i = 0; i < n && !tapeteRolante.empty(); i++) {
        adicionarAoCarrinho(tapeteRolante.front());
        tapeteRolante.pop();
    }
}

void TransportadorDeBagagm::adicionarAoCarrinho(Bagagem* bagagem){
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

void TransportadorDeBagagm::despejarCarrinho() {
    list<list<stack<Bagagem*>>>::iterator it1;
    list<stack<Bagagem*>>::iterator it2;

    for (it1 = carrinho.begin(); it1 != carrinho.end(); it1++) {
        for (it2 = it1->begin(); it2 != it1->end(); it2++) {
            while(!it2->empty())
                it2->pop();  //fazer alguma coisa depois das malas sairem do transportador?
        }
    }
}