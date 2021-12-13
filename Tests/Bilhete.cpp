#include "Bilhete.h"

Bilhete::Bilhete() {
    this->voo = Voo();
    this->bagagemDeMao = false;
}

Bilhete::Bilhete(const Voo& v, bool bagagem, Passageiro* p) {
    this->voo = v;
    this->bagagemDeMao = bagagem;
    this->passageiro = p;
}

const Voo& Bilhete::getVoo() const {
    return this->voo;
}

bool Bilhete::temBagagemDeMao() const {
    return this->bagagemDeMao;
}

Passageiro* Bilhete::getPasssageiro() const {
    return passageiro;
}

void Bilhete::setBagagemDeMao(bool bagagem) {
    this->bagagemDeMao = bagagem;
}

void Bilhete::setPassageiro(Passageiro* p) {
    this->passageiro = p;
}
