#ifndef _DATA_H
#define _DATA_H

#include <string>
using namespace std;

class Data {
private:
    /**
     * Número que indica o dia e que se encontra no intervalo de 1-31
     */
    unsigned dia;
    /**
     * Número que indica o mês e que se encontra no intervalo de 1-12
     */
    unsigned mes;
    /**
     * Número que indica o ano
     */
    unsigned ano;
    /**
     * Data escrita no formato DD-MM-AAAA (dia-mes-ano)
     */
    string data;
    void getStringRepresentation();
public:
    Data();
    Data(unsigned d, unsigned m, unsigned a);
    /**
     *
     * @return O dia.
     */
    unsigned getDia() const;
    /**
     *
     * @return O mês.
     */
    unsigned getMes() const;
    /**
     *
     * @return O ano.
     */
    unsigned getAno() const;
    /**
     *
     * @return o objeto em forma de texto e escrito no formato DD-MM-AAAA.
     */
    string getData() const;
    /**
     * Altera o dia.
     * @param d é o novo dia.
     */
    void setDia(unsigned d);
    /**
     * Modifica o mês.
     * @param m é o novo mês.
     */
    void setMes(unsigned m);
    /**
     * Altera o ano.
     * @param a é o novo ano.
     */
    void setAno(unsigned a);

    /**
     * Uma data é tanto menor quanto menor é o seu ano.
     * Em caso de empate, é tanto menor quanto menor é o seu mês.
     * Em caso de empate, é tanto menor quanto menor é o seu dia.
     * @param d é a data a ser comparada com está instância.
     * @return true se esta instância é menor que @param d caso contrário false.
     */
    bool operator< (const Data &d) const;
    /**
     * Duas datas são iguais se todos os seus atributos são iguais.
     * @param d é a data a ser comparada com esta instância.
     * @return true se esta instância é igual à @param d caso contrário false.
     */
    bool operator == (const Data& d) const;
    //TODO: DOCUMENTACAO
    bool operator <= (const Data& d) const;
};

#endif //_DATA_H
