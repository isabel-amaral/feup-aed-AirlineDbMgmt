#include <iomanip>
#include "LocalDeTransporte.h"

LocalDeTransporte::LocalDeTransporte() {
    this->distancia=0.0;
}

LocalDeTransporte::LocalDeTransporte(unsigned id, float d, tipoTransporte t, const list<Horario> &h) {
    this->idLocal = id;
    this->distancia = d;
    this->tipo = t;
    this->horarios = h;
}

unsigned LocalDeTransporte::getIdLocal() const {
    return idLocal;
}

float LocalDeTransporte::getDistancia() const {
    return distancia;
}

tipoTransporte LocalDeTransporte::getTipo() const {
    return tipo;
}

list<Horario> LocalDeTransporte::getHorarios() const {
    return horarios;
}

unsigned LocalDeTransporte::getDisponibilidade() const {
    int count=0;
    for (const auto & horario : horarios){
        count += horario.getHoras().size();
    }
    return count;
}

void LocalDeTransporte::setIdLocal(unsigned int id) {
    this->idLocal = id;
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
    os << "TIPO: ";
    if (local.getTipo() == Metro)
        os << "Metro" << endl;
    else if (local.getTipo() == Comboio)
        os << "Comboio" << endl;
    else
        os << "Autocarro" << endl;

    os << "DISTÂNCIA AO AEROPORTO: " << local.getDistancia() << " metros" << endl;
    os << "HORÁRIOS: " << endl;

    for (const auto& h: local.getHorarios()){
        if(h.getDia()==DiasUteis)
            os << "Dias Uteis: ";
        else if (h.getDia() == DomingosFeriados)
            os << "Domingos e Feriados: ";
        else
            os << "Sábados: " ;

        for (auto hora: h.getHoras()){
            os << fixed << setprecision(2) << hora << "  ";
        }
        os << endl;
    }
    return os;
}







