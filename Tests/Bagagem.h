#ifndef _BAGAGEM_H
#define _BAGAGEM_H

class Bagagem {
private:
    float peso;
    bool bagagemDeMao;
    bool checkInAutomatico;

public:
    Bagagem();
    Bagagem(float p, bool bagagem);
    float getPeso() const;
    bool isBagagemDeMao() const;
    bool isCheckInAutomatico() const;
};

#endif //_BAGAGEM_H
