#ifndef _AEROPORTO_H
#define _AEROPORTO_H

#include <string>
using namespace std;

class Aeroporto {
private:
    string nome;
    string cidade;
    //list<LocalTransporte> - quando a classe estiver criada
public:
    Aeroporto();
    Aeroporto(string n, string c);
    string getNome() const;
    string getCidade() const;
    //isabel: acho que não precisamos de setters nesta classe, o que acham?
    void setNome(const string &nome);
    void setCidade(const string &cidade);

};

#endif //_AEROPORTO_H
