#include "Data.h"
#include <sstream>
using namespace std;

Data::Data() {
    this->dia = 0;
    this->mes = 0;
    this->ano = 0;
    this->data = "";
}

Data::Data(unsigned int d, unsigned int m, unsigned int a) {
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

bool Data::operator < (const Data &d2) const{
    if (ano == d2.ano) {
        if (mes == d2.mes) {
            return dia < d2.dia;
        }
        return mes < d2.mes;
    }
    return ano < d2.ano;
}