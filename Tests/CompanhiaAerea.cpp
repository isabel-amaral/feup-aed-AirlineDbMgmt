#include "CompanhiaAerea.h"
#include <iostream>
#include <algorithm>
#include <fstream>

CompanhiaAerea::CompanhiaAerea() {
    bilhetesVendidos = vector<Bilhete>();
    voos = vector<Voo>();
    excessoPeso = ExcessoPeso();
    aeroportos = vector<Aeroporto>();
}

CompanhiaAerea::CompanhiaAerea(float pesoMaximo, float taxaPesoExtra, float taxaBagagemDeMao) {
    bilhetesVendidos = vector<Bilhete>();
    voos = vector<Voo>();
    excessoPeso = ExcessoPeso(pesoMaximo, taxaPesoExtra, taxaBagagemDeMao);
}

vector<Bilhete>& CompanhiaAerea::getBilhetesVendidos() {
    return bilhetesVendidos;
}

vector<Voo>& CompanhiaAerea::getVoos() {
    return voos;
}

list<Aviao>& CompanhiaAerea::getAvioes() {
    return avioes;
}

vector<Aeroporto>& CompanhiaAerea::getAeroportos() {
    return aeroportos;
}

/*void CompanhiaAerea::setVoos(const vector<Voo>& v) {
    this->voos = v;
    sort(voos.begin(), voos.end());
}*/

void CompanhiaAerea::setExcessoPeso(const ExcessoPeso &excessoPeso) {
    this->excessoPeso = excessoPeso;
}

void CompanhiaAerea::addVoo(const Voo &v) {
    voos.push_back(v);
    sort(voos.begin(), voos.end());
}

void CompanhiaAerea::addAviao(const Aviao &aviao) {
    avioes.push_back(aviao);
}

unsigned CompanhiaAerea::binarySearchAeroporto(const string& nome ) {
    unsigned left = 0;
    unsigned right = aeroportos.size() - 1;
    unsigned middle;

    while (left <= right) {
        middle = (left + right) / 2;
        if (aeroportos.at(middle).getNome() < nome)
            left = middle + 1;
        else if (nome < aeroportos.at(middle).getNome())
            right = middle - 1;
        else
            return middle;
    }
    return middle;
}

void CompanhiaAerea::addAeroporto(const Aeroporto& aeroporto) {
    if (aeroportos.empty())
        aeroportos.push_back(aeroporto);
    unsigned index = binarySearchAeroporto(aeroporto.getNome());
    if (aeroportos.at(index).getNome() == aeroporto.getNome())
        return;
    else if (aeroportos.at(index) < aeroporto)
        aeroportos.insert (aeroportos.begin() + index + 1, aeroporto);
    else
        aeroportos.insert(aeroportos.begin() + index, aeroporto);
}

Bilhete& CompanhiaAerea::getBilheteID(unsigned int bId) {
    for (Bilhete& b: bilhetesVendidos)
        if (b.getIdBilhete() == bId)
            return b;
    Bilhete bilhete;
    return bilhete;
}

vector<Bilhete> CompanhiaAerea::getBilhetesFromPassageiro(unsigned pId) const {
    vector<Bilhete> bilhetes;
    for (int i = 0; i < bilhetesVendidos.size(); i++) {
        if (bilhetesVendidos[i].getPasssageiro().getId() == pId) {
            bilhetes.push_back(bilhetesVendidos[i]);
            if (i < bilhetesVendidos.size()-1 && bilhetesVendidos[i+1].getPasssageiro().getId() != pId)
                break;  //vetor encontra-se ordenado por ordem alfabética do nome dos passageiros
        }
    }
    return bilhetes;
}

void CompanhiaAerea::showBilhetesFromPassageiro(unsigned pId) const {
    vector<Bilhete> bilhetes = getBilhetesFromPassageiro(pId);
    if (bilhetes.empty()){
        cout << "Este passageiro ainda nao adquiriu nenhum bilhete." <<endl;
        return;
    }
    for (Bilhete b: bilhetes) {
        cout << b << endl;
    }
    cout << endl;
}

vector<Passageiro> CompanhiaAerea::getPassageirosFromVoo(unsigned numVoo) const {
    vector<Passageiro> passageiros;
    for (Bilhete b: bilhetesVendidos) {
        if (b.getVoo().getNumeroVoo() == numVoo)
            passageiros.push_back(b.getPasssageiro());
    }
    return passageiros;
}

void CompanhiaAerea::showPassageirosFromVoo(unsigned numVoo) const {
    vector<Passageiro> passageiros = getPassageirosFromVoo(numVoo);
    if (passageiros.empty()) {
        cout << "Voo sem passageiros." << endl;
        return;
    }
    for (const auto& passageiro: passageiros) {
        cout << passageiro << endl;
    }
    cout << endl;
}

Bilhete CompanhiaAerea::getBilhetePassageiroVoo(unsigned pId, unsigned numVoo) const {
    vector<Bilhete> bilhetes = getBilhetesFromPassageiro(pId);
    for (Bilhete b: bilhetes) {
        if (b.getVoo().getNumeroVoo() == numVoo)
            return b;
    }
    return Bilhete();
}

bool CompanhiaAerea::adquirirBilhete(const Passageiro& p, Voo& v, bool bagagem, const list<Bagagem *>& bagagens) {
    for (Voo& voo: voos) {
        if (voo.getNumeroVoo() == v.getNumeroVoo()) {
            if (!voo.addPassageiro(p))
                return false;
            Bilhete b(Bilhete::getIdCount()+1, p, v, bagagem, bagagens);
            bilhetesVendidos.push_back(b);
            sort(bilhetesVendidos.begin(), bilhetesVendidos.end());
            return true;
        }
    }
    return false;
}

//todos os passageiros do grupo têm a mesma opção relativa a bagagem de mão
bool CompanhiaAerea::adquirirConjuntoBilhetes(list<Passageiro>& p, Voo& v, bool bagagem, list<list<Bagagem*>> bagagens) {
    for (Voo& voo: voos) {
        if (voo.getNumeroVoo() == v.getNumeroVoo()) {
            if (!voo.addConjuntoPassageiros(p))
                return false;
            list<Passageiro>::iterator it;
            list<list<Bagagem *> >:: iterator j;
            for (it = p.begin(), j =bagagens.begin() ; it != p.end() && j != bagagens.end(); it++, j++) {
                Bilhete b(Bilhete::getIdCount()+1, *it, v, bagagem, *j);
                bilhetesVendidos.push_back(b);
            }
            sort(bilhetesVendidos.begin(), bilhetesVendidos.end());
            return true;
        }
    }
    return false;
}

bool CompanhiaAerea::cancelarViagem(unsigned bId) {
    Bilhete b = getBilheteID(bId);
    if (find(b.getVoo().getPassageirosCheckedIn().begin(), b.getVoo().getPassageirosCheckedIn().end(), b.getPasssageiro()) != b.getVoo().getPassageirosCheckedIn().end())
        return false;
    vector<Bilhete>::iterator it = find(bilhetesVendidos.begin(), bilhetesVendidos.end(), b);
    bilhetesVendidos.erase(it);
    for (Voo& voo: voos)
        if (voo.getNumeroVoo() == b.getVoo().getNumeroVoo()) {
            voo.removerPassageiro(b.getPasssageiro());
            return true;
        }
    return false;
}

bool CompanhiaAerea::realizarCheckIn(unsigned bId) {
    Bilhete& bilhete = getBilheteID(bId);
    if (bId == 0) //Bilhete não existe
        return false;
    if (bilhete.isCheckedIn()) //O check-in para este bilhete já foi realizado
        return false;

    list<Bagagem*>::const_iterator it;
    for (it = bilhete.getBagagem().begin(); it != bilhete.getBagagem().end(); it++) {
        if (!(*it)->isBagagemDeMao()) {
            if ((*it)->isCheckInAutomatico())
                bilhete.getVoo().getTransportador().adicionarAoTapete(*it);
            if (excessoPeso.excedePeso(*it))
                bilhete.getPasssageiro().incrementarMulta(excessoPeso.multaExcessoPeso(*it));
        }
        else if (!bilhete.temBagagemDeMao())
            bilhete.getPasssageiro().incrementarMulta(excessoPeso.multaTaxaBagagemDeMao(*it));
    }

    for (Voo& voo: voos)
        if (voo.getNumeroVoo() == bilhete.getVoo().getNumeroVoo()) {
            voo.realizarCheckIn(bilhete.getPasssageiro());
            bilhete.realizarCheckIn();
            return true;
        }
    return false;
}

vector<Voo> CompanhiaAerea::getVoosChegada(const string& cidadeChegada, const Data& d) const {
    vector<Voo> result;
    for (auto& v: voos)
        if (v.getDestino().getCidade() == cidadeChegada && (d == Data() || d == v.getDataPartida()))
            result.push_back(v);
    return result;
}

vector<Voo> CompanhiaAerea::getVoosPartida(const string& cidadePartida, const Data& d) const{
    vector<Voo> result;
    for (const auto& v: voos)
        if (v.getOrigem().getCidade() == cidadePartida && (d == Data() || v.getDataPartida() == d))
            result.push_back(v);
    return result;
}

vector<Voo> CompanhiaAerea::getVoosCidades(const string& cidadePartida, const string& cidadeChegada, const Data& d1, const Data& d2) const {
    vector<Voo> result;

    for (const auto& v: voos){
        if ( v.getOrigem().getCidade() == cidadePartida && v.getDestino().getCidade()== cidadeChegada && (d1 <= v.getDataPartida() || v.getDataPartida()<=d2)) {
            result.push_back(v);
        }
    }
    return result;
}

vector<Voo> CompanhiaAerea::getVoosDatas(const Data& d1, const Data& d2) const {
    vector<Voo> result;
    for (const auto& v : voos){
        if (d1 <= v.getDataPartida() || v.getDataPartida() <= d2)
            result.push_back(v);
    }
    return result;
}

bool CompanhiaAerea::showVoos() const {
    if (voos.empty()) {
        cout << "Nao ha voos disponiveis." << endl;
        return false;
    }
    for (const auto& voo: voos)
        cout << "---------------" << voo;
    cout << endl;
    return true;
}

bool CompanhiaAerea::showVoosPartida(const string& cidadePartida, const Data& d1) const {
    vector<Voo> voosPartida = getVoosPartida(cidadePartida, d1);

    if (voosPartida.empty()){
        cout << "Nao existe voo com partida em "<< cidadePartida;
        if (!(d1 == Data()))
            cout << " para a data " << d1.getData();
        return false;
    }
    for (const auto& voo: voosPartida)
        cout <<  "---------------" << voo;
    cout << endl;
    return true;
}

bool CompanhiaAerea::showVoosChegada(const string& cidadeChegada, const Data& d1) const {
    vector<Voo> voosChegada = getVoosChegada(cidadeChegada, d1);

    if (voosChegada.empty()) {
        cout << "Nao existe voo com chegada a "<< cidadeChegada;
        if (!(d1 == Data()))
            cout << " para a data " << d1.getData() ;
        cout << endl;
        return false;
    }
    for (const auto& voo: voosChegada)
        cout << voo;
    cout << "---------------" << endl;
    return true;
}

bool CompanhiaAerea::showVoosCidades(const string& cidadePartida, const string& cidadeChegada, const Data& d1, const Data& d2) const {
    vector<Voo> voosCidade = getVoosCidades(cidadePartida, cidadeChegada, d1, d2);

    if (voosCidade.empty()){
        cout << "Nao ha voo com partida em " << cidadePartida << " e chegada a " << cidadeChegada << " no periodo indicado." << endl;
        return false;
    }
    for (const auto& voo: voosCidade)
        cout << voo;
    cout << "---------------" << endl;
    return true;
}

bool CompanhiaAerea::showVoosDatas(const Data& d1, const Data& d2) const {
    vector<Voo> voosDatas = getVoosDatas(d1, d2);

    if (voosDatas.empty()){
        cout << "Nao ha voo disponivel para o periodo indicado." <<endl;
        return false;
    }
    for (const auto& voo: voosDatas)
        cout << voo;
    cout << "---------------" << endl;
    return true;
}