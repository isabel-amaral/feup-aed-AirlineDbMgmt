#include "Aeroporto.h"
#include "LocalDeTransporte.h"
using namespace std;

Aeroporto::Aeroporto(): transportes(LocalDeTransporte(0.0)){
    this->nome = "";
    this->cidade = "";

    /*
    voosPartida.clear();
    voosChegada.clear();
     */
}

Aeroporto::Aeroporto(const string& n, const string& c): transportes(LocalDeTransporte(0.0)){
    this->nome = n;
    this->cidade = c;
    /*
    voosPartida = vp;
    voosChegada = vc;
     */
}

string Aeroporto::getNome() const {
    return nome;
}

string Aeroporto::getCidade() const {
    return cidade;
}

/*
list<Voo> Aeroporto::getVoosPartida() const {
    return voosPartida;
}

list<Voo> Aeroporto::getVoosChegada() const {
    return voosChegada;
}
*/

/*
void Aeroporto::setNome(const string &n) {
    this->nome = nome;
}

void Aeroporto::setCidade(const string &c) {
    this->cidade = c;
}

void Aeroporto::setVoosPartida(const list<Voo> &v) {
    this->voosPartida = v;
}

void Aeroporto::setVoosChegada(const list<Voo> &v) {
    this->voosChegada = v;
}
 */
/*
list<LocalDeTransporte> Aeroporto::getTransportes() const {
    return transportes;
}*/

void Aeroporto::addTransporte(const LocalDeTransporte &lp) {
    transportes.insert(lp);
}
/*
LocalDeTransporte* Aeroporto::getMeioTransporteProximo()  {
    LocalDeTransporte l= transportes.findMin();
    return &l;
}*/

/*
LocalDeTransporte Aeroporto::getMetroProximo() {
    BSTItrIn<LocalDeTransporte> it (transportes);
    while (!it.isAtEnd()){
        if (it.retrieve().getTipo()==Metro)
            return it.retrieve();
        it.advance();
    }
}

LocalDeTransporte Aeroporto::getComboioProximo() {
    BSTItrIn<LocalDeTransporte> it (transportes);
    while (!it.isAtEnd()){
        if (it.retrieve().getTipo()==Comboio)
            return it.retrieve();
        it.advance();
    }
}

LocalDeTransporte Aeroporto::getAutocarroProximo() {
    BSTItrIn<LocalDeTransporte> it (transportes);
    while (!it.isAtEnd()){
        if (it.retrieve().getTipo()==Autocarro)
            return it.retrieve();
        it.advance();
    }
}

void Aeroporto::showMeioTransporteProximo() {
    cout << getMeioTransporteProximo()<< endl;
}

void Aeroporto::showMetroProximo() {
    cout << getMetroProximo() << endl;
}

void Aeroporto::showComboioProximo() {
    cout << getComboioProximo() <<endl;
}

void Aeroporto::showAutocarroProximo() {
    cout << getAutocarroProximo() <<endl;
}*/












