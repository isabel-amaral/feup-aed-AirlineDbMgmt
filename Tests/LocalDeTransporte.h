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
     * Dia e horas pelos quais o veículo passa pelo local.
     * Este atributo só pode ter, no máximo, 3 elementos e todos eles diferentes entre si, isto é,
     * cada elemnto tem o atributo dia (da classe Horario) diferente dos restante.
     */
    list<Horario> horarios;
public:
    LocalDeTransporte();
    LocalDeTransporte(const float distancia);
    /**
     * Altera a distância entre o local e o aeroporto a que está associado
     * @param distancia é a nova distância a ser atribuída
     */
    void setDistancia(const float &d);
    /**
     * Modifica o tipo de transporte terrestre
     * @param tipo é o tipo de transporte que circula pelo local
     */
    void setTipo(const tipoTransporte &t);

    /**
     * Atualiza a lista de horários. Caso exista, um horario igual h (com o mesmo dia da semana)
     *
     * ainda não exista um horario igual h (com o mesmo dia da semana),
     * h é simplesmente adicionado a lista, caso
     * @param h é o horário
     * @return (true) casp h seja inserido ou (false) caso contrário.
     */
    bool addHorario(const Horario &h);
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
    int getDisponibilidade() const;

    //Milena: Há alguma coisa a dizer sobre estas duas?

    bool operator < (const LocalDeTransporte* l2) const;
    friend ostream& operator<<(ostream& os, const LocalDeTransporte& lp);
};


#endif //AIRLINEDATABASEMANAGEMENT_LOCALDETRANSPORTE_H
