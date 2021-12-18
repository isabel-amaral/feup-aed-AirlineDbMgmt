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

string Aeroporto::getNome() const{
    return nome;
}

string Aeroporto::getCidade() const{
    return cidade;
}

BST<LocalDeTransporte> Aeroporto::getTransportes() const{
    return transportes;
}

void Aeroporto::addTransporte(const LocalDeTransporte& lp) {
    transportes.insert(lp);
}

LocalDeTransporte Aeroporto::getLocalTransporteProximo() const{
    return transportes.findMin();
}

vector<LocalDeTransporte> Aeroporto::getMetros() const {
    vector<LocalDeTransporte> metros;

    BSTItrIn<LocalDeTransporte> it (transportes);

    while (!it.isAtEnd()){
        if (it.retrieve().getTipo()==Metro)
            metros.push_back(it.retrieve());
        it.advance();
    }
    return metros;
}

vector<LocalDeTransporte> Aeroporto::getComboios() const {
    vector<LocalDeTransporte> comboios;

    BSTItrIn<LocalDeTransporte> it (transportes);

    while (!it.isAtEnd()){
        if (it.retrieve().getTipo()==Comboio)
            comboios.push_back(it.retrieve());
        it.advance();
    }
    return comboios;
}

vector <LocalDeTransporte> Aeroporto::getAutocarros() const {
    vector<LocalDeTransporte> autocarros;

    BSTItrIn<LocalDeTransporte> it (transportes);

    while (!it.isAtEnd()){
        if (it.retrieve().getTipo()==Autocarro)
            autocarros.push_back(it.retrieve());
        it.advance();
    }
    return autocarros;
}

LocalDeTransporte Aeroporto::getMetroProximo() const{
    BSTItrIn<LocalDeTransporte> it (transportes);
    while (!it.isAtEnd()){
        if (it.retrieve().getTipo()==Metro)
            return it.retrieve();
        it.advance();
    }
    return LocalDeTransporte();
}

LocalDeTransporte Aeroporto::getComboioProximo() const{
    BSTItrIn<LocalDeTransporte> it (transportes);
    while (!it.isAtEnd()){
        if (it.retrieve().getTipo()==Comboio)
            return it.retrieve();
        it.advance();
    }
    return LocalDeTransporte();
}

LocalDeTransporte Aeroporto::getAutocarroProximo() const{
    BSTItrIn<LocalDeTransporte> it (transportes);
    while (!it.isAtEnd()){
        if (it.retrieve().getTipo()==Autocarro)
            return it.retrieve();
        it.advance();
    }
    return LocalDeTransporte();
}

void Aeroporto::showTransportes(int ordenacao) const {
    BSTItrIn <LocalDeTransporte> it (transportes);

    if (it.isAtEnd()){   // A BST está vazia
        cout << "Não existe informação sobre os meios de transportes disponíveis nesta cidade" << endl;
        return;
    }

    while(!it.isAtEnd()){ // A BST tem pelo menos um elemento
        cout << it.retrieve() << endl;
    }
}

void Aeroporto::showMetros(int ordenacao) const {
    vector <LocalDeTransporte> metros = getMetros();

    if (metros.empty()){
        cout << "Esta cidade não possui metros." << endl;
    }
    for (const auto& metro : metros)
        cout << metro << endl;
}

void Aeroporto::showComboios(int ordenacao) const {
    vector<LocalDeTransporte> comboios = getMetros();

    if (comboios.empty()){
        cout << "Esta cidade não possui comboios." << endl;
        return;
    }

    for (const auto& comboio : comboios)
        cout << comboio << endl;
}

void Aeroporto::showAutocaros(int ordenacao) const {
    vector<LocalDeTransporte> autocarros = getMetros();

    if (autocarros.empty()){
        cout << "Esta cidade não possui autocarros." << endl;
        return;
    }

    for (const auto& autocarro : autocarros)
        cout << autocarro << endl;
}

void Aeroporto::showLocalTransporteProximo(int ordenacao) const{
    if (getLocalTransporteProximo().getDistancia() == 0.0) {
        cout << "Não existe local de transporte terrestre próximo a este aeroporto." << endl;
        return;
    }
    cout << getLocalTransporteProximo() << endl;
}

void Aeroporto::showMetroProximo(int ordenacao) const{
    if (getLocalTransporteProximo().getDistancia() == 0.0) {
        cout << "Não existe local de Metro próximo a este aeroporto." << endl;
        return;
    }
    cout << getMetroProximo() << endl;
}

void Aeroporto::showComboioProximo(int ordenacao) const{
    if (getComboioProximo().getDistancia() == 0.0) {
        cout << "Não existe local de Comboio próximo a este aeroporto." << endl;
        return;
    }
    cout << getComboioProximo() << endl;
}

void Aeroporto::showAutocarroProximo(int ordenacao) const{
    if (getLocalTransporteProximo().getDistancia() == 0.0) {
        cout << "Não existe local de Autocarro próximo a este aeroporto." << endl;
        return;
    }
    cout << getAutocarroProximo() << endl;
}

bool Aeroporto::operator<(const Aeroporto &a1) const {
    return this->nome < a1.nome;
}
/*
void Aeroporto::setNome(const string &n) {
    this->nome = nome;
}

void Aeroporto::setCidade(const string &c) {
    this->cidade = c;
}
 */

