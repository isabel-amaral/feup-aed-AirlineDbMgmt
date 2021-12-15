#include "Aeroporto.h"
using namespace std;

Aeroporto::Aeroporto(): transportes(new LocalDeTransporte()){
    this->nome = "";
    this->cidade = "";
    /*
    voosPartida.clear();
    voosChegada.clear();
     */
}

Aeroporto::Aeroporto(const string& n, const string& c): transportes(new LocalDeTransporte()){
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

void Aeroporto::addTransporte( LocalDeTransporte* lp) {
    transportes.insert(lp);
}

LocalDeTransporte* Aeroporto::getLocalTransporteProximo()  {
    return transportes.findMin();
}


LocalDeTransporte* Aeroporto::getMetroProximo() {
    BSTItrIn<LocalDeTransporte*> it (transportes);
    while (!it.isAtEnd()){
        if (it.retrieve()->getTipo()==Metro)
            return it.retrieve();
        it.advance();
    }
    return nullptr;
}

LocalDeTransporte* Aeroporto::getComboioProximo() {
    BSTItrIn<LocalDeTransporte*> it (transportes);
    while (!it.isAtEnd()){
        if (it.retrieve()->getTipo()==Comboio)
            return it.retrieve();
        it.advance();
    }
    return nullptr;
}

LocalDeTransporte* Aeroporto::getAutocarroProximo() {
    BSTItrIn<LocalDeTransporte*> it (transportes);
    while (!it.isAtEnd()){
        if (it.retrieve()->getTipo()==Autocarro)
            return it.retrieve();
        it.advance();
    }
    return nullptr;
}

void Aeroporto::showLocalTransporteProximo() {
    if (getLocalTransporteProximo() == nullptr) {
        cout << "Não existe local de transporte terrestre próximo a este aeroporto." << endl;
        return;
    }
    cout << getLocalTransporteProximo()<< endl;
}

void Aeroporto::showMetroProximo() {
    if (getLocalTransporteProximo() == nullptr) {
        cout << "Não existe local de Metro próximo a este aeroporto." << endl;
        return;
    }
    cout << *(getMetroProximo())<< endl;
}

void Aeroporto::showComboioProximo() {
    if (getComboioProximo() == nullptr) {
        cout << "Não existe local de Comboio próximo a este aeroporto." << endl;
        return;
    }
    cout << *(getComboioProximo())<< endl;

}

void Aeroporto::showAutocarroProximo() {
    if (getLocalTransporteProximo() == nullptr) {
        cout << "Não existe local de Autocarro próximo a este aeroporto." << endl;
        return;
    }
    cout << *(getAutocarroProximo())<< endl;
}












