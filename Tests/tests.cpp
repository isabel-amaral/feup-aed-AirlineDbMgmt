#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Aeroporto.h"
#include "Aviao.h"
#include "Bagagem.h"
#include "Bilhete.h"
#include "CompanhiaAerea.h"
#include "Data.h"
#include "Funcionario.h"
#include "Passageiro.h"
#include "Servico.h"
#include "TransportadorDeBagagem.h"
#include "Voo.h"
#include "Horario.h"
#include "LocalDeTransporte.h"
//sofia: para ja inclui todas, dps tiramos as que nao forem precisas

using testing::Eq;
using namespace std;

TEST(test_1, test_addTransporte) {
    Aeroporto a("Francisco Sá Carneiro", "Porto");

    Horario h1(DiasUteis, {9.50, 10.25, 10.58, 11.32, 12.04}); //sofia: nao vale a pena meter aqui mts horas pois nao?
    Horario h2(Sabados, {13.50, 14.25, 14.58, 15.32, 16.04});
    Horario h3(DomingosFeriados, {15.50, 16.25, 16.58, 17.32, 18.04});
    list<Horario> lh1;
    lh1.push_back(h1);
    lh1.push_back(h2);
    lh1.push_back(h3);
    LocalDeTransporte *l1 = new LocalDeTransporte(300, Autocarro, lh1);

    Horario h4(DiasUteis, {1.05, 1.50, 2.34, 3.10, 3.55, 4.45});
    Horario h5(Sabados, {3.46, 4.17, 4.59, 5.39, 6.20, 7.00, 7.41});
    list<Horario> lh2;
    lh2.push_back(h4);
    lh2.push_back(h5);
    LocalDeTransporte *l2 = new LocalDeTransporte(750, Comboio, lh2);

    a.addTransporte(l1);
    a.addTransporte(l2);

    BSTItrIn<LocalDeTransporte*> it(a.getTransportes());
    unsigned numLocaisDeTransporte = 0;
    while(!it.isAtEnd()) {
        numLocaisDeTransporte++;
        it.advance();
    }

    ASSERT_EQ(2, numLocaisDeTransporte);
}