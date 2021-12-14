#include "CompanhiaAerea.h"
#include <iostream>
#include <algorithm>

CompanhiaAerea::CompanhiaAerea() {
    bilhetesVendidos = vector<Bilhete>();
}

const vector<Bilhete>& CompanhiaAerea::getBilhetesVendidos() const {
    return bilhetesVendidos;
}

//TODO
const vector<Bilhete>& CompanhiaAerea::getBilhetesFromPassageiro(const Passageiro& p) const {
    vector<Bilhete> bilhetes;
    return bilhetes;
}

void CompanhiaAerea::mostrarBilhetesFromPassageiro(const Passageiro &p) const {
    vector<Bilhete> bilhetes = getBilhetesFromPassageiro(p);
    for (Bilhete b: bilhetes) {
        cout << "Bilhete para " << b.getVoo().getDestino().getNome() << " com partida de " << b.getVoo().getOrigem().getNome() << endl;
        cout << "Voo número " << b.getVoo().getNumeroVoo() << endl;
        cout << "Partida prevista às " << b.getVoo().getHoraPartida() << " com chegada prevista às " << b.getVoo().getHoraChegada() << " no dia " << b.getVoo().getDataPartida() << endl;
        cout << "A duração do voo será aproximadamente " << b.getVoo().getDuracao() << endl;
        if (b.temBagagemDeMao())
            cout << p.getNome() << " tem direito a levar bagagem de mão" << endl;
        else
            cout << p.getNome() << " não tem direito a levar bagagem de mão" << endl;
        cout << endl;
    }
}

bool CompanhiaAerea::adquirirBilhete(const Passageiro& p, Voo& v, bool bagagem) {
    //arranjar forma de gararantir q o avião não está cheio
    Bilhete b(v, bagagem, p);
    bilhetesVendidos.push_back(b);
    v.addPassageiro(p);
    sort(bilhetesVendidos.begin(), bilhetesVendidos.end());
    return true;
}