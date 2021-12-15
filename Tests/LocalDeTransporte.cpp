#include "LocalDeTransporte.h"

LocalDeTransporte::LocalDeTransporte() {
    this->distancia=0.0;
}

LocalDeTransporte::LocalDeTransporte(float d, tipoTransporte t, const list<Horario> &h) {
    this->distancia = d;
    this->tipo = t;
    this->horarios = h;
}

float LocalDeTransporte::getDistancia() const {
    return distancia;
}

tipoTransporte LocalDeTransporte::getTipo() const {
    return tipo;
}

const list<Horario>& LocalDeTransporte::getHorarios() const {
    return horarios;
}

unsigned LocalDeTransporte::getDisponibilidade() const {
    int count=0;
    for (auto i=horarios.begin(); i!=horarios.end(); i++){
        count += i->getHoras().size();
    }
    return count;
}

void LocalDeTransporte::setDistancia(float d) {
    this->distancia = d;
}

void LocalDeTransporte::setTipo(const tipoTransporte& t) {
    this->tipo = t;
}

void LocalDeTransporte::updateHorario(const Horario& horario) {
    if (horarios.empty()) {
        horarios.push_back(horario);
        return;
    }

    list<Horario>::iterator it;
    for (it = horarios.begin(); it != horarios.end(); it++) {
        if (it->getDia() == horario.getDia()) {
            it->clearHoras();
            it->setHoras(horario.getHoras());
            return;
        }
    }
    this->horarios.push_back(horario);
    horarios.sort();
}

bool LocalDeTransporte::operator< (const LocalDeTransporte& local) const {
    if (this->distancia != local.distancia)
        return this->distancia < local.distancia;
    if (this->getDisponibilidade() != local.getDisponibilidade())
        return this->getDisponibilidade() > local.getDisponibilidade();
    return (this->tipo < local.tipo);
}

ostream& operator<< (ostream &os, const LocalDeTransporte &local) {
    os << "Tipo: "<< local.getTipo();
    os << "Distancia do aeroporto: " << local.getDistancia();
    os << "Horários: ";

    for (auto h: local.getHorarios()){
        if(h.getDia()==DiasUteis)
            os << "Dias Uteis: ";
        else if (h.getDia() == DomingosFeriados)
            os << "Domingos e Feriados: ";
        else
            os << "Sábados: ";

        for (auto hora: h.getHoras()){
            os << hora;
        }
    }
    return os;
}




