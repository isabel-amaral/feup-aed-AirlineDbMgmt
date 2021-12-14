#include "Horario.h"

Horario::Horario() {
    dia=DomingosFeriados;
}

Horario::Horario(const DiaDaSemana &dia) {
    this->dia=dia;
}

DiaDaSemana Horario::getDia() const{
    return dia;
}

vector<string> Horario::getHoras() const {
    return horas;
}

void Horario::addHora(string &hora) {
    if (find(horas.begin(), horas.end(),hora)==horas.end()){
        horas.push_back(hora);
        sort(horas.begin(), horas.end());
    }
}

void Horario::setDia(const DiaDaSemana &dia) {
    this->dia=dia;
}

/*
void Horario::sortHoras() {
    sort(horas.begin(),horas.end());
}

int Horario:: BinarySearch(const string &hora) const {
    int left = 0, right = horas.size() - 1;

    while (left <= right) {
        int middle = (left + right) / 2;
        if (horas.at(middle) < hora)
            left = middle + 1;
        else if (hora < horas.at(middle))
            right = middle - 1;
        else
            return middle;
    }
    return -1;
}*/

bool Horario::operator<(const Horario &h2) const {
    return this->dia < h2.dia;
}




