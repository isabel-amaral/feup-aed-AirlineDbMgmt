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

using testing::Eq;
using namespace std;

//Aeroporto::addTransporte()
TEST(test_1, test_addTransporte) {
    Aeroporto a("Aeroporto Francisco Sá Carneiro", "Porto");

    LocalDeTransporte l1(300.0, Autocarro);
    a.addTransporte(l1);
    LocalDeTransporte l2(750.0, Comboio);
    a.addTransporte(l2);

    BST<LocalDeTransporte> bt1 = a.getTransportes();
    BSTItrIn<LocalDeTransporte> it1(bt1);
    unsigned numLocaisDeTransporte = 0;
    vector<LocalDeTransporte> lt;
    while (!it1.isAtEnd()) {
        lt.push_back(it1.retrieve());
        numLocaisDeTransporte++;
        it1.advance();
    }
    EXPECT_EQ(300.0, lt[0].getDistancia());
    EXPECT_EQ(Autocarro, lt[0].getTipo());
    EXPECT_EQ(750.0, lt[1].getDistancia());
    EXPECT_EQ(Comboio, lt[1].getTipo());
    EXPECT_EQ(2, numLocaisDeTransporte);

    Horario h1(DiasUteis, {9.0, 9.30, 10.0, 10.30, 11.0, 11.30, 12.0, 12.30, 13.0, 14.0, 15.30, 16.0, 16.30, 17.0, 18.0, 19.0});
    Horario h2(Sabados, {10.0, 11.0, 12.0, 12.30, 13.0, 14.0, 15.0});
    list<Horario> lh;
    lh.push_back(h1);
    lh.push_back(h2);
    LocalDeTransporte l3(350.0, Autocarro, lh);
    LocalDeTransporte l4(400.0, Metro, lh);
    a.addTransporte(l3);
    a.addTransporte(l4);

    BST<LocalDeTransporte> bt2 = a.getTransportes();
    BSTItrIn<LocalDeTransporte> it2(bt2);
    numLocaisDeTransporte = 0;
    lt.clear();
    while (!it2.isAtEnd()) {
        lt.push_back(it2.retrieve());
        numLocaisDeTransporte++;
        it2.advance();
    }
    EXPECT_EQ(300.0, lt[0].getDistancia());
    EXPECT_EQ(Autocarro, lt[0].getTipo());
    EXPECT_EQ(350.0, lt[1].getDistancia());
    EXPECT_EQ(Autocarro, lt[1].getTipo());
    EXPECT_EQ(400.0, lt[2].getDistancia());
    EXPECT_EQ(Metro, lt[2].getTipo());
    EXPECT_EQ(750.0, lt[3].getDistancia());
    EXPECT_EQ(Comboio, lt[3].getTipo());
    EXPECT_EQ(4, numLocaisDeTransporte);
    //cout << l1 << endl;
    //cout << l2 << endl;
    //cout << l3 << endl;
    //a.showAutocaros();
    //a.showComboios();
    //a.showMetros();
    //a.showLocalTransporteProximo();

}

//Aviao::addVoo()
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

//Aviao::addServicoPorRealizar()
TEST(test_3, test_addServicoPorRealizar) {
    Aviao av("N774AM", 415);

    Data d1(16, 12, 2021);
    Funcionario f1(123, "Sofia");
    Servico s1(Manutencao, d1, f1);
    av.addServicoPorRealizar(s1);

    Data d2(18, 12, 2021);
    Funcionario f2(456, "Milena");
    Servico s2(Limpeza, d2, f2);

    EXPECT_EQ(true, av.addServicoPorRealizar(s2));
    EXPECT_EQ(2,av.getServicosPorRealizar().size());

    EXPECT_EQ(s1.getData(), av.getServicosPorRealizar().front().getData());
    EXPECT_EQ(s1.getFuncionarioResponsavel().getIdFuncionario(), av.getServicosPorRealizar().front().getFuncionarioResponsavel().getIdFuncionario());
    EXPECT_EQ(Manutencao, av.getServicosPorRealizar().front().getTipoServico());

    EXPECT_EQ(s2.getData(), av.getServicosPorRealizar().back().getData());
    EXPECT_EQ(s2.getFuncionarioResponsavel().getIdFuncionario(), av.getServicosPorRealizar().back().getFuncionarioResponsavel().getIdFuncionario());
    EXPECT_EQ(Limpeza, av.getServicosPorRealizar().back().getTipoServico());

    Data d3(18, 11, 2021);
    Funcionario f3(456, "Isabel");
    Servico s3(Limpeza, d3, f3);

    EXPECT_EQ(false, av.addServicoPorRealizar(s3));
    EXPECT_EQ(2, av.getServicosPorRealizar().size());
}

//Aviao::realizarServico()
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

    av.realizarServico();
    EXPECT_EQ(0, av.getServicosPorRealizar().size());
    EXPECT_EQ(2, av.getServicosRealizados().size());
    EXPECT_EQ(false, av.realizarServico());
}

//CompanhiaAerea::adquirirBilhete()
TEST(test_5, test_adquirirBilhete) {
    CompanhiaAerea ca;
    Passageiro p1("Isabel", 123, 19, false);
    Aeroporto a1("Aeroporto Francisco Sá Carneiro", "Porto");
    Aeroporto a2("Aeroporto de S. Tomé", "S. Miguel");
    Data d(17, 12, 2021);
    Voo v(327, a1, a2, d, 15.30, 17.55, 2.25, 400, 360);

    EXPECT_EQ(true, ca.adquirirBilhete(p1, v, true));
    EXPECT_EQ("Isabel", ca.getBilhetesVendidos()[0].getPasssageiro().getNome());
    EXPECT_EQ(123, ca.getBilhetesVendidos()[0].getPasssageiro().getId());
    EXPECT_EQ("Porto", ca.getBilhetesVendidos()[0].getVoo().getOrigem().getCidade());
    EXPECT_EQ("S. Miguel", ca.getBilhetesVendidos()[0].getVoo().getDestino().getCidade());

    Passageiro p2("Filipa", 456, 19, false);
    EXPECT_EQ(true, ca.adquirirBilhete(p2, v, true));
    EXPECT_EQ("Filipa", ca.getBilhetesVendidos()[0].getPasssageiro().getNome());
    EXPECT_EQ(456, ca.getBilhetesVendidos()[0].getPasssageiro().getId());

    v.setNumLugaresReservados(400);
    Passageiro p3("Raquel", 789, 18);
    EXPECT_EQ(false, ca.adquirirBilhete(p3, v, false));

//    for (auto b: ca.getBilhetesVendidos())
//        cout << b<< endl;
}

//CompanhiaAerea::getBilhetesFromPassageiro()
TEST(test_6, test_getBilhetesFromPassageiro) {
    CompanhiaAerea ca;
    Passageiro p("Isabel", 123, 19, false);
    Aeroporto a1("Aeroporto Francisco Sá Carneiro", "Porto");
    Aeroporto a2("Aeroporto de S. Tomé", "S. Miguel");
    Aeroporto a3("Aeroporto de S. Miguel", "S. Tomé");
    Data d1(17, 12, 2021);
    Voo v1(327, a1, a2, d1, 15.30, 17.55, 2.25, 400, 360);
    ca.adquirirBilhete(p, v1, true);

    vector<Bilhete> b = ca.getBilhetesFromPassageiro(p);
    EXPECT_EQ(1, b.size());
    EXPECT_EQ("Isabel", b[0].getPasssageiro().getNome());
    EXPECT_EQ(123, b[0].getPasssageiro().getId());
    EXPECT_EQ("Porto", b[0].getVoo().getOrigem().getCidade());
    EXPECT_EQ("S. Miguel", b[0].getVoo().getDestino().getCidade());

    Data d2(3, 1, 2022);
    Voo v2(328, a2, a1, d2, 15.30, 17.55, 2.25, 400, 360);
    ca.adquirirBilhete(p, v2, false);
    Data d3(14, 7, 2021);
    Voo v3(329, a1, a2, d3, 10.30, 12.55, 2.25, 400, 360);
    ca.adquirirBilhete(p, v3, true);
    Voo v4(330, a2, a3, d3, 15.30, 18.40, 3.10, 400, 360);
    ca.adquirirBilhete(p, v4, true);

    b = ca.getBilhetesFromPassageiro(p);
    EXPECT_EQ(329, b[0].getVoo().getNumeroVoo());
    EXPECT_EQ(330, b[1].getVoo().getNumeroVoo());
    EXPECT_EQ(327, b[2].getVoo().getNumeroVoo());
    EXPECT_EQ(328, b[3].getVoo().getNumeroVoo());
}

//CompanhiaAerea::adquirirConjuntoBilhetes()
TEST(test_7, test_adquirirConjuntoBilhetes) {
    CompanhiaAerea ca;
    Passageiro p1("Isabel", 123, 19, false);
    Passageiro p2("Filipa", 456, 19, false);
    Passageiro p3 ("Sofia", 963, 20, false);
    Passageiro p4 ( "Maria", 756, 14, true);
    Passageiro p5("Sofia", 789, 7, false);

    list<Passageiro> lp;
    lp.push_back(p1);
    lp.push_back(p2);
    lp.push_back(p3);
    lp.push_back(p4);

    Aeroporto a1("Aeroporto Francisco Sá Carneiro", "Porto");
    Aeroporto a2("Aeroporto de S. Tomé", "S. Miguel");
    Data d(17, 12, 2021);
    Voo v1(327, a1, a2, d, 15.30, 17.55, 2.25, 400, 360);
    Voo v2(456, a1, a2, d, 12.30, 19.00, 450, 400, 20);

    EXPECT_EQ(true,  ca.adquirirConjuntoBilhetes(lp, v1, true));
    EXPECT_EQ(4, ca.getBilhetesVendidos().size());
    EXPECT_EQ("Filipa", ca.getBilhetesVendidos()[0].getPasssageiro().getNome());
    EXPECT_EQ("Isabel", ca.getBilhetesVendidos()[1].getPasssageiro().getNome());
    EXPECT_EQ("Maria", ca.getBilhetesVendidos()[2].getPasssageiro().getNome());
    EXPECT_EQ("Sofia", ca.getBilhetesVendidos()[3].getPasssageiro().getNome());

    ca.adquirirBilhete(p5, v2, false);
    EXPECT_EQ(789, ca.getBilhetesVendidos()[3].getPasssageiro().getId());
    EXPECT_EQ(963, ca.getBilhetesVendidos()[4].getPasssageiro().getId());

    //for (auto b : ca.getBilhetesVendidos())
      //  cout << b << endl;
}

//Horario::BinarySearchHora()
TEST(test_8, test_BinarySearchHora) {
    vector<float> vh = {10.30, 11.00, 12.30, 13.15, 14.00, 15.30, 16.45, 17.55, 18.25};
    Horario h(DiasUteis, vh);

    EXPECT_EQ(3, h.BinarySearchHora(13.15));
    EXPECT_EQ(vh[3], vh[h.BinarySearchHora(13.16)]);
}

//Horario::addHora()
TEST(test_9, test_addHora) {
    vector<float> vh = {10.30, 11.00, 12.30, 13.15, 14.00, 15.30, 16.45, 17.55, 18.25};
    Horario h(DiasUteis, vh);
    float hora1 = 16.05;
    float hora2 = 13.16;
    float hora3 =  18.40;
    float hora4 = 9.00;
    float hora5 = 15.27;
    h.addHora(hora1);
    h.addHora(hora2);
    h.addHora(hora3);
    h.addHora(hora4);
    h.addHora(hora5);
    EXPECT_EQ(14, h.getHoras().size());

    //esperado: 9.00, 10.30, 11.00, 12.30, 13.15, 13.16, 14.00, 15.27, 15.30, 16.05, 16.45, 17.55, 18.25, 18.40
//    for (auto h: h.getHoras())
//        cout << h << " ";
//    cout << endl;
}

//Horario::updateHorario()
TEST(test_10, test_updateHorario) {
    Horario h1(DiasUteis, {9.0, 9.30, 10.0, 10.30, 11.0, 11.30, 12.0, 12.30, 13.0, 14.0, 15.30, 16.0, 16.30, 17.0, 18.0, 19.0});
    Horario h2(Sabados, {10.0, 11.0, 12.0, 12.30, 13.0, 14.0, 15.0});
    list<Horario> lh1;
    lh1.push_back(h1);
    lh1.push_back(h2);
    LocalDeTransporte l(300.0, Autocarro, lh1);

    Horario h3(DomingosFeriados, {9.0, 11.0, 12.30, 14.0, 16.3, 18.0, 20.0});
    l.updateHorario(h3);

    EXPECT_EQ(3, l.getHorarios().size());
    EXPECT_EQ(h3.getHoras(), l.getHorarios().back().getHoras());
    EXPECT_EQ(h3.getDia(), l.getHorarios().back().getDia());

    Horario h4(Sabados, {8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 15.30, 16.0, 16.30, 17.0, 17.30});
    l.updateHorario(h4);

    EXPECT_EQ(3, l.getHorarios().size());

    list<Horario> lh2 = l.getHorarios();
    lh2.pop_back();
    LocalDeTransporte l2(300.0, Autocarro, lh2);

    EXPECT_EQ(h4.getHoras(), l2.getHorarios().back().getHoras());
    EXPECT_EQ(h4.getDia(), l2.getHorarios().back().getDia());
}

//TransportadorDeBagagem::adicionarAoTapete()
TEST(test_11, test_adicionarAoTapete) {
    TransportadorDeBagagem t(2, 3, 4);
    Bagagem *b = new Bagagem(30, false);

    t.adicionarAoTapete(b);

    EXPECT_EQ(b, t.getTapeteRolante().back());
}

//TransportadorDeBagagem::adicionarAoCarrinho()
TEST(test_12, test_adicionarAoCarrinho) {
    TransportadorDeBagagem t(2, 3, 4);
    Bagagem *b = new Bagagem(30, false);
    t.adicionarAoCarrinho(b);

    EXPECT_EQ(b, t.getCarrinho().front().front().top());
    EXPECT_EQ(0, t.getTapeteRolante().size());
}
//TransportadorDeBagagem::despejarTapete()
TEST(test_13, test_despejarTapete) {
    TransportadorDeBagagem t(2, 3, 4);

    Bagagem *b1 = new Bagagem(30, false);
    t.adicionarAoTapete(b1);

    Bagagem *b2 = new Bagagem(15, true);
    t.adicionarAoTapete(b2);

    t.despejarTapete();
    EXPECT_EQ(b2, t.getCarrinho().front().front().top());

    t.adicionarAoTapete(b1);
    t.adicionarAoTapete(b2);
    Bagagem *b3 = new Bagagem(27, false);
    t.adicionarAoTapete(b3);

    t.despejarTapete(2);

    EXPECT_EQ(2, t.getCarrinho().size());
    EXPECT_EQ(1, t.getTapeteRolante().size());
    EXPECT_EQ(b3, t.getTapeteRolante().front());
}

TEST(test_14, test_despejarCarrinho) {
    TransportadorDeBagagem t(2, 3, 4);

    Bagagem *b1 = new Bagagem(30, false);
    t.adicionarAoCarrinho(b1);

    Bagagem *b2 = new Bagagem(15, true);
    t.adicionarAoCarrinho(b2);

    t.despejarCarrinho();
    EXPECT_EQ(2, t.getCarrinho().size());
}

TEST(test_15, test_addPassageiro) {
    Passageiro p1("Isabel", 123, 19, false);
    Passageiro p2("Milena", 456, 19, false);
    Passageiro p3("Sofia", 789, 20, false);

    Aeroporto a1("Aeroporto Francisco Sá Carneiro", "Porto");
    Aeroporto a2("Aeroporto de S.Tomé", "S. Miguel");
    Data d(17, 12, 2021);
    Voo v(327, a1, a2, d, 15.30, 17.55, 2.25, 400, 360);

    v.addPassageiro(p1);
    v.addPassageiro(p2);
    v.addPassageiro(p3);

    EXPECT_EQ(3, v.getPassageiros().size());
}

TEST(test_16, test_addConjuntoPassageiros) {
    Passageiro p1("Isabel", 123, 19, false);
    Passageiro p2("Milena", 456, 19, false);
    Passageiro p3("Sofia", 789, 20, false);
    list<Passageiro> l;
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);

    Aeroporto a1("Aeroporto Francisco Sá Carneiro", "Porto");
    Aeroporto a2("Aeroporto de S.Tomé", "S. Miguel");
    Data d(17, 12, 2021);
    Voo v(327, a1, a2, d, 15.30, 17.55, 2.25, 400, 360);

    v.addConjuntoPassageiros(l);
    EXPECT_EQ(3, v.getPassageiros().size());
}

TEST(test_17, test_realizarCheckIn) {
    Aeroporto a1("Aeroporto Francisco Sá Carneiro", "Porto");
    Aeroporto a2("Aeroporto de S.Tomé", "S. Miguel");
    Data d(17, 12, 2021);
    Voo v(327, a1, a2, d, 15.30, 17.55, 2.25, 400, 360);

    Passageiro p("Isabel", 123, 19, false);

    v.realizarCheckIn(p);
    EXPECT_EQ(1, v.getPassageirosCheckedIn().size());
}