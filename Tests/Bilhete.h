#ifndef _BILHETE_H
#define _BILHETE_H

#include "Voo.h"
#include "Passageiro.h"
#include "Bagagem.h"

class Bilhete {
private:
    /**
     * Passageiro a quem pertence o bilhete.
     */
    Passageiro passageiro;
    /**
     * Voo para o qual o bilhete foi aquirido.
     */
    Voo voo;
    /**
     * Se o passageiro que adquiriu o bilhete tem direito a levar bagagem de mão ou não.
     */
    bool bagagemDeMao;
    /**
     * lista com os volumes de bagagem do passageiro para o voo em questão.
     */
    list<Bagagem*> bagagem;

public:
    Bilhete();
    Bilhete(const Passageiro& p, const Voo& v, bool b, const list<Bagagem*>& bagagem = list<Bagagem*>());
    /**
     *
     * @return passageiro a quem pertence o bilhete.
     */
    Passageiro getPasssageiro() const;
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
     * @return lista com os volumes de bagagem do passageiro para o voo em questão.
     */
    list<Bagagem*> getBagagem() const;
    /**
     * Indica o passageiro que comprou o bilhete.
     * @param p é o passageiro a quem pertence o bilhete.
     */
    void setPassageiro(const Passageiro& p);
    /**
     * Modifica o atributo bagagem de mão.
     * @param bagagem é o novo valor booleano que o atributo bagagemDeMao terá.
     */
    void setBagagemDeMao(bool bagagem);
    /**
     * Define as bagagens que o passageiro possui.
     * @param b é a lista das bagagens.
     */
    void setBagagem(const list<Bagagem*>& b);
    //TODO
    bool operator< (const Bilhete& b) const;
};

#endif //_BILHETE_H
