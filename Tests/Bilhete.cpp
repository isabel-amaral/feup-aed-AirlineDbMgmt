#include "Bilhete.h"

Bilhete::Bilhete(Voo v, bool bagagem) {
    this->voo = v;
    this->bagagemDeMao = bagagem;
}

Voo Bilhete::getVoo() const {
    return this->voo;
}

bool Bilhete::temBagagemDeMao() const {
    return this->bagagemDeMao;
}
