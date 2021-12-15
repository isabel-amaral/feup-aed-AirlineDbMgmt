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
    Aeroporto a("Aeroporto Francisco Sá Carneiro", "Porto");

    LocalDeTransporte *l1 = new LocalDeTransporte(300, Autocarro);
    a.addTransporte(l1);

    LocalDeTransporte *l2 = new LocalDeTransporte(750, Comboio);
    a.addTransporte(l2);

    BSTItrIn<LocalDeTransporte*> it(a.getTransportes());
    unsigned numLocaisDeTransporte = 0;
    while(!it.isAtEnd()) {
        numLocaisDeTransporte++;
        it.advance();
    }

    ASSERT_EQ(2, numLocaisDeTransporte);
}

TEST(test_2, test_addVoo) {
    Aviao av("N774AM", 415);

    Aeroporto a1("Aeroporto Francisco Sá Carneiro", "Porto");
    Aeroporto a2("Aeroporto Humberto Delgado", "Lisboa");
    Data d1(17, 12, 2021);
    Voo v1(327, a1, a2, d1, 15.30, 16.21, 0.51, 400, 360);
    av.addVoo(v1);

    Aeroporto a3("Aeroporto de S. Tomé", "S. Miguel");
    Voo v2(327, a2, a3, d1, 17.20, 19.05, 1.45, 400, 345);
    av.addVoo(v2);

    EXPECT_EQ(2, av.getPlanoDeVoo().size());
    EXPECT_EQ(v1, av.getPlanoDeVoo().front());
    EXPECT_EQ(v2, av.getPlanoDeVoo().back());
}

TEST(test_3, test_addServicoPorRealizar) {
    Aviao av("N774AM", 415);

    Data d1(16, 12, 2021);
    Funcionario f1(123, "Sofia");
    Servico s1(Manutencao, d1, f1);
    av.addServicoPorRealizar(s1);

    Data d2(18, 12, 2021);
    Funcionario f2(456, "Milena");
    Servico s2(Limpeza, d2, f2);
    av.addServicoPorRealizar(s2);

    EXPECT_EQ(2,av.getServicosPorRealizar().size());
    EXPECT_EQ(s1, av.getServicosPorRealizar().front());
    EXPECT_EQ(s2, av.getServicosPorRealizar().back());
}