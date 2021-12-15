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

    BST<LocalDeTransporte*> bt = a.getTransportes();
    BSTItrIn<LocalDeTransporte*> it(bt);
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
    EXPECT_EQ(v1.getNumeroVoo(), av.getPlanoDeVoo().front().getNumeroVoo());
    EXPECT_EQ(v2.getNumeroVoo(), av.getPlanoDeVoo().back().getNumeroVoo());
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
    EXPECT_EQ(s1.getData(), av.getServicosPorRealizar().front().getData());
    EXPECT_EQ(s1.getFuncionarioResponsavel().getIdFuncionario(), av.getServicosPorRealizar().front().getFuncionarioResponsavel().getIdFuncionario());
    EXPECT_EQ(Manutencao, av.getServicosPorRealizar().front().getTipoServico());
    EXPECT_EQ(s2.getData(), av.getServicosPorRealizar().back().getData());
    EXPECT_EQ(s2.getFuncionarioResponsavel().getIdFuncionario(), av.getServicosPorRealizar().back().getFuncionarioResponsavel().getIdFuncionario());
    EXPECT_EQ(Limpeza, av.getServicosPorRealizar().back().getTipoServico());
}

TEST(test_4, test_realizarServico) {
    Aviao av("N774AM", 415);

    Data d1(16, 12, 2021);
    Funcionario f1(123, "Sofia");
    Servico s1(Manutencao, d1, f1);
    av.addServicoPorRealizar(s1);

    Data d2(18, 12, 2021);
    Funcionario f2(456, "Milena");
    Servico s2(Limpeza, d2, f2);
    av.addServicoPorRealizar(s2);

    av.realizarServico();
    EXPECT_EQ(1,av.getServicosPorRealizar().size());
    EXPECT_EQ(s2.getData(), av.getServicosPorRealizar().front().getData());
    EXPECT_EQ(s2.getFuncionarioResponsavel().getIdFuncionario(), av.getServicosPorRealizar().front().getFuncionarioResponsavel().getIdFuncionario());
    EXPECT_EQ(Limpeza, av.getServicosPorRealizar().front().getTipoServico());
    EXPECT_EQ(s1.getData(), av.getServicosRealizados().back().getData());
    EXPECT_EQ(s1.getFuncionarioResponsavel().getIdFuncionario(), av.getServicosRealizados().back().getFuncionarioResponsavel().getIdFuncionario());
    EXPECT_EQ(s1.getTipoServico(), av.getServicosRealizados().back().getTipoServico());

}

TEST(test_5, test_adquirirBilhete) { //sofia: nao sei bem que expects fazer
    CompanhiaAerea ca;
    Passageiro p("Isabel", 123, 19, false);
    Aeroporto a1("Aeroporto Francisco Sá Carneiro", "Porto");
    Aeroporto a2("Aeroporto de S. Tomé", "S. Miguel");
    Data d(17, 12, 2021);
    Voo v(327, a1, a2, d, 15.30, 17.55, 2.25, 400, 360);
    bool bilheteAdquirido = ca.adquirirBilhete(p, v, true);

    EXPECT_EQ(true, bilheteAdquirido);
    EXPECT_EQ(1, ca.getBilhetesFromPassageiro(p).size());
}

TEST(test_6, test_adquirirConjuntoBilhetes) { //sofia: e aqui tbm nao
    CompanhiaAerea ca;
    Passageiro p1("Isabel", 123, 19, false);
    Passageiro p2("Filipa", 456, 19, false);
    list<Passageiro> lp;
    lp.push_back(p1);
    lp.push_back(p2);

    Aeroporto a1("Aeroporto Francisco Sá Carneiro", "Porto");
    Aeroporto a2("Aeroporto de S. Tomé", "S. Miguel");
    Data d(17, 12, 2021);
    Voo v(327, a1, a2, d, 15.30, 17.55, 2.25, 400, 360);

    bool bilhetesAdquiridos = ca.adquirirConjuntoBilhetes(lp, v, true);

    EXPECT_EQ(true, bilhetesAdquiridos);
    EXPECT_EQ(2, ca.getBilhetesVendidos().size());
}

TEST(test_7, test_BinarySearchPassageiro) {
    CompanhiaAerea ca;
    Passageiro p1("Isabel", 123, 19, false);
    Passageiro p2("Milena", 456, 19, false);
    Passageiro p3("Sofia", 789, 20, false);
    list<Passageiro> lp;
    lp.push_back(p1);
    lp.push_back(p2);
    lp.push_back(p3);

    Aeroporto a1("Aeroporto Francisco Sá Carneiro", "Porto");
    Aeroporto a2("Aeroporto Internacional de Maputo Mavalane", "Maputo");
    Data d(17, 12, 2021);
    Voo v(327, a1, a2, d, 15.30, 17.55, 2.25, 400, 360);

    ca.adquirirConjuntoBilhetes(lp, v, true);

    EXPECT_EQ(1, ca.BinarySearchPassageiro(p2));

    Passageiro p4("Anete", 321, 18, false);
    EXPECT_EQ(3, ca.BinarySearchPassageiro(p4));
}

TEST(test_8, test_BinarySearchHora) {
    vector<float> vh = {10.30, 11.00, 12.30, 13.15, 14.00, 15.30, 16.45, 17.55, 18.25};
    Horario h(DiasUteis, vh);

    EXPECT_EQ(3, h.BinarySearchHora(13.15));
    EXPECT_EQ(vh[3], vh[h.BinarySearchHora(13.16)]);
}

TEST(test_9, test_addHora) {
    vector<float> vh = {10.30, 11.00, 12.30, 13.15, 14.00, 15.30, 16.45, 17.55, 18.25};
    Horario h(DiasUteis, vh);
    float hora = 16.05;
    h.addHora(hora);
    EXPECT_EQ(hora, h.getHoras()[6]);
}

TEST(test_10, test_updateHorario) {

}

TEST(test_11, test_adicionarAoTapete) {

}

TEST(test_12, test_despejarTapete) { //nao esquecer que ha 2 metodos despejarTapete, ver se preciso fazer 2 testes

}

TEST(test_13, test_adicionarAoCarrinho) {

}

TEST(test_14, test_despejarCarrinho) {

}

TEST(test_15, test_addPassageiro) {

}

TEST(test_16, test_addConjuntoPassageiros) {

}

TEST(test_17, test_realizarCheckIn) {

}