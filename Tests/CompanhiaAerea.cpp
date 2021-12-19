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

void CompanhiaAerea::addAviao(const Aviao &aviao) {
    avioes.push_back(aviao);
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

void CompanhiaAerea::addAeroporto(const Aeroporto &aeroporto) {
    if (aeroportos.empty())
        aeroportos.push_back(aeroporto);
    unsigned index = binarySearchAeroporto(aeroporto);
    if (aeroportos.at(index).getNome() == aeroporto.getNome())
        return;
    else if (aeroportos.at(index) < aeroporto)
        aeroportos.insert (aeroportos.begin() + index + 1, aeroporto);
    else
        aeroportos.insert(aeroportos.begin() + index, aeroporto);
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
    if (passageiros.empty()){
        cout << "Voo sem passageiros." << endl;
        return;
    }
    for (const auto& passageiro: passageiros){
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

bool CompanhiaAerea::cancelarViagem(unsigned bId) {
    Bilhete b = getBilheteID(bId);
    if (find(b.getVoo().getPassageirosCheckedIn().begin(), b.getVoo().getPassageirosCheckedIn().end(), b.getPasssageiro()) == b.getVoo().getPassageirosCheckedIn().end())
        return false;
    vector<Bilhete>::iterator it = find(bilhetesVendidos.begin(), bilhetesVendidos.end(), b);
    bilhetesVendidos.erase(it);
    b.getVoo().removerPassageiro(b.getPasssageiro());
    return true;
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
    cout << endl;
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
    cout << endl;
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
    cout << endl;
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
    cout << endl;
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
    cout << endl;
}

void CompanhiaAerea::loadData() {
    this->loadAvioes();
    this->loadServicos();
    this->loadAeroportos();
    this->loadLocaisTransporte();
    //this->loadVoosAndBilhetes();
}

void CompanhiaAerea::loadAvioes() {
    ifstream f;
    int num;
    string matricula, tipo, aux;
    int capacidade;

    f.open("avioes.txt");
    if (!f.is_open())
        cout << "Ficheiro nao existe." << endl;

    f >> num;
    while (!f.eof() && num > 0){
        f.ignore(LONG_MAX, '\n');
        getline(f, matricula);
        getline(f, tipo);
        f >> capacidade;

        this->addAviao(Aviao(matricula, tipo, capacidade));
        num--;
    }
    f.close();
}

void CompanhiaAerea::loadServicos() {
    ifstream f;
    int num;
    string matricula, aux, nomeFunc;
    TipoServico tipo;
    int dia, mes, ano, idFunc;

    f.open("servicos.txt");
    if (!f.is_open())
        cout << "Ficheiro nao existe." << endl;

    f >> num;
    f.ignore(LONG_MAX, '\n');
    while (!f.eof() && num > 0) {
        getline(f, matricula);
        getline(f, aux);
        if (aux == "0")
            tipo = Manutencao;
        else
            tipo = Limpeza;

        f >> dia >> mes >> ano;
        Data d1(dia, mes, ano);
        f >> idFunc;
        f.ignore(LONG_MAX, '\n');
        getline(f, nomeFunc);
        Funcionario f1(idFunc, nomeFunc);

        for (Aviao a: avioes) {
            if (a.getMatricula() == matricula) {
                a.addServicoPorRealizar(Servico(tipo, d1, f1));
                break;
            }
        }
        num--;
    }
    f.close();
}

void CompanhiaAerea::loadAeroportos(){
    ifstream f;
    int num;
    string nome, cidade;

    f.open("aeroportos.txt");
    if (!f.is_open())
        cout << "Ficheiro nao existe." << endl;

    f >> num;
    while (!f.eof() && num > 0) {
        f.ignore(LONG_MAX, '\n');
        getline(f, nome);
        getline(f, cidade);
        this->addAeroporto(Aeroporto(nome, cidade));
        num--;
    }
    f.close();
}

void CompanhiaAerea::loadLocaisTransporte() {
    ifstream f;
    unsigned num, numHoras;
    float dist, hora;
    string nome, auxTransporte, auxDia;
    tipoTransporte tipo;
    DiaDaSemana dia;
    vector<float> horario;
    list<Horario> horarios;

    f.open("locaisDeTransporte.txt");
    if (!f.is_open())
        cout << "Ficheiro nao existe." << endl;

    f >> num;
    f.ignore(LONG_MAX, '\n');
    while (!f.eof() && num > 0) {
        f >> dist;
        f >> auxTransporte;
        if (auxTransporte == "0")
            tipo = Metro;
        else if (auxTransporte == "1")
            tipo = Comboio;
        else
            tipo = Autocarro;

        f.ignore(LONG_MAX, '\n');
        getline(f, nome);

        f >> auxDia;
        while (auxDia != "***" && !f.eof()) {
            if (auxDia == "0")
                dia = DiasUteis;
            else if (auxDia == "1")
                dia = Sabados;
            else
                dia = DomingosFeriados;

            f >> numHoras;
            horario.clear();
            for (int i = 0; i < numHoras; i++) {
                f >> hora;
                horario.push_back(hora);
            }
            Horario h(dia, horario);
            horarios.push_back(h);
            horarios.clear();

            f >> auxDia;
        }

        for (Aeroporto& a: aeroportos) {
            if (a.getNome() == nome) {
                a.addTransporte(LocalDeTransporte(dist, tipo, horarios));
                break;
            }
        }
        num--;
    }
    f.close();
}

/*
void CompanhiaAerea::loadVoosAndBilhetes() {
//-----Ler Passageiros:
    vector <Passageiro> p;
    ifstream f;
    int num;
    string nomePassageiro;
    int idPassageiro;
    int idadePassageiro;
    bool menorNaoAcompanhado;

    f.open("passageiros.txt");
    if (!f.is_open())
        cout << "Ficheiro nao existe." << endl;

    f >> num;
    f.ignore(LONG_MAX, '\n');

    while(!f.eof() && num>0) {
        getline(f, nomePassageiro);

        f >> idPassageiro;
        f.ignore(LONG_MAX, '\n');
        f >> idadePassageiro;
        f.ignore(LONG_MAX, '\n');
        f >> menorNaoAcompanhado;
        f.ignore(LONG_MAX, '\n');
        f.ignore(LONG_MAX, '\n');           // Ignorar separador "*"
        p.push_back(Passageiro(nomePassageiro, idPassageiro, idadePassageiro, menorNaoAcompanhado));
        num --;
    }
    f.close();

//------Ler Voos----
    int idVoo, lotacao, reservas;
    string origem, destino;
    int dia, mes, ano;
    float hPartida, hChegada, duracao;
    string matricula;
    unsigned indexOrigem, indexDestino;
    auto i = avioes.begin();


    f.open("voos.txt");
    if (!f.is_open())
        cout << "Ficheiro nao existe." << endl;

    f >> num;
    f.ignore(LONG_MAX, '\n');

    while(!f.eof() && num>0) {
        f >> idVoo;
        f.ignore(LONG_MAX, '\n');

        getline (f, origem);
        getline (f, destino);

        f >> dia >> mes >> ano;
        f.ignore(LONG_MAX, '\n');

        f >> hPartida;
        f.ignore(LONG_MAX, '\n');

        f >> hChegada;
        f.ignore(LONG_MAX, '\n');

        f >> duracao;
        f.ignore(LONG_MAX, '\n');

        f >> lotacao;
        f.ignore(LONG_MAX, '\n');

        f >> reservas;
        f.ignore(LONG_MAX, '\n');

        indexDestino = this->binarySearchAeroporto(Aeroporto(origem,""));
        indexOrigem = this->binarySearchAeroporto(Aeroporto(destino, ""));

        Voo v (idVoo, aeroportos.at(indexOrigem), aeroportos.at(indexDestino), Data (dia,mes,ano), hPartida, hChegada, duracao, lotacao, reservas);

        while (f >> idPassageiro)
            v.addPassageiro(p.at(idPassageiro-1));
        f.ignore(LONG_MAX, '\n');

        getline (f, matricula);

        if (i->getMatricula() != matricula) i++;

        i->addVoo(v);
        f.ignore(LONG_MAX, '\n');   // ignorar o separador "*"
        num --;
    }
    f.close();

//------Ler Bilhetes----
    unsigned idBilhete;
    bool bagagemMao;

    f.open("bilhetes.txt");
    if (!f.is_open())
        cout << "Ficheiro nao existe." << endl;

    f >> num;
    f.ignore(LONG_MAX, '\n');

    while(!f.eof() && num>0) {
        f >> idBilhete;
        f.ignore(LONG_MAX, '\n');

        f >> idVoo;
        f.ignore(LONG_MAX, '\n');

        f >> idPassageiro;
        f.ignore(LONG_MAX, '\n');

        f >> bagagemMao;
        f.ignore(LONG_MAX, '\n');

        f.ignore(LONG_MAX, '\n');   // ignorar o separador "*"

        Voo voo;
        for(Voo v: voos) if(v.getNumeroVoo() == idVoo) voo = v;
        Bilhete b(idBilhete, p.at(idPassageiro - 1 ), voo, bagagemMao);
        bilhetesVendidos.push_back(b);

        num--;
    }
}
*/
