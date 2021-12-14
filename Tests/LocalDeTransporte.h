#ifndef AIRLINEDATABASEMANAGEMENT_LOCALDETRANSPORTE_H
#define AIRLINEDATABASEMANAGEMENT_LOCALDETRANSPORTE_H
#include <string>
#include <list>
#include <sstream>
#include "Horario.h"

using namespace std;

enum tipoTransporte{ Metro, Comboio, Autocarro};
class LocalDeTransporte {
private:
    /**
     * Distância do local de transporte até ao aeroporto a que está associado
     */
    float distancia;
    /**
     * Tipo de transporte que cricula pelo local
     */
    tipoTransporte tipo;
    /**
     * Dia e horas pelos quais o veículo passa pelo local
     */
    list<Horario> horarios;
public:
    LocalDeTransporte();
    LocalDeTransporte(const float distancia);
    /**
     * Altera a distância entre o local e o aeroporto a que está associado
     * @param distancia é a nova distância a ser atribuída
     */
    void setDistancia(const float &distancia);
    /**
     * Modifica o tipo de transporte terrestre
     * @param tipo é o tipo de transporte que circula pelo local
     */
    void setTipo(const tipoTransporte &tipo);

    /**
     * Adiciona um novo horário a lista horários
     * @param h é o horário
     */
    void addHorario(const Horario &h);
    /**
     * @return distância entre o local e o aeroporto
     */
    float getDistancia() const;
    /**
     * @return tipo de transporte terrestre (metro, autocarro ou comboio)
     */
    tipoTransporte getTipo() const;
    /**
     * @return horários do local
     */
    list<Horario> getHorarios() const;
    /**
     * @return número de vezes que o meio de transporte passa pelo local
     */
    int disponibilidade() const;

    //Milena: Há alguma coisa a dizer sobre estas duas?
    bool operator < (const LocalDeTransporte& l2) const;
    friend ostream& operator<<(ostream& os, const LocalDeTransporte& lp);
};


#endif //AIRLINEDATABASEMANAGEMENT_LOCALDETRANSPORTE_H
