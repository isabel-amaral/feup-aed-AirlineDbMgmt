#include "CompanhiaAerea.h"
#include <iostream>
#include <algorithm>

CompanhiaAerea::CompanhiaAerea() {
    bilhetesVendidos = vector<Bilhete>();
}

vector<Bilhete> CompanhiaAerea::getBilhetesVendidos() const {
    return bilhetesVendidos;
}

vector<Bilhete> CompanhiaAerea::getBilhetesFromPassageiro(const Passageiro& p) const {
    vector<Bilhete> bilhetes;
    for (int i = 0; i < bilhetesVendidos.size(); i++) {
        if (bilhetesVendidos[i].getPasssageiro().getNome() == p.getNome()) {
            bilhetes.push_back(bilhetesVendidos[i]);
            if (i < bilhetesVendidos.size()-1 && bilhetesVendidos[i+1].getPasssageiro().getNome() != p.getNome())
                break;  //vetor encontra-se ordenado por ordem alfabética do nome dos passageiros
        }
    }
    return bilhetes;
}
//TODO: operador << na classe Bilhete
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

vector<Passageiro> CompanhiaAerea::getPassageirosFromVoo(const Voo &v) const {
    vector<Passageiro> passageiros;
    for (Bilhete b: bilhetesVendidos) {
        if (b.getVoo().getNumeroVoo() == v.getNumeroVoo())
            passageiros.push_back(b.getPasssageiro());
    }
    return passageiros;
}

//TODO: método mostrarPassageirosFromVoo, operador << na classe Passageiro

bool CompanhiaAerea::adquirirBilhete(const Passageiro& p, Voo& v, bool bagagem) {
    if (!v.addPassageiro(p))
        return false;
    Bilhete b(p, v, bagagem);
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
        Bilhete b(*it, v, bagagem);
        bilhetesVendidos.push_back(b);
    }
    sort(bilhetesVendidos.begin(), bilhetesVendidos.end());
    return true;;
}

void CompanhiaAerea::realizarCheckIn(const Passageiro &p, Voo &v) {
    //acrescentar restrições de peso, o que acontece se o passageiro tiver bagagem de mão e o seu bilhete não permitir?
    Bilhete bilhete;
    vector<Bilhete> bilhetes = getBilhetesFromPassageiro(p);
    for (Bilhete b: bilhetes) {
        if (b.getVoo().getNumeroVoo() == v.getNumeroVoo()) {
            bilhete = b;
            break;
        }
    }

    list<Bagagem*>::iterator it;
    for (it = bilhete.getBagagem().begin(); it != bilhete.getBagagem().end(); it++) {
        if (!(*it)->isBagagemDeMao() && (*it)->isCheckInAutomatico())
            v.getTransportador().adicionarAoTapete(*it);
    }
    v.realizarCheckIn(p);
}