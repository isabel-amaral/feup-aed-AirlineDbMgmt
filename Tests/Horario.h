#ifndef AIRLINEDATABASEMANAGEMENT_HORARIO_H
#define AIRLINEDATABASEMANAGEMENT_HORARIO_H

#include <string>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

enum DiaDaSemana { DiasUteis, Sabados, DomingosFeriados};

class Horario {
private:
    /**
     * Dia da semana
     */
    DiaDaSemana dia;
    /**
     * Conjunto de horas não repetidas
     */
    vector<float> horas;
public:
    Horario();
    Horario(const DiaDaSemana& dia, const vector<float>& horas = vector<float>());
    /**
     * @return o dia da semana
     */
    DiaDaSemana getDia() const;
    /**
     * @return o vetor de horas
     */
    vector<float> getHoras() const;
    /**
     * Acrescenta um novo elemento às horas, caso este ainda não exista no vetor
     * @param hora é o elemento a ser adicionado
     */
    void addHora(const float& hora);
    /**
     * Modifica/define o dia da semana
     * @param dia é o dia que será atribuido ao objeto
     */
    void setDia(const DiaDaSemana& d);
    /**
     * Modifica/define o conjunto de horas não repetidas
     * @param h são as horas
     */
    void setHoras(const vector<float>& h);
    /**
     * Remove todos os elementos do atributo horas
     */
    void clearHoras();
    /**
     *
     * @param hora é o elemento a ser pesquisado no vetor horas usando pesquisa binária.
     * @return Posição da hora no vetor caso seja seja encontrado, caso contrário retorna.
     * O índice do maior elemento menor que @param hora ou o menor elemento maior que @param hora.
     */
    unsigned BinarySearchHora(const float& hora) const;
    /**
     * Este horário é menor que outro horário(h) se o seu dia for menor que o dia de h.
     * Sendo que os dias seguem a ordenação DiasUteis< Sabados< Domingos .
     * @param h é o objeto a ser comparado com o este horário.
     * @return true se esta instância é menor que h, caso contrário false.
     */
    bool operator< (const Horario& h) const;
};


#endif //AIRLINEDATABASEMANAGEMENT_HORARIO_H
