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
    vector <LocalDeTransporte> locais;
    if (it.isAtEnd()){   //A BST está vazia
        cout << "Não existe informação sobre os meios de transportes disponíveis nesta cidade" << endl;
        return;
    }
    while(!it.isAtEnd()){
        if (ordenacao != 1)
            locais.push_back(it.retrieve());
        else
            cout << it.retrieve() << endl;
        it.advance();
    }

    if (ordenacao != 1)
        ordenarLocais(locais, ordenacao);
}

void Aeroporto::showMetros(int ordenacao) const {
    vector <LocalDeTransporte> metros = getMetros();

    if (metros.empty()){
        cout << "Esta cidade não possui metros." << endl;
    }
    if ( ordenacao != 1)
        ordenarLocais(metros, ordenacao);

    for (const auto& metro : metros)
        cout << metro << endl;
}

void Aeroporto::showComboios(int ordenacao) const {
    vector<LocalDeTransporte> comboios = getMetros();

    if (comboios.empty()){
        cout << "Esta cidade não possui comboios." << endl;
        return;
    }

    if ( ordenacao != 1)
        ordenarLocais(comboios, ordenacao);

    for (const auto& comboio : comboios)
        cout << comboio << endl;
}

void Aeroporto::showAutocaros(int ordenacao) const {
    vector<LocalDeTransporte> autocarros = getMetros();
    if (autocarros.empty()) {
        cout << "Esta cidade não possui autocarros." << endl;
        return;
    }
    if (ordenacao != 1)
        ordenarLocais(autocarros, ordenacao);

    for (const auto& autocarro: autocarros)
        cout << autocarro << endl;
}

void Aeroporto::showLocalTransporteProximo() const{
    if (getLocalTransporteProximo().getDistancia() == 0.0) {
        cout << "Não existe local de transporte terrestre próximo a este aeroporto." << endl;
        return;
    }
    cout << getLocalTransporteProximo() << endl;
}

void Aeroporto::showMetroProximo() const{
    if (getLocalTransporteProximo().getDistancia() == 0.0) {
        cout << "Não existe local de Metro próximo a este aeroporto." << endl;
        return;
    }
    cout << getMetroProximo() << endl;
}

void Aeroporto::showComboioProximo() const{
    if (getComboioProximo().getDistancia() == 0.0) {
        cout << "Não existe local de Comboio próximo a este aeroporto." << endl;
        return;
    }
    cout << getComboioProximo() << endl;
}

void Aeroporto::showAutocarroProximo() const{
    if (getLocalTransporteProximo().getDistancia() == 0.0) {
        cout << "Não existe local de Autocarro próximo a este aeroporto." << endl;
        return;
    }
    cout << getAutocarroProximo() << endl;
}

bool Aeroporto::operator< (const Aeroporto &a1) const {
    return this->nome < a1.nome;
}

bool criterioComparacao2(const LocalDeTransporte &l1, const LocalDeTransporte &l2) {
    if (l1.getDisponibilidade() != l2.getDisponibilidade())
        return l1.getDisponibilidade() < l2.getDisponibilidade();
    else if (l1.getDistancia() != l2.getDistancia())
        return l1.getDistancia() < l2.getDistancia();
    else
        return l1.getTipo() < l2.getTipo();
}

bool criterioComparacao3(const LocalDeTransporte &l1, const LocalDeTransporte &l2) {
    if (l1.getTipo() != l2.getTipo())
        return l1.getTipo() < l2.getTipo();
    else if (l1.getDistancia() != l2.getDistancia())
        return l1.getDistancia() < l2.getDistancia();
    else
        return l1.getDisponibilidade() < l2.getDisponibilidade();
}

void ordenarLocais(vector <LocalDeTransporte>& locais, int ordenacao)
{
    if (ordenacao == 2)
        sort ( locais.begin(), locais.end(), criterioComparacao2);
    else
        sort (locais.begin(), locais.end(), criterioComparacao3);
}
