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

vector<Bilhete> CompanhiaAerea::getBilhetesVendidos() const {
    return bilhetesVendidos;
}

vector<Voo> CompanhiaAerea::getVoos() const{
    return voos;
}

list<Aviao> CompanhiaAerea::getAvioes() const {
    return avioes;
}

vector<Aeroporto> CompanhiaAerea::getAeroportos() const {
    return aeroportos;
}

void CompanhiaAerea::setVoos(const vector<Voo>& v) {
    this->voos = v;
    sort(voos.begin(), voos.end());
}

void CompanhiaAerea::addVoo(const Voo &v) {
    voos.push_back(v);
    sort(voos.begin(), voos.end());
}

Bilhete CompanhiaAerea::getBilheteID(unsigned int bId) const {
    for (Bilhete b: bilhetesVendidos)
        if (b.getIdBilhete() == bId)
            return b;
    return Bilhete();
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
        cout << "Este passageiro ainda não adquiriu nenhum bilhete." <<endl;
        return;
    }
    for (Bilhete b: bilhetes) {
        cout << b << endl;
    }
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
    if (passageiros.empty()){
        cout << "Voo sem passageiros." << endl;
        return;
    }
    for (const auto& passageiro: passageiros){
        cout << passageiro << endl;
    }
}

Bilhete CompanhiaAerea::getBilhetePassageiroVoo(unsigned pId, unsigned numVoo) const {
    vector<Bilhete> bilhetes = getBilhetesFromPassageiro(pId);
    for (Bilhete b: bilhetes) {
        if (b.getVoo().getNumeroVoo() == numVoo)
            return b;
    }
    return Bilhete();
}

bool CompanhiaAerea::adquirirBilhete(const Passageiro& p, Voo& v, bool bagagem) {
    if (!v.addPassageiro(p))
        return false;
    Bilhete b(Bilhete::getIdCount()+1, p, v, bagagem);
    bilhetesVendidos.push_back(b);
    sort(bilhetesVendidos.begin(), bilhetesVendidos.end());
    return true;
}

//todos os passageiros do grupo têm a mesma opção relativa a bagagem de mão
bool CompanhiaAerea::adquirirConjuntoBilhetes(list<Passageiro> &p, Voo &v, bool bagagem) {
    if (!v.addConjuntoPassageiros(p))
        return false;

    list<Passageiro>::const_iterator it;
    for (it = p.begin(); it != p.end(); it++) {
        Bilhete b(Bilhete::getIdCount()+1, *it, v, bagagem);
        bilhetesVendidos.push_back(b);
    }
    sort(bilhetesVendidos.begin(), bilhetesVendidos.end());
    return true;
}

bool CompanhiaAerea::cancelarViagem(const Passageiro &p, Voo &v) {
    Bilhete b = getBilhetePassageiroVoo(p.getId(), v.getNumeroVoo());
    if (b.getIdBilhete() == 0)
        return false;
    if (find(v.getPassageirosCheckedIn().begin(), v.getPassageirosCheckedIn().end(), p) == v.getPassageirosCheckedIn().end())
        return false;
    vector<Bilhete>::iterator it = find(bilhetesVendidos.begin(), bilhetesVendidos.end(), b);
    bilhetesVendidos.erase(it);
    v.removerPassageiro(p);
}

void CompanhiaAerea::realizarCheckIn(unsigned bId) const {
    Bilhete bilhete = getBilheteID(bId);
    list<Bagagem*>::iterator it;
    for (it = bilhete.getBagagem().begin(); it != bilhete.getBagagem().end(); it++) {
        if (!(*it)->isBagagemDeMao()) {
            if ((*it)->isCheckInAutomatico())
                bilhete.getVoo().getTransportador().adicionarAoTapete(*it);
            if (excessoPeso.excedePeso(*it))
                bilhete.getPasssageiro().incrementarMulta(excessoPeso.multaExcessoPeso(*it));
        }
        else
            bilhete.getPasssageiro().incrementarMulta(excessoPeso.multaTaxaBagagemDeMao(*it));
    }
    bilhete.getVoo().realizarCheckIn(bilhete.getPasssageiro());
}

vector<Voo> CompanhiaAerea::getVoosChegada(const string& cidadeChegada, const Data& d) const {
    vector<Voo> result;
    for (const auto& v: voos)
        if (v.getDestino().getCidade() == cidadeChegada && (d == Data() || d == v.getDataPartida()))
            result.push_back(v);
    return result;
}

vector<Voo> CompanhiaAerea::getVoosPartida(const string& cidadePartida, const Data& d) const {
    vector <Voo> result;
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
        if (d1 <= v.getDataPartida() || v.getDataPartida()<=d2)
            result.push_back(v);
    }
    return result;
}

void CompanhiaAerea::showVoos() const {
    if (voos.empty()){
        cout << "Nao ha voos disponiveis." << endl;
        return;
    }
    for (const auto& voo : voos){
        cout << voo;
    }
}

void CompanhiaAerea::showVoosPartida(const string &cidadePartida, const Data &d1) const {
    vector <Voo> voosPartida= getVoosPartida(cidadePartida,d1);

    if (voosPartida.empty()){
        cout << "Nao existe voo com partida em "<< cidadePartida;
        if (!(d1 == Data()))
            cout<< " para a data " << d1.getData();
        return;
    }
    for (const auto& voo : voosPartida){
        cout << voo;
    }
}

void CompanhiaAerea::showVoosChegada(const string &cidadeChegada, const Data &d1) const {
    vector <Voo> voosChegada= getVoosChegada(cidadeChegada, d1);

    if (voosChegada.empty()) {
        cout << "Não existe voo com chegada a "<< cidadeChegada;
        if (!(d1 == Data()))
            cout << " para a data " << d1.getData() ;
        cout << endl;
        return;
    }
    for (const auto& voo : voosChegada){
        cout << voo;
    }
}

void CompanhiaAerea::showVoosCidades(const string &cidadePartida, const string &cidadeChegada, const Data &d1, const Data &d2) const {
    vector <Voo> voosCidade = getVoosCidades(cidadePartida, cidadeChegada, d1, d2);

    if (voosCidade.empty()){
        cout<< "Nao ha voo com partida em " << cidadePartida << " e chegada a " << cidadeChegada << " no periodo indicado." << endl;
        return;
    }

    for (const auto& voo : voosCidade){
        cout << voo;
    }
}

void CompanhiaAerea::showVoosDatas(const Data &d1, const Data &d2) const {
    vector <Voo> voosDatas = getVoosDatas(d1, d2);

    if (voosDatas.empty()){
        cout << "Nao ha voo disponivel para o periodo indicado." <<endl;
        return;
    }

    for (const auto& voo: voosDatas){
        cout<<voo;
    }
}

void CompanhiaAerea::loadData(string ficheiroAvioes, string ficheiroVoos, string ficheiroBilhetes) {
    ifstream f;
    int numAvioes;
    queue<Servico> servicos;

    f.open("avioes.txt");
    if (!f.is_open())
        cout << "Ficheiro nao exite." << endl;
    f >> numAvioes;
}

void CompanhiaAerea::addAviao(const Aviao &aviao) {
    avioes.push_back(aviao);
}

void CompanhiaAerea::addAeroporto(const Aeroporto &aeroporto) {
    if (aeroportos.empty())
        aeroportos.push_back(aeroporto);
    unsigned index= binarySearchAeroporto(aeroporto);
    if (aeroportos.at(index).getNome() == aeroporto.getNome())
        return;
    else if (aeroportos.at(index) < aeroporto)
        aeroportos.insert (aeroportos.begin() + index + 1, aeroporto);
    else
        aeroportos.insert(aeroportos.begin() + index, aeroporto);
}

unsigned CompanhiaAerea::binarySearchAeroporto(const Aeroporto &aeroporto) {
    unsigned left = 0;
    unsigned right = aeroportos.size() - 1;
    unsigned middle;

    while (left <= right) {
        middle = (left + right) / 2;
        if (aeroportos.at(middle) < aeroporto)
            left = middle + 1;
        else if (aeroporto < aeroportos.at(middle))
            right = middle - 1;
        else
            return middle;
    }
    return middle;
}












