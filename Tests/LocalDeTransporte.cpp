#include "LocalDeTransporte.h"

LocalDeTransporte::LocalDeTransporte() {
    this->distancia=0.0;
}

LocalDeTransporte::LocalDeTransporte(const float distancia) {
    this->distancia=distancia;
}

void LocalDeTransporte::setDistancia(const float &distancia) {
    this->distancia=distancia;
}

void LocalDeTransporte::setTipo(const tipoTransporte &tipo) {
    this->tipo=tipo;
}

void LocalDeTransporte::addHorario(const Horario &h) {
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

int LocalDeTransporte::disponibilidade() const {
    int count=0;
    for (auto h:horarios){
        count+=h.getHoras().size();
    }
}

bool LocalDeTransporte::operator<(const LocalDeTransporte &l2) const {
    if (this->distancia != l2.distancia)
        return this->distancia < l2.distancia;
    else if (this->horarios.size() != l2.horarios.size())
        return this->horarios.size() > l2.horarios.size();
    return (this->tipo < l2.tipo);

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




