#include "LoadData.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

LoadData::LoadData(CompanhiaAerea& ca) {
    this->loadAvioes(ca);
    this->loadServicos(ca);
    this->loadAeroportos(ca);
    this->loadLocaisTransporte(ca);
    this->loadVoosAndBilhetes(ca);
    this->loadBagagens(ca);
    this->loadTransportadorBagagem(ca);
    this->loadExcessoPeso(ca);
}

void LoadData::loadAvioes(CompanhiaAerea& ca) {
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
        ca.addAviao(Aviao(matricula, tipo, capacidade));
        num--;
    }
    f.close();
}

void LoadData::loadServicos(CompanhiaAerea& ca) {
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

        for (Aviao& aviao : ca.getAvioes()) {
            if (aviao.getMatricula() == matricula) {
                Servico s(tipo, d1, f1);
                aviao.addServicoPorRealizar(s);
                break;
            }
        }
        num--;
    }
    f.close();
}

void LoadData::loadAeroportos(CompanhiaAerea& ca){
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
        ca.addAeroporto(Aeroporto(nome, cidade));
        num--;
    }
    f.close();
}

void LoadData::loadLocaisTransporte(CompanhiaAerea& ca) {
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

        unsigned index = ca.binarySearchAeroporto(nome);
        ca.getAeroportos()[index].addTransporte(LocalDeTransporte(dist, tipo, horarios));
        horarios.clear();
        num--;
    }
    f.close();
}

void LoadData::loadVoosAndBilhetes(CompanhiaAerea& ca) {
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

        Passageiro p1(nomePassageiro, idPassageiro, idadePassageiro, menorNaoAcompanhado);
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
        indexOrigem = ca.binarySearchAeroporto(origem);
        indexDestino = ca.binarySearchAeroporto(destino);
        Voo v(idVoo, ca.getAeroportos()[indexOrigem], ca.getAeroportos()[indexDestino], Data (dia,mes,ano), hPartida, hChegada, duracao, lotacao, reservas);

        getline(f, text);
        istringstream passageiros(text);
        while(passageiros >> idPassageiro)
            v.addPassageiro(p.at(idPassageiro-1));

        getline(f, matricula);
        for (auto it = ca.getAvioes().begin(); it != ca.getAvioes().end(); it++) {
            if (it->getMatricula() == matricula) {
                it->addVoo(v);
                break;
            }
        }
        ca.addVoo(v);
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

        for (const Voo& v: ca.getVoos()) {
            if (v.getNumeroVoo() == idVoo){
                Bilhete b(idBilhete, p.at( idPassageiro -1), v, bagagemMao);
                ca.getBilhetesVendidos().push_back(b);
                break;
            }
        }
        num--;
    }
    f.close();
}

void LoadData::loadBagagens(CompanhiaAerea& ca) {
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
        for (Bilhete& bilhete: ca.getBilhetesVendidos()) {
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
void LoadData::loadTransportadorBagagem(CompanhiaAerea& ca) {
    ifstream f;
    unsigned c, n, m, capacidade;

    f.open("transportadorDeBagagem.txt");
    if (!f.is_open())
        cout << "Ficheiro nao existe." << endl;

    f >> c;
    f >> n;
    f >> m;
    f >> capacidade;
    for (Voo& v: ca.getVoos())
        v.setTransportador(c, n, m, capacidade);
}

//O valor maximo de cada volume de bagagem e as taxas a pagar por incumprimento das regras são os mesmos para todos os voos da companhia
void LoadData::loadExcessoPeso(CompanhiaAerea& ca) {
    ifstream f;
    float p, tp, tb;

    f.open("excessoPeso.txt");
    if (!f.is_open())
        cout << "Ficheiro nao existe." << endl;

    f >> p;
    f >> tp;
    f >> tb;
    ca.setExcessoPeso(ExcessoPeso(p, tp, tb));
}