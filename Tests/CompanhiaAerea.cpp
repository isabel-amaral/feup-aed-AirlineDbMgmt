#include "CompanhiaAerea.h"
#include <iostream>
#include <algorithm>

CompanhiaAerea::CompanhiaAerea() {
    bilhetesVendidos = vector<Bilhete>();
}

vector<Bilhete> CompanhiaAerea::getBilhetesVendidos() const {
    return bilhetesVendidos;
}

unsigned CompanhiaAerea::BinarySearchPassageiro(const Passageiro &p) const {
    int left = 0, right = bilhetesVendidos.size() - 1;
    int middle;
    while (left <= right) {
        middle = (left + right)/2;
        if (bilhetesVendidos[middle].getPasssageiro().getNome() < p.getNome())
            left = middle + 1;
        else if (bilhetesVendidos[middle].getPasssageiro().getNome() > p.getNome())
            right = middle - 1;
        else
            return middle;
    }
    return bilhetesVendidos.size(); //caso o passageiro não seja encontrado
}

vector<Bilhete> CompanhiaAerea::getBilhetesFromPassageiro(const Passageiro& p) const {
    vector<Bilhete> bilhetes;
    unsigned index = BinarySearchPassageiro(p);
    bilhetes.push_back(bilhetesVendidos[index]);

    bool passageiroDiferente = false;
    for (int i = index-1; i >= 0 && !passageiroDiferente; i--) {
        if (bilhetesVendidos[i].getPasssageiro().getNome() == p.getNome())
            bilhetes.push_back(bilhetesVendidos[i]);
        else
            passageiroDiferente = true;
    }
    passageiroDiferente = false;
    for (int i = index+1; i < bilhetesVendidos.size(); i++) {
        if (bilhetesVendidos[i].getPasssageiro().getNome() == p.getNome())
            bilhetes.push_back(bilhetesVendidos[i]);
        else
            passageiroDiferente = true;
    }
    sort(bilhetes.begin(), bilhetes.end());
    return bilhetes;
}

void CompanhiaAerea::mostrarBilhetesFromPassageiro(const Passageiro &p) const {
    vector<Bilhete> bilhetes = getBilhetesFromPassageiro(p);
    for (Bilhete b: bilhetes) {
        cout << "Bilhete para " << b.getVoo().getDestino().getNome() << " com partida de " << b.getVoo().getOrigem().getNome() << endl;
        cout << "Voo número " << b.getVoo().getNumeroVoo() << endl;
        cout << "Partida prevista às " << b.getVoo().getHoraPartida() << " com chegada prevista às " << b.getVoo().getHoraChegada();
        cout << " no dia " << b.getVoo().getDataPartida().getData() << endl;
        cout << "A duração do voo será aproximadamente " << b.getVoo().getDuracao() << endl;
        if (b.temBagagemDeMao())
            cout << p.getNome() << " tem direito a levar bagagem de mão" << endl;
        else
            cout << p.getNome() << " não tem direito a levar bagagem de mão" << endl;
        cout << endl;
    }
}

bool CompanhiaAerea::adquirirBilhete(const Passageiro& p, Voo& v, bool bagagem) {
    if (!v.addPassageiro(p))
        return false;
    Bilhete b(v, bagagem, p);
    bilhetesVendidos.push_back(b);
    sort(bilhetesVendidos.begin(), bilhetesVendidos.end());
    return true;
}

//todos os passageiros do grupo têm a mesma opção relativa a bagagem de mão
bool CompanhiaAerea::adquirirConjuntoBilhetes(const list<Passageiro> &p, Voo &v, bool bagagem) {
    if (!v.addConjuntoPassageiros(p))
        return false;

    list<Passageiro>::const_iterator it;
    for (it = p.begin(); it != p.end(); it++) {
        Bilhete b(v, bagagem, *it);
        bilhetesVendidos.push_back(b);
    }
    sort(bilhetesVendidos.begin(), bilhetesVendidos.end());
    return true;
}