#include "Aeroporto.h"
using namespace std;

Aeroporto::Aeroporto(): transportes(LocalDeTransporte()){
    this->nome = "";
    this->cidade = "";
}

Aeroporto::Aeroporto(const string& n, const string& c): transportes(LocalDeTransporte()){
    this->nome = n;
    this->cidade = c;
}

string Aeroporto::getNome() const {
    return nome;
}

string Aeroporto::getCidade() const {
    return cidade;
}

BST<LocalDeTransporte> Aeroporto::getTransportes() const {
    return transportes;
}

void Aeroporto::addTransporte(LocalDeTransporte lp) {
    transportes.insert(lp);
}

LocalDeTransporte Aeroporto::getLocalTransporteProximo()  {
    return transportes.findMin();
}


LocalDeTransporte Aeroporto::getMetroProximo() {
    BSTItrIn<LocalDeTransporte> it (transportes);
    while (!it.isAtEnd()){
        if (it.retrieve().getTipo()==Metro)
            return it.retrieve();
        it.advance();
    }
    return LocalDeTransporte();
}

LocalDeTransporte Aeroporto::getComboioProximo() {
    BSTItrIn<LocalDeTransporte> it (transportes);
    while (!it.isAtEnd()){
        if (it.retrieve().getTipo()==Comboio)
            return it.retrieve();
        it.advance();
    }
    return LocalDeTransporte();
}

LocalDeTransporte Aeroporto::getAutocarroProximo() {
    BSTItrIn<LocalDeTransporte> it (transportes);
    while (!it.isAtEnd()){
        if (it.retrieve().getTipo()==Autocarro)
            return it.retrieve();
        it.advance();
    }
    return LocalDeTransporte();
}

void Aeroporto::showLocalTransporteProximo() {
    if (getLocalTransporteProximo().getDistancia() == 0.0) {
        cout << "Não existe local de transporte terrestre próximo a este aeroporto." << endl;
        return;
    }
    cout << getLocalTransporteProximo() << endl;
}

void Aeroporto::showMetroProximo() {
    if (getLocalTransporteProximo().getDistancia() == 0.0) {
        cout << "Não existe local de Metro próximo a este aeroporto." << endl;
        return;
    }
    cout << getMetroProximo() << endl;
}

void Aeroporto::showComboioProximo() {
    if (getComboioProximo().getDistancia() == 0.0) {
        cout << "Não existe local de Comboio próximo a este aeroporto." << endl;
        return;
    }
    cout << getComboioProximo() << endl;

}

void Aeroporto::showAutocarroProximo() {
    if (getLocalTransporteProximo().getDistancia() == 0.0) {
        cout << "Não existe local de Autocarro próximo a este aeroporto." << endl;
        return;
    }
    cout << getAutocarroProximo() << endl;
}

/*
void Aeroporto::setNome(const string &n) {
    this->nome = nome;
}

void Aeroporto::setCidade(const string &c) {
    this->cidade = c;
}
 */

