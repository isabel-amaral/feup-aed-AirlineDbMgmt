#include "Bagagem.h"

Bagagem::Bagagem() {
    this->peso = 0.0;
    this->bagagemDeMao = false;
    this->checkInAutomatico = false;
}

Bagagem::Bagagem(float p, bool bagagemMao, bool checkIn) {
    this->peso = p;
    this->bagagemDeMao = bagagemMao;
    this->checkInAutomatico = checkIn;
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
