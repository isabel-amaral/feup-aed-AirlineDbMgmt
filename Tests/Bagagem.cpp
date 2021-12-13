#include "Bagagem.h"

Bagagem::Bagagem() {
    this->peso = 0.0;
    this->bagagemDeMao = false;
    this->checkInAutomatico = false;
}

Bagagem::Bagagem(float p, bool bagagem) {
    this->peso = p;
    this->bagagemDeMao = bagagem;
    this->checkInAutomatico = false;  //no seu estado inicial a bagagem nunca tem o check-in feito
}

float Bagagem::getPeso() const {
    return peso;
}

bool Bagagem::isBagagemDeMao() const {
    return bagagemDeMao;
}

bool Bagagem::isCheckInAutomatico() const {
    return checkInAutomatico;
}
