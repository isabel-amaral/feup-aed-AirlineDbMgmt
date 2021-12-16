#include "Bilhete.h"

Bilhete::Bilhete() {
    this->passageiro = Passageiro();
    this->voo = Voo();
    this->bagagemDeMao = false;
    this->bagagem = list<Bagagem*>();
}

Bilhete::Bilhete(const Passageiro& p, const Voo& v, bool b, const list<Bagagem*>& bagagem) {
    this->passageiro = p;
    this->voo = v;
    this->bagagemDeMao = b;
    this->bagagem = bagagem;
}

Passageiro Bilhete::getPasssageiro() const {
    return passageiro;
}

Voo Bilhete::getVoo() const {
    return this->voo;
}

bool Bilhete::temBagagemDeMao() const {
    return this->bagagemDeMao;
}

list<Bagagem*> Bilhete::getBagagem() const {
    return bagagem;
}

void Bilhete::setPassageiro(const Passageiro& p) {
    this->passageiro = p;
}

void Bilhete::setBagagemDeMao(bool bagagem) {
    this->bagagemDeMao = bagagem;
}

void Bilhete::setBagagem(const list<Bagagem*>& b) {
    this->bagagem = b;
}

bool Bilhete::operator< (const Bilhete& b) const {
    if (this->passageiro.getNome() < b.passageiro.getNome())
        return true;
    if (this->passageiro.getNome() == b.passageiro.getNome())
        if (this->getVoo().getDataPartida() < this->getVoo().getDataPartida())
            return true;
    if (this->getVoo().getDataPartida() == this->getVoo().getDataPartida())
        return this->getVoo().getHoraPartida() < this->getVoo().getHoraPartida();
    return false;
}
