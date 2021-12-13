#ifndef _AEROPORTO_H
#define _AEROPORTO_H

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
    //sofia: list<LocalTransporte> quando a classe estiver criada

public:
    Aeroporto();
    Aeroporto(const string& n, const string& c);
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
    void setNome(const string &nome);
    void setCidade(const string &cidade);
    void setVoosPartida(const list<Voo> &v);
    void setVoosChegada(const list<Voo> &v);
    */
};

#endif //_AEROPORTO_H