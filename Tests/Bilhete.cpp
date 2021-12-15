#include "Bilhete.h"

Bilhete::Bilhete() {
    this->voo = Voo();
    this->bagagemDeMao = false;
}

Bilhete::Bilhete(const Voo& v, bool bagagem, const Passageiro& p) {
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

const Passageiro& Bilhete::getPasssageiro() const {
    return passageiro;
}

void Bilhete::setBagagemDeMao(bool bagagem) {
    this->bagagemDeMao = bagagem;
}

void Bilhete::setPassageiro(const Passageiro& p) {
    this->passageiro = p;
}

bool Bilhete::operator< (const Bilhete& b) {
    if (this->passageiro.getNome() < b.passageiro.getNome())
        return true;
    if (this->passageiro.getNome() == b.passageiro.getNome())
        if (this->getVoo().getDataPartida() < this->getVoo().getDataPartida())
            return true;
        if (this->getVoo().getDataPartida() == this->getVoo().getDataPartida())
            return this->getVoo().getHoraPartida() < this->getVoo().getHoraPartida();
    return false;
}