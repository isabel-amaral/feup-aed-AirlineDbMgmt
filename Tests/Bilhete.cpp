#include "Bilhete.h"

Bilhete::Bilhete(Voo v, bool bagagem) {
    voo = v;
    bagagemDeMao = bagagem;
}

Voo Bilhete::getVoo() const {
    return voo;
}

bool Bilhete::temBagagemDeMao() const {
    return bagagemDeMao;
}
