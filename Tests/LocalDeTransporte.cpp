#include "LocalDeTransporte.h"

LocalDeTransporte::LocalDeTransporte() {
    this->distancia=0.0;
}

LocalDeTransporte::LocalDeTransporte(const float distancia) {
    this->distancia=distancia;
}

void LocalDeTransporte::setDistancia(const float &d) {
    this->distancia=d;
}

void LocalDeTransporte::setTipo(const tipoTransporte &t) {
    this->tipo=t;
}

bool LocalDeTransporte::addHorario(const Horario &h) {
    if (horarios.size()==3) return false;
    if (!horarios.empty())
    {
        horarios.push_back(h);
        return true;
    }
    /*
    for (auto i=horarios.begin(); i!=horarios.end(); i++){
        //if
    }*/
    this->horarios.push_back(h);
    horarios.sort();
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

int LocalDeTransporte::getDisponibilidade() const {
    int count=0;
    for (auto i=horarios.begin(); i!=horarios.end(); i++){
        count+=i->getHoras().size();
    }
    return count;
}

bool LocalDeTransporte::operator<(const LocalDeTransporte* l2) const {
    if (this->distancia != l2->distancia)
        return this->distancia < l2->distancia;
    else if (this->getDisponibilidade() != l2->getDisponibilidade())
        return this->getDisponibilidade() > l2->getDisponibilidade();
    return (this->tipo < l2->tipo);

}

ostream &operator<<(ostream &os, const LocalDeTransporte &lp) {
    os << "Tipo: "<< lp.getTipo();
    os << "Distancia do aeroporto: "<<lp.getDistancia();
    os << "Horários: ";

     for (auto h:lp.getHorarios()){
         if(h.getDia()==DiasUteis)
             os << "Dias Uteis: ";
         else if (h.getDia() == DomingosFeriados)
             os << "Domingos e Feriados: ";
         else
             os << "Sábados: ";

         for (auto hora: h.getHoras()){
             os<<hora;
         }
     }
    return os;
}




