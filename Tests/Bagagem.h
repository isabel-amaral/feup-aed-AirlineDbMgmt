#ifndef _BAGAGEM_H
#define _BAGAGEM_H

class Bagagem {
private:
    /**
     * peso da bagagem
     */
    float peso;
    /**
     * Se a bagagem é ou não de mão
     */
    bool bagagemDeMao;
    /**
     * Se o checkIn será feito de forma automática
     */
    bool checkInAutomatico;

public:
    Bagagem();
    Bagagem(float p, bool bagagem);
    /**
     * @return peso da mala
     */
    float getPeso() const;
    /**
     *
     * @return true se a bagagem for de mão, caso contrário false
     */
    bool isBagagemDeMao() const;
    /**
     *
     * @return true se o check in foi feito automaticamente, caso contrário false
     */
    bool isCheckInAutomatico() const;
};

#endif //_BAGAGEM_H
