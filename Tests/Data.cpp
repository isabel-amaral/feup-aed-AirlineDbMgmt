#include "Data.h"
#include <sstream>
using namespace std;

Data::Data(unsigned int d, unsigned int m, unsigned int a) {
    this->dia = d;
    this->mes = m;
    this->ano = a;

    ostringstream out;
    out << d << "-" << m << "-" << a;
    data = out.str();
}

unsigned Data::getDia() const {
    return dia;
}

unsigned Data::getMes() const {
    return mes;
}

unsigned Data::getAno() const {
    return ano;
}

void Data::setDia(unsigned d) {
    this->dia = d;
}

void Data::setMes(unsigned m) {
    this->mes = m;
}

void Data::setAno(unsigned a) {
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