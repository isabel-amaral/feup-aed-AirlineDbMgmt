#include "Bilhete.h"

Bilhete::Bilhete() {
    this->idBilhete = 0;
    this->passageiro = Passageiro();
    this->voo = Voo();
    this->bagagemDeMao = false;
    this->bagagem = list<Bagagem*>();
}

Bilhete::Bilhete(unsigned id, const Passageiro& p, const Voo& v, bool b, const list<Bagagem*>& bagagem) {
    this->idBilhete = id;
    this->passageiro = p;
    this->voo = v;
    this->bagagemDeMao = b;
    this->bagagem = bagagem;
}

unsigned Bilhete::getIdBilhete() {
    return idBilhete;
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
    if (this->passageiro.getNome() == b.passageiro.getNome()) {
        if (this->getVoo().getDataPartida() < b.getVoo().getDataPartida())
            return true;
        if (this->getVoo().getDataPartida() == b.getVoo().getDataPartida())
            return this->getVoo().getHoraPartida() < b.getVoo().getHoraPartida();
    }
    return false;
}

ostream &operator<<(ostream &os, const Bilhete &b) {
    os<< b.getVoo();
    if (b.temBagagemDeMao())
        cout << b.getPasssageiro().getNome() << " tem direito a levar bagagem de mão" << endl;
    else
        cout << b.getPasssageiro().getNome() << " não tem direito a levar bagagem de mão" << endl;
    cout << endl;

    if (!b.getBagagem().empty())
        cout<< "Pode levar " << b.getBagagem().size() << " mala(s) no total." << endl;

    return os;
}


