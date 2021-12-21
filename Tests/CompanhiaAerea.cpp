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
bool CompanhiaAerea::adquirirConjuntoBilhetes(list<Passageiro> &p, Voo &v, bool bagagem, list <list<Bagagem*> > bagagens) {
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
        return true;
    }
    for (const auto& voo: voosPartida)
        cout <<  "---------------" << voo;
    cout << endl;
    return false;
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

void CompanhiaAerea::loadData() {
    this->loadAvioes();
    this->loadServicos();
    this->loadAeroportos();
    this->loadLocaisTransporte();
    this->loadVoosAndBilhetes();
    this->loadBagagens();
    this->loadTransportadorBagagem();
    this->loadExcessoPeso();
}

void CompanhiaAerea::loadAvioes() {
    ifstream f;
    int num;
    string matricula, tipo, text;
    int capacidade;


    f.open("avioes.txt");
    if (!f.is_open())
        cout << "Ficheiro nao existe." << endl;

    f >> num;
    f.ignore(LONG_MAX, '\n');
    while (!f.eof() && num > 0){
        f.ignore(LONG_MAX, '\n');
        getline (f, matricula);
        getline (f, tipo);
        getline (f, text);
        capacidade = stoi(text);
        this->addAviao(Aviao(matricula, tipo, capacidade));
        num--;
    }
    f.close();
}

void CompanhiaAerea::loadServicos() {
    ifstream f;
    int num;
    string matricula, text, nomeFunc;
    TipoServico tipo;
    int dia, mes, ano, idFunc;

    f.open("servicos.txt");
    if (!f.is_open())
        cout << "Ficheiro nao existe." << endl;

    f >> num;
    f.ignore(LONG_MAX, '\n');
    while (!f.eof() && num > 0) {
        f.ignore(LONG_MAX, '\n');
        getline(f, matricula);
        getline(f, text);
        if (text == "0\t")
            tipo = Manutencao;
        else
            tipo = Limpeza;

        getline(f, text);
        istringstream data(text);
        data >> dia >> mes >> ano;
        Data d1(dia, mes, ano);

        getline(f, text);
        idFunc = stoi(text);

        getline(f, nomeFunc);
        Funcionario f1(idFunc, nomeFunc);

        for (Aviao& a: avioes) {
            if (a.getMatricula() == matricula) {
                Servico s(tipo, d1, f1);
                a.addServicoPorRealizar(s);
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
    f.ignore(LONG_MAX, '\n');
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
            f >> auxDia;
        }

        unsigned index = binarySearchAeroporto(nome);
        aeroportos[index].addTransporte(LocalDeTransporte(dist, tipo, horarios));
        horarios.clear();
        num--;
    }
    f.close();
}

void CompanhiaAerea::loadVoosAndBilhetes() {
//--------Ler Passageiros------------
    vector<Passageiro> p;
    ifstream f;
    string text;
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
    while(!f.eof() && num > 0) {
        f.ignore(LONG_MAX, '\n');
        getline(f, nomePassageiro);
        getline (f, text);
        idPassageiro = stoi(text);
        getline (f, text);
        idadePassageiro = stoi(text);
        getline (f, text);
        menorNaoAcompanhado = (text == "true");

        Passageiro p1 (nomePassageiro, idPassageiro, idadePassageiro, menorNaoAcompanhado);
        p.push_back(p1);

        num--;
    }
    f.close();

//------Ler Voos----
    int idVoo, lotacao, reservas;
    int dia, mes, ano;
    unsigned indexOrigem, indexDestino;
    float hPartida, hChegada, duracao;
    string origem, destino, matricula;

    f.open("voos.txt");
    if (!f.is_open())
        cout << "Ficheiro nao existe." << endl;

    f >> num;
    f.ignore(LONG_MAX, '\n');
    while(!f.eof() && num > 0) {
        f.ignore(LONG_MAX, '\n');
        getline (f, text);
        idVoo = stoi(text);
        getline (f, origem);
        getline (f, destino);
        getline (f, text);
        istringstream data(text);
        data >> dia >> mes >> ano;
        getline(f, text);
        hPartida = stof(text);
        getline(f, text);
        hChegada = stof(text);
        getline(f, text);
        duracao = stof(text);
        getline(f, text);
        lotacao = stoi(text);
        getline(f, text);
        reservas = stoi(text);
        indexOrigem = this->binarySearchAeroporto(origem);
        indexDestino = this->binarySearchAeroporto(destino);
        Voo v(idVoo, aeroportos.at(indexOrigem), aeroportos.at(indexDestino), Data (dia,mes,ano), hPartida, hChegada, duracao, lotacao, reservas);

        getline(f, text);
        istringstream passageiros(text);
        while(passageiros >> idPassageiro)
            v.addPassageiro(p.at(idPassageiro-1));

        getline(f, matricula);
        for (auto it = avioes.begin(); it != avioes.end(); it++) {
            if (it->getMatricula() == matricula) {
                it->addVoo(v);
                break;
            }
        }
        this->addVoo(v);
        num--;
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
    while (!f.eof() && num > 0) {
        f.ignore(LONG_MAX, '\n');
        getline(f, text);
        idBilhete = stoi(text);
        getline(f, text);
        idPassageiro = stoi(text);
        getline(f, text);
        idVoo = stoi(text);
        getline(f, text);
        bagagemMao = (text == "true");

        for (const Voo& v: voos) {
            if (v.getNumeroVoo() == idVoo){
                Bilhete b(idBilhete, p.at( idPassageiro -1), v, bagagemMao);
                bilhetesVendidos.push_back(b);
                break;
            }
        }
        num--;
    }
    f.close();
}

void CompanhiaAerea::loadBagagens() {
    ifstream f;
    unsigned num;
    string text;
    float peso;
    bool bagagemMao;
    unsigned idBilhete;
    list<Bagagem*> bagagens;

    f.open("bagagens.txt");
    if (!f.is_open())
        cout << "Ficheiro nao existe." << endl;

    f >> num;
    f.ignore(LONG_MAX, '\n');
    while(!f.eof() && num > 0) {
        f.ignore(LONG_MAX, '\n');
        getline(f, text);
        peso = stof(text);
        getline(f, text);
        bagagemMao = (text == "true");
        getline(f, text);
        idBilhete = stoi(text);

        Bagagem* b = new Bagagem(peso, bagagemMao);
        //bagagens.push_back(b);
        for (Bilhete& bilhete: bilhetesVendidos) {
            if (bilhete.getIdBilhete() == idBilhete) {
                list<Bagagem*> aux = bilhete.getBagagem();
                aux.push_back(b);
                bilhete.setBagagem(aux);
            }
        }
        num--;
    }
    f.close();
}

//Todos os voos da companhia aérea, independentemente dos aeroportos onde são realizados, usam o mesmo tipo de transportadores
void CompanhiaAerea::loadTransportadorBagagem() {
    ifstream f;
    unsigned c, n, m, capacidade;

    f.open("transportadorDeBagagem.txt");
    if (!f.is_open())
        cout << "Ficheiro nao existe." << endl;

    f >> c;
    f >> n;
    f >> m;
    f >> capacidade;
    for (Voo& v: voos)
        v.setTransportador(c, n, m, capacidade);
}

//O valor maximo de cada volume de bagagem e as taxas a pagar por incumprimento das regras são os mesmos para todos os voos da companhia
void CompanhiaAerea::loadExcessoPeso() {
    ifstream f;
    float p, tp, tb;

    f.open("excessoPeso.txt");
    if (!f.is_open())
        cout << "Ficheiro nao existe." << endl;

    f >> p;
    f >> tp;
    f >> tb;
    excessoPeso = ExcessoPeso(p, tp, tb);
}