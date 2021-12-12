#ifndef _AEROPORTO_H
#define _AEROPORTO_H

#include "Voo.h"
#include <string>
#include <list>
using namespace std;

class Aeroporto {
private:
    /**
     * nome do aeroporto
     */
    string nome;
    /**
     * cidade onde o aeroporto se localiza
     */
    string cidade;

    //sofia: dividi os voos do aeroporto em partida e chegada mas nao sei se vai dar jeito assim dps
    //isabel: para já comentei pq tbm n sei se vai dar jeito. a ideia de termos uma classe aeroporto era para associarmos cada voo a um aeroporto, não o contrário
    /*
    /**
     * todos os voos que têm como origem o aeroporto e que estão agendados/por realizar
     *//*
    list<Voo> voosPartida;
    *//**
     * todos os voos que têm como destino o aeroporto e que estão agendados/por realizar
     *//*
    list<Voo> voosChegada;
    */

    //sofia: list<LocalTransporte> quando a classe estiver criada
public:
    Aeroporto();
    Aeroporto(string n, string c);
    /**
     *
     * @return nome do aeroporto
     */
    string getNome() const;
    /**
     *
     * @return cidade do aeroporto
     */
    string getCidade() const;

    /*
    /**
    *
    * @return todos os voos que partem do aeroporto e que estão agendados/por realizar
    *//*
    list<Voo> getVoosPartida() const;
    *//**
    *
    * @return todos os voos que chegam ao aeroporto e que estão agendados/por realizar
    *//*
    list<Voo> getVoosChegada() const;
    */

    /*
    void setNome(const string &nome);
    void setCidade(const string &cidade);
    void setVoosPartida(const list<Voo> &v);
    void setVoosChegada(const list<Voo> &v);
    */
};

#endif //_AEROPORTO_H