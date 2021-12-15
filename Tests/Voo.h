#ifndef _VOO_H
#define _VOO_H

#include "Aeroporto.h"
#include "Passageiro.h"
#include "TransportadorDeBagagem.h"
#include "Voo.h"
#include "Data.h"
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
     * dia de partida do voo;
     */
    Data dataPartida;
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
    float duracao;
    unsigned lotacao;
    /**
     * número de lugares reservados(ocupados) no avião onde será realizado o voo
     */
    unsigned numLugaresReservados;
    list<Passageiro> passageiros;
    list<Passageiro> passageirosCheckedIn;
    TransportadorDeBagagem transportador;

public:
    Voo();
    Voo(unsigned n, const Aeroporto& ao, const Aeroporto& ad, const Data& dp, float hp, float hc, float d, unsigned l, unsigned nlr);
    //Voo(const Voo& v);
    /**
    *
    * @return número do voo
    */
    unsigned getNumeroVoo() const;
    /**
    *
    * @return origem do voo
    */
    Aeroporto getOrigem() const;
    /**
     *
     * @return data de partida do voo
     */
    Data getDataPartida() const;
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
    unsigned int getLotacao() const;
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
    void setDataPartida(const Data& dp);
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
     * Altera a lotação do Voo
     * @param lotacao é a nova lotação
     */
    void setLotacao(unsigned int lotacao);
    /**
    * modifica o  número de lugares reservados(ocupados) no avião
    * @param lr é o número de lugares ocupados
    */
    void setNumLugaresReservados(unsigned lr);
    void setTransportador(unsigned c, unsigned n, unsigned m);
    bool addPassageiro(const Passageiro& p);
    bool addConjuntoPassageiros(const list<Passageiro>& p);
    void realizarCheckIn(const Passageiro& p);
};

#endif //_VOO_H