#ifndef _BILHETE_H
#define _BILHETE_H

#include "Voo.h"
#include "Passageiro.h"

class Bilhete {
private:
    /**
     * voo para o qual o bilhete foi aquirido
     */
    Voo voo;
    /**
     * se o passageiro que adquiriu o bilhete tem direito a levar bagagem de mão
     */
    bool bagagemDeMao;
    Passageiro passageiro;

public:
    Bilhete();
    Bilhete(const Voo& v, bool bagagem, const Passageiro& p);
    /**
     *
     * @return voo para o qual o bilhete foi adquirido
     */
    Voo getVoo() const;
    /**
     *
     * @return true se o passageiro tem direito a levar bagagem de mão, falso caso contrário
     */
    bool temBagagemDeMao() const;
    Passageiro getPasssageiro() const;
    void setBagagemDeMao(bool bagagem);
    void setPassageiro(const Passageiro& p);
    bool operator< (const Bilhete& b);
};

#endif //_BILHETE_H
