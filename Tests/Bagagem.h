#ifndef _BAGAGEM_H
#define _BAGAGEM_H

class Bagagem {
private:
    float peso;
    bool bagaemDeMao;
    bool checkInAutomatico;

public:
    Bagagem();
    Bagagem(float p, bool bagagem);
    float getPeso() const;
    bool isBagaemDeMao() const;
    bool isCheckInAutomatico() const;
};

#endif //_BAGAGEM_H
