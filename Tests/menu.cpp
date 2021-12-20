#include "menu.h"

Menu::Menu() {
    companhia.loadData();
    lastMenu.push(0);   //'0' representa o menu inicial/principal

    cout << "1. Pesquisar Voos" << endl;
    cout << "2. Realizar Check-in" << endl;
    cout << "3. As minhas Reservas" << endl;
    cout << "4. Transportes: Locais e Horarios" << endl;
    cout << "5. Companhia: Pesquisa e Listagens" << endl;
    cout << "0. Sair." << endl;
    cout << "\nESCOLHA UMA OPCAO: ";
    readOption(0, 5);

    if (option) {
        lastMenu.push(0);
        processOption();
    }
    else {
        cout << "VOLTE SEMPRE.";
        exit (0);
    }
}

void Menu::readOption(const unsigned& minOption, const unsigned& maxOption) {
    bool validOption;
    do {
        cin >> option;
        if (cin.fail()) {
            if (cin.eof()) {
                cout << "VOLTE SEMPRE." << endl;
                exit (1);
            }
            else {
                validOption = false;
                cout << "OPCAO INVALIDA! TENTE NOVAMENTE" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
        else if ((minOption <= option &&  option <= maxOption) || option == 0) {
            validOption = true;
            cin.ignore(1000, '\n');
        }
        else {  //O utilizador introduziu um inteiro invalido
            validOption = false;
            cout << "OPCAO INVALIDA! TENTE NOVAMENTE. " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (!validOption);
}

void Menu::processOption() {
    switch (option) {
        case 0: Menu(); break;
        case 1: menu1(); break;
        case 2: menu2(); break;
        case 3: menu3(); break;
        case 4: menu4(); break;
        case 5: menu5(); break;
        case 6: menu6(); break;
        case 7: menu7(); break;
        case 8: menu8(); break;
        case 9: menu9(); break;
        case 10: menu10(); break;
        case 19: menu19(); break;
        case 20: menu20(); break;
        case 21: menu21(); break;
        case 22: menu22(); break;
        case 23: menu23(); break;
        case 24: menu24(); break;
        case 25: menu25(); break;
    }
}

//Pesquisar Voos
void Menu::menu1() {
    cout << "\n6. Imprimir todos os voos" << endl;
    cout << "7. Visualizar voos com partida numa determinada cidade" << endl;
    cout << "8. Visualizar voos com chegada numa determinada cidade" << endl;
    cout << "9. Visualizar voos entre duas cidades selecionadas" << endl;
    cout << "10. Visualizar voos realizados em determinadas datas" << endl;
    cout << "0. Voltar a pagina anterior" << endl;
    cout << "\nESCOLHA UMA OPCAO: ";
    readOption(6,10);

    if (option)
        lastMenu.push(1);
    else {
        option = lastMenu.top();
        lastMenu.pop();
    }
    processOption();
}

//Realizar Check-in
void Menu::menu2() {
    unsigned numeroBilhete;
    cout << "\nIntroduza o numero do seu bilhete de viagem (Clique 0 para voltar a pagina anterior): ";
    cin >> numeroBilhete;
    if (numeroBilhete != 0) {
        if (companhia.realizarCheckIn(numeroBilhete))
            cout << "\nCHECK-IN FEITO COM SUCESSO!" << endl;
        else
            cout << "\nNAO FOI POSSIVEL REALIZAR O CHECK-IN!" << endl;
    }
    else {
        option = lastMenu.top();
        lastMenu.pop();
    }
    processOption();
}

//As minhas Reservas
void Menu::menu3() {
    unsigned idPassageiro;
    cout << "\nInsira o seu numero de identificacao:";
    cin >> idPassageiro;

   if (idPassageiro != 0)
       companhia.showBilhetesFromPassageiro(idPassageiro);
}

//Transportes: Locais e Horarios
void Menu::menu4() {
    int n = 0;
    int opOrdenacao;
    Aeroporto a1;
    for (const auto& a: companhia.getAeroportos()){
        cout << n + 1 << "- ";
        cout << a.getNome() << "  " << endl;
        n++;
    }
    cout << "\nEscolha uma das opcoes relativas ao nome do aeroporto (0 para voltar a pagina anterior):";

    readOption(1, n);
    if (option == 0) {
        option = lastMenu.top();
        lastMenu.pop();
        processOption();
    }
    a1 = companhia.getAeroportos().at(option - 1);

    cout << "\n11. Visualizar dados de todos os locais de transporte" << endl;
    cout << "12. Visualizar dados de todos os locais de Metro" << endl;
    cout << "13. Visualizar dados de todos os locais de Comboio" << endl;
    cout << "14. Visualizar dados de todos os locais de Autocarro" << endl;
    cout << "15. Visualizar dados do local de transporte mais proximo" << endl;
    cout << "16. Visualizar dados do local de transporte de Metro mais proximo" << endl;
    cout << "17. Visualizar dados do local de transporte de Comboio mais proximo" << endl;
    cout << "18. Visualizar dados do local de transporte de Autocarro mais proximo" << endl;
    cout << "0. Voltar a pagina anterior." << endl;
    cout << "\nESCOLHA UMA OPCAO: ";
    readOption(11, 18);

    if (option == 0) {
        option = lastMenu.top();
        lastMenu.pop();
        processOption();
    }
    if (option >= 11 && option <= 14) {
        lastMenu.push (4);
        cout << "\n1. Distancia Ascendente - Disponibilidade Ascendente - Tipo " << endl;
        cout << "2. Disponibilidade Ascendente - Distancia Ascendente - Tipo" << endl;
        cout << "3. Tipo - Distancia Ascendente - Disponibilidade Ascendente " << endl;
        cout << endl << "\nESCOLHA EM QUE ORDEM DESEJA QUE OS DADOS SEJAM APRESENTADOS:";
        cin >> opOrdenacao;
    }

    switch (option) {
        case 11: a1.showTransportes(opOrdenacao); break;
        case 12: a1.showMetros(opOrdenacao); break;
        case 13: a1.showComboios(opOrdenacao); break;
        case 14: a1.showAutocaros(opOrdenacao); break;
        case 15: a1.showLocalTransporteProximo(); break;
        case 16: a1.showMetroProximo(); break;
        case 17: a1.showComboioProximo(); break;
        case 18: a1.showAutocarroProximo(); break;
    }
    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

//Companhia: Pesquisa e Listagens
void Menu::menu5() {
    cout << "\n19. Adicionar voo." << endl;
    cout << "20. Adicionar aviao." << endl;
    cout << "21. Adicionar aeroporto." << endl;
    cout << "22. Visualizar os aeroportos." << endl;
    cout << "23. Procurar aeroporto." << endl;
    cout << "24. Visualizar os passageiros de um voo." << endl;
    cout << "25. Visualizar numero de passageiros que fizeram check-in num voo." << endl;
    cout << "0. Voltar a pagina anterior." << endl;
    cout <<  "\nESCOLHA UMA OPCAO: ";
    readOption(19, 25);

    if (option)
        lastMenu.push(5);
    else {
        option=lastMenu.top();
        lastMenu.pop();
    }
    processOption();
}

//Imprimir todos os voos
void Menu::menu6() {
    companhia.showVoos();
    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

//Visualizar voos com partida numa determinada cidade
void Menu::menu7() {
    string cidade;
    string resposta;
    unsigned dia, mes, ano;

    cout << "\nInsira a cidade de partida: ";
    getline(cin, cidade);

    cout << "\nPossui uma data em especifico? [Escolha 'S'-Sim ou 'N'- Nao ou 0-Voltar]" << endl;
    do {
        getline (cin, resposta);
        if (resposta != "S" && resposta != "N" && resposta != "0"){
            cout << "ESCOLHA INVALIDA! TENTE NOVAMENTE." <<endl;
        }
    } while (resposta != "S" && resposta != "N" && resposta != "0") ;

    if (resposta == "0") {
        option = lastMenu.top();
        lastMenu.pop();
        processOption();
    }
    if (resposta == "N")
        companhia.showVoosPartida(cidade);
    else if (resposta == "S") {
        cout << "\nESCOLHA O DIA, O MES E O ANO" << endl;
        cout << "Dia: ";
        cin >> dia;
        cout << "Mes: ";
        cin >> mes;
        cout << "Ano: ";
        cin >> ano;
        Data d1(dia, mes, ano);
        companhia.showVoosPartida(cidade, d1);
    }
    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

//Visualizar voos com chegada numa determinada cidade
void Menu::menu8() {
    string cidade, resposta;
    unsigned dia, mes, ano;

    cout << "\nInsira o destino:";
    getline(cin, cidade);
    cout << "\nPossui uma data em especifico? [Escolha 'S'-Sim ou 'N'- Nao ou 0-Voltar]" << endl;
    do{
        getline (cin, resposta);
        if (resposta != "S" && resposta != "N" && resposta != "0"){
            cout << "ESCOLHA INVALIDA! TENTE NOVAMENTE." <<endl;
        }
    } while (resposta != "S" && resposta != "N" && resposta != "0") ;

    if (resposta == "0"){
        option = lastMenu.top();
        lastMenu.pop();
        processOption();
    }

    if (resposta == "N"){
        companhia.showVoosChegada(cidade);
    }
    else if (resposta == "S"){
        cout << "\nESCOLHA O DIA, O MES E O ANO: " << endl;
        cout << "Dia: ";
        cin >> dia;
        cout << "\nMes: ";
        cin >> mes;
        cout << "\nAno: ";
        cin >> ano;
        Data d1 (dia, mes, ano);

        companhia.showVoosChegada(cidade, d1);
    }
    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

//Visualizar voos entre duas cidades selecionadas
//TODO: testar
void Menu::menu9() {
    string origem, destino;
    unsigned dia, mes, ano;

    cout << "\nOrigem: ";
    getline(cin,origem);
    cout << "\nDestino: ";
    getline (cin, destino);

    cout << "\nData de partida: ";
    cout << "Dia: ";
    cin >> dia;
    cout << "\nMes: ";
    cin >> mes;
    cout << "\nAno: ";
    cin >> ano;
    Data partida (dia, mes, ano);

    cout << endl;
    cout <<  "\nData de regresso: ";
    cout << "Dia: ";
    cin >> dia;
    cout << "\nMes: ";
    cin >> mes;
    cout << "\nAno: ";
    cin >> ano;
    Data regresso (dia, mes, ano);

    companhia.showVoosCidades(origem, destino, partida, regresso);
    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

//Visualizar voos realizados em determinadas datas
void Menu::menu10() {
    string origem, destino;
    unsigned dia, mes, ano;

    cout << "\nData de partida: ";
    cout << "Dia: ";
    cin >> dia;
    cout << "\nMes: ";
    cin >> mes;
    cout << "\nAno: ";
    cin >> ano;
    Data partida (dia, mes, ano);

    cout << endl;
    cout <<  "\nData de regresso: ";
    cout << "Dia: ";
    cin >> dia;
    cout << "\nMes: ";
    cin >> mes;
    cout << "\nAno: ";
    cin >> ano;
    Data regresso (dia, mes, ano);

    companhia.showVoosDatas(partida, regresso);
    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

//Adicionar voo
void Menu::menu19() {
    unsigned n;
    float hp, hc, d;
    unsigned l, dia, mes, ano;
    string nome, cidade;

    cout << "\nNumero do voo: ";
    cin >> n;
    cout << "\nAeroporto de origem: ";
    getline(cin, nome);
    cout << "\nCidade: ";
    getline(cin, cidade);
    Aeroporto ao(nome, cidade);
    cout << "\nAeroporto de destino: ";
    getline(cin, nome);
    cout << "\nCidade: ";
    getline(cin, cidade);
    Aeroporto ad(nome, cidade);
    cout << "\nData de ida: ";
    cin >> dia >> mes >> ano ;
    Data partida(dia, mes, ano);
    cout << "\nHora de partida: ";
    cin >> hp;
    cout << "\nHora de chegada: ";
    cin >> hc;
    cout << "\nDuracao prevista: ";
    cin >> d;
    cout << "\nLotacao do aviao: ";
    cin >> l;

    Voo v(n, ao, ad, partida, hp, hc, d, l, 0);
    companhia.addVoo(v);

    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

//Adicionar aviao
void Menu::menu20() {
    string m, t;
    unsigned c;

    cout << "\nMatrícula do aviao: ";
    cin >> m;
    cout << "\nTipo do avião: ";
    cin >> t;
    cout << "\nCapacidade do aviao: ";
    cin >> c;

    Aviao a(m, t, c);
    companhia.addAviao(a);

    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

//Adicionar aeroporto
void Menu::menu21() {
    string nome, cidade;

    cout << "\nNome: ";
    getline(cin, nome);
    cout << "\nCidade: ";
    getline(cin, cidade);

    Aeroporto a(nome, cidade);
    companhia.addAeroporto(a);

    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

//Visualizar os aeroportos
void Menu::menu22() {
    vector<Aeroporto> a = companhia.getAeroportos();
    sort(a.begin(), a.end());

    for (const Aeroporto& ap: a) {
        cout << ap.getNome() << endl;
        cout << ap.getCidade() << endl;
    }

    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

//Procurar aeroporto
void Menu::menu23() {
    string nome, cidade;
    unsigned index;

    cout << "\nNome: ";
    getline(cin, nome);
    cout << "\nCidade: ";
    getline(cin, cidade);

    Aeroporto a(nome, cidade);
    index = companhia.binarySearchAeroporto(a.getNome());
    if (companhia.getAeroportos()[index].getNome() == nome && companhia.getAeroportos()[index].getCidade() == cidade)
        cout << "\nA nossa companhia possui voos com partida/destino neste aeroporto." << endl;
    else{
        cout << "\nA nossa companhia nao realiza voos com partida/destino nest aeoroporto" << endl;
    }

    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

//Visualizar os passageiros de um voo
void Menu::menu24() {
    unsigned n;
    cout << "\nNumero de voo: " << endl;
    cin >> n;

    for (const Passageiro& p: companhia.getPassageirosFromVoo(n)) {
        cout << p << endl;
        cout << endl;
    }

    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

//Visualizar numero de passageiros que fizeram check-in num voo
void Menu::menu25() {
    unsigned n;
    cout << "\nNumero de voo: " << endl;
    cin >> n;

    for (const Voo& v: companhia.getVoos()) {
        if (v.getNumeroVoo() == n) {
            for (const Passageiro& p: v.getPassageirosCheckedIn()) {
                cout << p << endl;
                cout << endl;
            }
            break;
        }
    }

    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}
