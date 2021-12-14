
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
     * Conjunto de horas de disponibilidade nao repetidas
     */
    vector<float> horas;
public:
    Horario();
    Horario(const DiaDaSemana &dia);
    /**
     * @return o dia da semana
     */
    DiaDaSemana getDia() const;
    /**
     * @return o vetor de horas
     */
    vector<float> getHoras() const;
    /**
     * acrescenta um novo elemento às horas, caso este ainda não exista no vetor
     * @param hora é a hora a ser adicionada
     */
    void addHora(float &hora);
    /**
     * modifica/define o dia da semana
     * @param dia é o dia que será atribuido ao Horario
     */
    void setDia (const DiaDaSemana &d);

    bool operator <(const Horario &h2) const;   //Milena: Ha alguma documentacao a escrever em relacao a esta funcao?
};


#endif //AIRLINEDATABASEMANAGEMENT_HORARIO_H
