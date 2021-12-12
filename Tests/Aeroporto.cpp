#include "Aeroporto.h"
using namespace std;

Aeroporto::Aeroporto() {
    this->nome = "";
    this->cidade = "";
    /*
    voosPartida.clear();
    voosChegada.clear();
     */
}

Aeroporto::Aeroporto(string n, string c) {
    this->nome = n;
    this->cidade = c;
    /*
    voosPartida = vp;
    voosChegada = vc;
     */
}


//-------------------------------------------------------------------------------------------------------
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