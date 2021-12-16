#ifndef _BILHETE_H
#define _BILHETE_H

#include "Voo.h"
#include "Passageiro.h"

class Bilhete {
private:
    /**
     * Voo para o qual o bilhete foi aquirido.
     */
    Voo voo;
    /**
     * Se o passageiro que adquiriu o bilhete tem direito a levar bagagem de mão ou não.
     */
    bool bagagemDeMao;
    /**
     * Passageiro a quem pertence o bilhete.
     */
    Passageiro passageiro;

public:
    Bilhete();
    Bilhete(const Voo& v, bool bagagem, const Passageiro& p);
    /**
     *
     * @return voo para o qual o bilhete foi adquirido.
     */
    Voo getVoo() const;
    /**
     *
     * @return true se o passageiro tem direito a levar bagagem de mão, caso contrário false.
     */
    bool temBagagemDeMao() const;
    /**
     *
     * @return passageiro a quem pertence o bilhete.
     */
    Passageiro getPasssageiro() const;
    /**
     * Modifica o atributo bagagem de mão.
     * @param bagagem é o novo valor booleano que o atributo bagagemDeMao terá.
     */
    void setBagagemDeMao(bool bagagem);
    /**
     * Indica o passageiro que comprou o bilhete.
     * @param p é o passageiro a quem pertence o bilhete.
     */
    void setPassageiro(const Passageiro& p);
    //TODO
    bool operator< (const Bilhete& b);
};

#endif //_BILHETE_H
