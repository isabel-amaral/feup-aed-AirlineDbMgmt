#ifndef _BILHETE_H
#define _BILHETE_H

#include "Voo.h"
#include "Passageiro.h"
#include "Bagagem.h"

class Bilhete {
private:
    /**
     * Número de identificação do bilhete.
     */
    unsigned idBilhete;
    /**
     * Atributo que é incrementada de cada vez que um novo bilhete é adicionado à companhia aérea.
     * Representa o número de bilhetes comprados até ao momento.
     */
    static unsigned idCount;
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
    Bilhete(unsigned id, const Passageiro& p, const Voo& v, bool b, const list<Bagagem*>& bagagem = list<Bagagem*>());
    /**
     *
     * @return Número de identificação do bilhete.
     */
    unsigned getIdBilhete() const;
    /**
     * Retorna o número de bilhetes comprados até ao momento.
     * @return ID do último bilhete adicionado
     */
    static unsigned getIdCount();
    /**
     *
     * @return passageiro a quem pertence o bilhete.
     */
    Passageiro getPasssageiro() const;
    /**
     *
     * @return voo para o qual o bilhete foi adquirido.
     */
    Voo& getVoo();
    /**
     *
     * @return true se o passageiro tem direito a levar bagagem de mão, caso contrário false.
     */
    bool temBagagemDeMao() const;
    /**
     *
     * @return lista com os volumes de bagagem do passageiro para o voo em questão.
     */
    list<Bagagem*>& getBagagem();
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
    /**
     * Um bilhete é tanto menor quanto menor é o nome do passegeiro a quem pertence.
     * Em caso de empate é tanto menor quanto menor é a data de partida do voo a que se refere.
     * Em caso de empate é tanto menor quanto menor é a hora de partida do repetivo voo.
     * @param b é o objeto a ser comparado com esta instância.
     * @return true se esta instância é menor que b, caso contrário false.
     */
    bool operator< (Bilhete& b);
    /**
     * Dois bilhetes são iguais se tiverem o mesmo ID
     * @param b é o objeto a ser comparado com esta instância
     * @return true se esta instância é igual a b, caso contràrio false
     */
    bool operator== (const Bilhete& b) const;
    /**
     * Este operador envia para uma outputstream toda a informação sobre um bilhete que deverá ser mostrada ao utilizador.
     * @param os outputstream que conterá informação sobre o bilhete
     * @param b bilhete do qual se pretende obter informação
     * @return outputstream com a informação sobre o bilhete
     */
    friend ostream &operator<<(ostream &os, Bilhete &b);
};

#endif //_BILHETE_H
