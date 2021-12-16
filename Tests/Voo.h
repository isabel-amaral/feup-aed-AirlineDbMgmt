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
     * Número que identifica o voo.
     */
    unsigned numeroVoo;
    /**
     * Aeroporto de onde parte o voo.
     */
    Aeroporto origem;
    /**
     * Aeroporto aonde acaba o voo.
     */
    Aeroporto destino;
    /**
     * Dia de partida do voo.
     */
    Data dataPartida;
    /**
     * Horário de partida na cidade do aeroporto de origem do voo.
     */
    float horaPartida;
    /**
     * Horário de chegada na cidade do aeroporto de destino do voo.
     */
    float horaChegada;
    /**
     * duração do voo em horas e minutos.
     */
    float duracao;
    //TODO
    unsigned lotacao;
    /**
     * número de lugares reservados(ocupados) no avião onde será realizado o voo.
     */
    unsigned numLugaresReservados;
    /**
     * Todos os passageiros que adiquiriram bilhetes para este voo.
     */
    list<Passageiro> passageiros;
    /**
     * Passageiros com check-in feito.
     */
    list<Passageiro> passageirosCheckedIn;
    /**
     * Carrinho que transporta as malas dos passageiros do voo.
     */
    TransportadorDeBagagem transportador;

public:
    Voo();
    Voo(unsigned n, const Aeroporto& ao, const Aeroporto& ad, const Data& dp, float hp, float hc, float d, unsigned l, unsigned nlr);
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
     * @return numero de lugares reservados(ocupados) no avião.
     */
    unsigned getNumLugaresReservados() const;
    const list<Passageiro>& getPassageiros() const;
    /**
    * atribui um número ao voo.
    * @param n é o número do voo.
    */
    void setNumeroVoo(unsigned n);
    /**
    * Modifica a origem do voo.
    * @param ao é a origem do voo.
    */
    void setOrigem(const Aeroporto& ao);
    /**
     * Define a data de partida do voo.
     * @param dp é a data de partida do voo.
     */
    void setDataPartida(const Data& dp);
    /**
    *
     * Altera a hora de partida do voo.
    * @param p é a partida do voo.
    */
    void setHoraPartida(float p);
    /**
    * Modifica o destino do voo.
    * @param ad é a destino do voo.
    */
    void setDestino(const Aeroporto& ad);
    /**
    * modifica a hora de chegada do voo.
    * @param c é a chegada do voo.
    */
    void setHoraChegada(float c);
    /**
    * modifica a duração do voo.
    * @param d é a origem do voo.
    */
    void setDuracao(float d);
    /**
     * Altera a lotação do Voo.
     * @param lotacao é a nova lotação.
     */
    void setLotacao(unsigned int lotacao);
    /**
    * modifica o  número de lugares reservados(ocupados) no avião.
    * @param lr é o número de lugares ocupados.
    */
    void setNumLugaresReservados(unsigned lr);
    /**
     * Define as dimensões do carrinho de transporte de malas.
     * @param c é o número de carruagens.
     * @param n é o número de pilhas que cada carruagem tem.
     * @param m é o número máximo de malas que cada pilha pode conte.
     */
    void setTransportador(unsigned c, unsigned n, unsigned m);
    /**
     * Adiciona um novo passageiro ao vetor passageiros se o voo não se encontra lotado.
     * @param p é o novo passageiro que pretende viajar.
     * @return true se passageiro poderá viajar, caso contrário false.
     */
    bool addPassageiro(const Passageiro& p);
    /**
     * Se os lugares vagos são suficientes para o número de passageiros que pretende viajar,
     * estes são adicicionados ao vector de passageiros do voo.
     * @param p contém os passageiros que pretendem viajar em conjunto.
     * @return  true se o grupo de passageiros poderá viajar, caso contrário false.
     */
    bool addConjuntoPassageiros(const list<Passageiro>& p);
    /**
     * Realiza o check-in de um passageiro: coloca as suas bagagens no tapete rolante e de seguida.
     * adiciona o passageiro à lista de passageiros com o check-in feito.
     * @param p é o passageiro que pretende realizar o seu check-in.
     */
    void realizarCheckIn(const Passageiro& p);
};

#endif //_VOO_H