#include "Bagagem.h"

Bagagem::Bagagem() {
    this->peso = 0.0;
    this->bagaemDeMao = false;
    this->checkedIn = false;
}

Bagagem::Bagagem(float p, bool bagagem) {
    this->peso = p;
    this->bagaemDeMao = bagagem;
    this->checkedIn = false;  //no seu estado inicial a bagagem nunca tem o check-in feito
}

float Bagagem::getPeso() const {
    return peso;
}

bool Bagagem::isBagaemDeMao() const {
    return bagaemDeMao;
}
