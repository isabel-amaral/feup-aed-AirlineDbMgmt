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

vector<float> Horario::getHoras() const {
    return horas;
}

void Horario::addHora(float &hora) {
    if (horas.empty()) horas.push_back(hora);

    int index= BinarySearchHora(hora);

    if (horas.at(index) == hora) return;
    else if (horas.at(index)<hora){
        horas.insert(horas.begin()+index+1,hora);
    }
    else{
        horas.insert(horas.begin()+index,hora);
    }
}

void Horario::setDia(const DiaDaSemana &d) {
    this->dia=d;
}

void Horario::clearHoras() {
    this->horas.clear();
}

int Horario:: BinarySearchHora(const float &hora) const {
    int left = 0;
    int right = horas.size() - 1;
    int middle;

    while (left <= right) {
        middle = (left + right) / 2;
        if (horas.at(middle) < hora)
            left = middle + 1;
        else if (hora < horas.at(middle))
            right = middle - 1;
        else
            return middle;
    }
    return middle;
}

bool Horario::operator<(const Horario &h2) const {
    return this->dia < h2.dia;
}

bool Horario::operator==(const Horario &h2) const {
    return this->dia==h2.dia;
}








