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
    Data(unsigned int d, unsigned int m, unsigned a);
    /**
     *
     * @return o dia
     */
    unsigned getDia() const;
    /**
     *
     * @return o mês
     */
    unsigned getMes() const;
    /**
     *
     * @return o ano
     */
    unsigned getAno() const;
    /**
     *
     * @return o objeto em forma de texto e escrito no formato DD-MM-AAAA
     */
    string getData() const;
    /**
     * Altera o dia
     * @param d é o novo dia
     */
    void setDia(unsigned d);
    /**
     * Modifica o mês
     * @param m é o novo mês
     */
    void setMes(unsigned m);
    /**
     * Altera o ano
     * @param a é o novo ano
     */
    void setAno(unsigned a);

    bool operator< (const Data &d) const;
    bool operator== (const Data& d) const;
};

#endif //_DATA_H
