#ifndef _AEROPORTO_H
#define _AEROPORTO_H

#include "Voo.h"
#include <string>
#include <list>
using namespace std;

class Aeroporto {
private:
    string nome;
    string cidade;
    list<Voo> voos;
    //sofia: list<LocalTransporte> quando a classe estiver criada
public:
    Aeroporto();
    Aeroporto(string n, string c);
    string getNome() const;
    string getCidade() const;
    list<Voo> getVoos() const;
    //isabel: acho que não precisamos de setters nesta classe, o que acham?
    void setNome(const string &nome);
    void setCidade(const string &cidade);
    void setVoos(const list<Voo> &v);

};

#endif //_AEROPORTO_H