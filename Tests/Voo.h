#ifndef _VOO_H
#define _VOO_H

#include "Aviao.h"
#include "Aeroporto.h"
#include "Passageiro.h"
#include <string>
using namespace std;

class Voo {
private:
    /**
     * número que identifica o voo
     */
    unsigned numeroVoo;
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
    unsigned numLugaresReservados;
    list<Passageiro> passageiros;

public:
    Voo();
    Voo(unsigned n, const Aeroporto& ao, const Aeroporto& ad, float hp, float hc, float d, const Aviao& a, unsigned nlr);
    Voo(const Voo& v);
    /**
    *
    * @return número do voo
    */
    unsigned getNumeroVoo() const;
    /**
    *
    * @return origem do voo
    */
    const Aeroporto& getOrigem() const;
    /**
    *
    * @return hora de partida do voo
    */
    float getHoraPartida() const;
    /**
    *
    * @return destino do voo
    */
    const Aeroporto& getDestino() const;
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
    const Aviao& getAviao() const;
    /**
     *
     * @return numero de lugares reservados(ocupados) no avião
     */
    unsigned getNumLugaresReservados() const;
    const list<Passageiro>& getPassageiros() const;
    /**
    * atribui um número ao voo
    * @param n é o número do voo
    */
    void setNumeroVoo(unsigned n);
    /**
    * modifica a origem do voo
    * @param ao é a origem do voo
    */
    void setOrigem(const Aeroporto& ao);
    /**
    * modifica a hora de partida do voo
    * @param p é a partida do voo
    */
    void setHoraPartida(float p);
    /**
    * modifica o destino do voo
    * @param ad é a destino do voo
    */
    void setDestino(const Aeroporto& ad);
    /**
    * modifica a hora de chegada do voo
    * @param c é a chegada do voo
    */
    void setHoraChegada(float c);
    /**
    * modifica a duração do voo
    * @param d é a origem do voo
    */
    void setDuracao(float d);
    /**
    * define o avião onde será feito o voo
    * @param a é o avião
    */
    void setAviao(const Aviao& a);
    /**
    * modifica o  número de lugares reservados(ocupados) no avião
    * @param lr é o número de lugares ocupados
    */
    void setNumLugaresReservados(unsigned lr);
    bool addPassageiro(const Passageiro& p);
};

#endif //_VOO_H