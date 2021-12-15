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
    void addHora(float& hora);
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
     * @param hora é o elemento a ser pesquisado no vetor horas
     * @return
     */
    unsigned BinarySearchHora(const float& hora) const;
    bool operator< (const Horario& h) const;   //Milena: Ha alguma documentacao a escrever em relacao a esta funcao? isabel: é melhor descrever o critério de ordenação
    //bool operator== (const Horario& h) const;
};


#endif //AIRLINEDATABASEMANAGEMENT_HORARIO_H
