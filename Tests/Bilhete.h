#ifndef _BILHETE_H
#define _BILHETE_H

#include "Voo.h"

class Bilhete {
private:
    Voo voo;
    bool bagagemDeMao;
public:
    Bilhete(Voo v, bool bagagem);
    Voo getVoo() const;
    bool temBagagemDeMao() const;
};

#endif //_BILHETE_H
