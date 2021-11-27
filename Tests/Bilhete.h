#ifndef _BILHETE_H
#define _BILHETE_H

#include "Voo.h"

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
public:
    Bilhete(Voo v, bool bagagem);
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
};

#endif //_BILHETE_H
