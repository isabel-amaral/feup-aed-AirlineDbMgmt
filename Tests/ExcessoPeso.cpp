#include "ExcessoPeso.h"

ExcessoPeso::ExcessoPeso() {
    pesoMaximo = 0.0;
    taxaPesoExtra = 0.0;
    taxaBagagemDeMao = 0.0;
}

ExcessoPeso::ExcessoPeso(float peso, float tp, float tb) {
    this->pesoMaximo = peso;
    this->taxaPesoExtra = tp;
    this->taxaBagagemDeMao = tb;
}

float ExcessoPeso::getPesoMaximo() const {
    return pesoMaximo;
}

float ExcessoPeso::getTaxaPesoExtra() const {
    return taxaPesoExtra;
}

float ExcessoPeso::getTaxaBagagemDeMao() const {
    return taxaBagagemDeMao;
}

bool ExcessoPeso::excedePeso(const Bagagem* b) const {
    return b->getPeso() > pesoMaximo;
}

float ExcessoPeso::multaExcessoPeso(const Bagagem* b) const {
    return (b->getPeso() - pesoMaximo) * taxaPesoExtra;
}

float ExcessoPeso::multaTaxaBagagemDeMao(const Bagagem* b) const {
    return taxaBagagemDeMao;
}
