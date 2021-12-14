#include "Data.h"
using namespace std;

int Data::getDia() const {
    return dia;
}

int Data::getMes() const {
    return mes;
}

int Data::getAno() const {
    return ano;
}

void Data::setDia(const int &d) {
    this->dia = d;
}

void Data::setMes(const int &m) {
    this->mes = m;
}

void Data::setAno(const int &a) {
    this->ano = a;
}

bool Data::operator < (const Data &d2) const{
    if (ano == d2.ano) {
        if (mes == d2.mes) {
            return dia < d2.dia;
        }
        return mes < d2.mes;
    }
    return ano < d2.ano;
}