#include "Data.h"
#include <sstream>
using namespace std;

Data::Data() {
    this->dia = 0;
    this->mes = 0;
    this->ano = 0;
    this->data = "";
}

Data::Data(unsigned d, unsigned m, unsigned a) {
    this->dia = d;
    this->mes = m;
    this->ano = a;
    getStringRepresentation();
}

void Data::getStringRepresentation() {
    ostringstream out;
    out << dia << "-" << mes << "-" << ano;
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

string Data::getData() const {
    return data;
}

void Data::setDia(unsigned d) {
    this->dia = d;
    getStringRepresentation();
}

void Data::setMes(unsigned m) {
    this->mes = m;
    getStringRepresentation();
}

void Data::setAno(unsigned a) {
    this->ano = a;
    getStringRepresentation();
}

bool Data::operator < (const Data &d) const {
    if (ano == d.ano) {
        if (mes == d.mes) {
            return dia < d.dia;
        }
        return mes < d.mes;
    }
    return ano < d.ano;
}

bool Data::operator==(const Data &d) const {
    return ano == d.ano && mes == d.mes && dia == d.dia;
}

bool Data::operator<=(const Data &d) const {
    return *this == d || *this < d;
}


