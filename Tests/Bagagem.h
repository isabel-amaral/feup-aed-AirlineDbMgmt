#ifndef _BAGAGEM_H
#define _BAGAGEM_H

class Bagagem {
private:
    /**
     * Peso da bagagem.
     */
    float peso;
    /**
     * Se a bagagem é ou não de mão.
     */
    bool bagagemDeMao;
    /**
     * true se o passageiro pretender que o check-in da sua bagagem seja feito de forma automática, false caso contrário
     */
    bool checkInAutomatico;

public:
    Bagagem();
    Bagagem(float p, bool bagagemMao, bool checkIn);
    /**
     * @return peso da mala.
     */
    float getPeso() const;
    /**
     *
     * @return true se a bagagem for de mão, caso contrário false.
     */
    bool isBagagemDeMao() const;
    /**
     *
     * @return true se o check-in foi feito automaticamente, caso contrário false.
     */
    bool isCheckInAutomatico() const;
};

#endif //_BAGAGEM_H
