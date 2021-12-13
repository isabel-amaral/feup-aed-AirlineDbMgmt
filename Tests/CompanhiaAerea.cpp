#include "CompanhiaAerea.h"
#include <algorithm>

CompanhiaAerea::CompanhiaAerea() {
    bilhetesVendidos = vector<Bilhete>();
}

const vector<Bilhete>& CompanhiaAerea::getBilhetesVendidos() const {
    return bilhetesVendidos;
}

//TODO
const vector<Bilhete>& CompanhiaAerea::getBilhetesFromPassageiro() const {
    vector<Bilhete> bilhetes;
    return bilhetes;
}

bool CompanhiaAerea::adquiriBilhete(const Passageiro& p, Voo& v, bool bagagem) {
    if (!v.addPassageiro(p))
        return false;
    Bilhete b(v, bagagem, p);
    bilhetesVendidos.push_back(b);
    sort(bilhetesVendidos.begin(), bilhetesVendidos.end());
    return true;
}