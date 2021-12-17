
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
     * Distância do local de transporte até ao aeroporto a que está associado.
     */
    float distancia;
    /**
     * Tipo de transporte que cricula pelo local.
     */
    tipoTransporte tipo;
    /**
     * Dia e horas pelos quais o veículo passa pelo local.
     * Este atributo só pode ter, no máximo, 3 elementos e todos eles diferentes entre si, isto é,
     * cada elemento tem o atributo dia (da classe Horario) diferente dos restantes.
     */
    list<Horario> horarios;
public:
    LocalDeTransporte();
    LocalDeTransporte(float d, tipoTransporte t, const list<Horario>& h = list<Horario>());
    /**
     * @return distância entre o local e o aeroporto.
     */
    float getDistancia() const;
    /**
     * @return tipo de transporte terrestre (Metro, Autocarro ou Comboio).
     */
    tipoTransporte getTipo() const;
    /**
     * @return horários do local.
     */
    const list<Horario>& getHorarios() const;
    /**
     * @return número de vezes que o meio de transporte passa pelo local.
     */
    unsigned getDisponibilidade() const;
    /**
     * Altera a distância entre o local e o aeroporto a que está associado.
     * @param d é a nova distância a ser atribuída.
     */
    void setDistancia(float d);
    /**
     * Modifica o tipo de transporte terrestre.
     * @param t é o tipo de transporte que circula pelo local.
     */
    void setTipo(const tipoTransporte &t);
    /**
     * Atualiza a lista de horários. Caso exista, um horario igual a h (com o mesmo dia da semana)
     * a lista de horas deste elemento é alterada: passa a ser igual à do horário h.
     * Caso contrário, o horário h é simplesmente adicionado a lista horarios do local de transporte.
     * @param horario é o novo horário
     */
    void updateHorario(const Horario &horario);

    /**
     * Considera-se que este local de transporte é menor que outro (local) se a sua distância ao aeroporto for menor que a de local. Em caso
     * de empate, compara-se as disponibilidades de cada um: o que tiver maior disponibilidade, será considerado menor. Caso contrário,
     * será menor aquele que tiver o menor tipo. Sendo considerada a seguinte ordem: Metro< Comboio< Autocarro.
     * @param local é o objeto a ser comparado com esta instância
     * @return true se esta instância é menor que @param local, caso contrário false.
     */
    bool operator< (const LocalDeTransporte& local) const;
    //TODO: DOCUMENTACAO
    friend ostream& operator<< (ostream& os, const LocalDeTransporte& local);
};


#endif //AIRLINEDATABASEMANAGEMENT_LOCALDETRANSPORTE_H
