#include "Bilhete.h"

unsigned Bilhete::idCount = 0;

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
    idCount++;
}

unsigned Bilhete::getIdBilhete() const {
    return idBilhete;
}

unsigned Bilhete::getIdCount() {
    return idCount;
}

Passageiro Bilhete::getPasssageiro() const {
    return passageiro;
}

Voo& Bilhete::getVoo() {
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

bool Bilhete::operator< (Bilhete& b) {
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

bool Bilhete::operator== (const Bilhete& b) const {
    return this->idBilhete == b.getIdBilhete();
}

ostream &operator<< (ostream& os, Bilhete& b) {

    os << "NUMERO DE BILHETE: " << b.getIdBilhete() << endl;
    os << b.getVoo();

    if (b.temBagagemDeMao())
        cout << b.getPasssageiro().getNome() << " tem direito a levar bagagem de mao" << endl;
    else
        cout << b.getPasssageiro().getNome() << " nao tem direito a levar bagagem de mao" << endl;
    //TODO: retirar?
    if (!b.getBagagem().empty())
        cout << "Pode levar " << b.getBagagem().size() << " mala(s) no total." << endl;
    return os;
}
