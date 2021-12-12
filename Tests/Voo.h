#ifndef _VOO_H
#define _VOO_H

#include "Aeroporto.h"
#include "Aviao.h"
#include <string>
using namespace std;

class Voo {
private:
    /**
     * número que identifica o voo
     */
    unsigned int numeroVoo;
    /**
 * aeroporto de onde parte o voo
 */
    Aeroporto origem;
    /**
     * aeroporto aonde acaba o voo
     */
    Aeroporto destino;
    /**
     * horário de partida na cidade do aeroporto de origem do voo
     */
    float horaPartida;
    /**
     * horário de chegada na cidade do aeroporto de destino do voo
     */
    float horaChegada;
    /**
     * duração do voo em horas e minutos
     */
    float duracao; // sofia: string?; isabel: mudei tudo o q era horas para float (igual àquele ex das plataformas dos comboios)
    /**
     * aviao onde será realizado o voo
     */
    Aviao aviao;
    /**
     * número de lugares reservados(ocupados) no avião onde será realizado o voo
     */
    unsigned int numLugaresReservados;

public:
    Voo();
    Voo(unsigned int n, Aeroporto& ao, Aeroporto& ad, float hp, float hc, float d, Aviao& a, unsigned int nlr);
    Voo(const Voo& v);
    /**
    *
    * @return número do voo
    */
    int getNum() const;
    /**
    *
    * @return origem do voo
    */
    Aeroporto getOrigem() const;
    /**
    *
    * @return hora de partida do voo
    */
    float getHoraPartida() const;
    /**
    *
    * @return destino do voo
    */
    Aeroporto getDestino() const;
    /**
    *
    * @return hora de chegada do voo
    */
    float getHoraChegada() const;
    /**
    *
    * @return duração do voo
    */
    float getDuracao() const;
    /**
    *
    * @return aviao onde será feito voo
    */
    Aviao getAviao() const;
    /**
     *
     * @return numero de lugares reservados(ocupados) no avião
     */
    unsigned int getNumLugaresReservados() const;
    /**
    * atribui um número ao voo
    * @param n é o número do voo
    */
    void setNum(const unsigned int& n);
    /**
    * modifica a origem do voo
    * @param ao é a origem do voo
    */
    void setOrigem(const Aeroporto& ao);
    /**
    * modifica a hora de partida do voo
    * @param p é a partida do voo
    */
    void setHoraPartida(const float p);
    /**
    * modifica o destino do voo
    * @param ad é a destino do voo
    */
    void setDestino(const Aeroporto& ad);
    /**
    * modifica a hora de chegada do voo
    * @param c é a chegada do voo
    */
    void setHoraChegada(const float c);
    /**
    * modifica a duração do voo
    * @param d é a origem do voo
    */
    void setDuracao(const float d);
    /**
    * define o avião onde será feito o voo
    * @param a é o avião
    */
    void setAviao(const Aviao& a);
    /**
    * modifica o  número de lugares reservados(ocupados) no avião
    * @param lr é o número de lugares ocupados
    */
    void setNumLugaresReservados(const unsigned int& lr);
};

#endif //_VOO_H