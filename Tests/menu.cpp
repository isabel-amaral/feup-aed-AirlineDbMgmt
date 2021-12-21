#include "menu.h"

Menu::Menu() {
    option = 0;
    LoadData loader(companhia);
    lastMenu.push(0);   //'0' representa o menu inicial/principal
    menu0();
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
        else {  // O utilizador introduziu um inteiro invalido
            validOption = false;
            cout << "OPCAO INVALIDA! TENTE NOVAMENTE. " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (!validOption);
}

void Menu::processOption() {
    switch (option) {
        case 0: menu0(); break;
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
        case 26: menu26(); break;
    }
}

void Menu::menu0() {
    cout << "1. Pesquisar Voos" << endl;
    cout << "2. Realizar Check-in" << endl;
    cout << "3. As minhas Reservas" << endl;
    cout << "4. Transportes: Locais e Horarios" << endl;
    cout << "5. Companhia: Pesquisa e Listagens" << endl;
    cout << "0. Sair." << endl;
    cout << "\nESCOLHA UMA OPCAO:";
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
    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

//As minhas Reservas
void Menu::menu3() {
    unsigned idPassageiro, numBilhete;
    cout << "\nInsira o seu numero de identificacao: ";
    cin >> idPassageiro;

    if (idPassageiro != 0){
        companhia.showBilhetesFromPassageiro(idPassageiro);

        cout << "1. Cancelar uma viagem" << endl;
        cout << "0. voltar" << endl;
        cout << "\nESCOLHA UMA OPCAO: ";
        readOption(0, 3);

        if(option == 1) {
            cout << "Insira o numero do bilhete: ";
            cin >> numBilhete;
            Bilhete b = companhia.getBilheteID(numBilhete);

            if (b.getPasssageiro().getId() != idPassageiro)
                cout << "Nao foi possivel encontrar registo do seu bilhete" << endl;
            else if (find(b.getVoo().getPassageiros().begin(), b.getVoo().getPassageiros().end(), b.getPasssageiro()) != b.getVoo().getPassageiros().end())
                companhia.showBagagem(b);
            else
                cout << "Nao foi possivel encontrar registo da sua bagagem" << endl;
        }

        else if (option == 2) {
            Passageiro p = companhia.getPassageiroID(idPassageiro);
            if (p.getMultaBagagem() == 0)
                cout << "Neste momento nao tem nenhuma multa a pagar" << endl;
            else
                cout << "Tem " << p.getMultaBagagem() << " euros a pagar";
        }

        else if (option == 3) {
            cout << "Insira o numero do bilhete: ";
            cin >> numBilhete;
            if (companhia.cancelarViagem(numBilhete))
                cout << "Viagem cancelada" << endl;
            else
                cout << "Nao foi possivel cancelar a viagem" << endl;
        }

        cout << endl;
        option = lastMenu.top();
        lastMenu.pop();
        processOption();
    }
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
    cout << "26. Gestao dos avioes." << endl;
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

    if (companhia.showVoos())
        menuCompra();

    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

//Visualizar voos com partida numa determinada cidade
void Menu::menu7() {
    string resposta, cidade;
    unsigned dia, mes, ano, n = 0;

    for (const auto& a: companhia.getAeroportos()){
        cout << n+1 << "- " << a.getCidade() << endl;
        n++;
    }
    cout << "\nInsira a cidade de partida: ";
    readOption(1,companhia.getAeroportos().size());
    cidade = companhia.getAeroportos().at( option -1).getCidade();

    cout << "\nDeseja selecionar alguma data? [Escolha 'S'-Sim ou 'N'- Nao ou 0-Voltar]" << endl;
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

    else if (resposta == "N" && companhia.showVoosPartida(cidade)){
        menuCompra();
    }

    else if (resposta == "S"){
        cout << "\nESCOLHA O DIA, O MES E O ANO" << endl;
        cout << "Dia: ";    cin >> dia;
        cout << "Mes: ";  cin >> mes;
        cout << "Ano: ";  cin >> ano;
        Data d1 (dia, mes, ano);

        if (companhia.showVoosPartida(cidade, d1))
            menuCompra();
    }

    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

//Visualizar voos com chegada numa determinada cidade
void Menu::menu8() {
    string resposta, cidade;
    unsigned dia, mes, ano, n = 0;

    for (const auto& a: companhia.getAeroportos()){
        cout << n+1 << "- " << a.getCidade() << endl;
        n++;
    }
    cout << "\nInsira a cidade de partida: ";
    readOption(1,companhia.getAeroportos().size());
    cidade = companhia.getAeroportos().at( option -1).getCidade();

    cout << "\nDeseja selecionar alguma data? [Escolha 'S'-Sim ou 'N'- Nao ou 0-Voltar]" << endl;
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

    else if (resposta == "N" && companhia.showVoosChegada(cidade)){
        menuCompra();
    }

    else if (resposta == "S"){
        cout << "\nESCOLHA O DIA, O MES E O ANO" << endl;
        cout << "Dia: ";    cin >> dia;
        cout << "Mes: ";  cin >> mes;
        cout << "Ano: ";  cin >> ano;
        Data d1 (dia, mes, ano);

        if (companhia.showVoosChegada(cidade, d1))
            menuCompra();
    }

    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

//Visualizar voos entre duas cidades selecionadas
void Menu::menu9() {
    unsigned dia, mes, ano, n=0;
    string origem, destino;

    for (const auto& a: companhia.getAeroportos()){
        cout << n+1 << "- " << a.getCidade() << endl;
        n++;
    }

    cout << "\nSELECIONE A ORIGEM: ";
    readOption(1,companhia.getAeroportos().size());
    origem =companhia.getAeroportos().at( option -1).getCidade();

    cout << "\nSELECIONE O DESTINO: ";
    readOption(1,companhia.getAeroportos().size());
    destino = companhia.getAeroportos().at( option -1).getCidade();

    cout << "\nData Inicial: ";
    cout << "\nDia: "; cin >> dia;
    cout << "Mes: "; cin >> mes;
    cout << "Ano: "; cin >> ano;
    Data partida (dia, mes, ano);
    cout << endl;

    cout <<  "\nData Final: ";
    cout << "\nDia: "; cin >> dia;
    cout << "Mes: "; cin >> mes;
    cout << "Ano: "; cin >> ano;
    Data regresso(dia, mes, ano);

    if (companhia.showVoosCidades(origem, destino, partida, regresso))
        menuCompra();

    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

//Visualizar voos realizados em determinadas datas
void Menu::menu10() {
    string origem, destino;
    unsigned dia, mes, ano, n = 0;

    cout << "\nData de partida: ";
    cout << "\nDia: "; cin >> dia;
    cout << "Mes: "; cin >> mes;
    cout << "Ano: "; cin >> ano;
    Data partida (dia, mes, ano);

    cout << endl;
    cout <<  "\nData de regresso: ";
    cout << "\nDia: "; cin >> dia;
    cout << "Mes: "; cin >> mes;
    cout << "Ano: "; cin >> ano;
    Data regresso (dia, mes, ano);

    if (companhia.showVoosDatas(partida, regresso))
        menuCompra();

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

    cout << "\nNumero do voo: "; cin >> n;
    cout << "Aeroporto de origem: "; getline(cin, nome);
    cout << "Cidade: "; getline(cin, cidade);
    Aeroporto ao(nome, cidade);

    cout << "\nAeroporto de destino: "; getline(cin, nome);
    cout << "Cidade: "; getline(cin, cidade);
    Aeroporto ad(nome, cidade);

    cout << "\nData de ida: "; cin >> dia >> mes >> ano ;
    Data partida(dia, mes, ano);

    cout << "Hora de partida: "; cin >> hp;
    cout << "Hora de chegada: "; cin >> hc;
    cout << "Duracao prevista: "; cin >> d;
    cout << "Lotacao do aviao: "; cin >> l;

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

    cout << "\nMatrícula do aviao: "; cin >> m;
    cout << "Tipo do avião: ";        cin >> t;
    cout << "Capacidade do aviao: ";  cin >> c;

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
    cout << "Cidade: ";
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
    cout << "Cidade: ";
    getline(cin, cidade);

    Aeroporto a(nome, cidade);
    index = companhia.binarySearchAeroporto(a.getNome());
    if (companhia.getAeroportos()[index].getNome() == nome && companhia.getAeroportos()[index].getCidade() == cidade)
        cout << "\nA nossa companhia possui voos com partida/destino neste aeroporto." << endl;
    else
        cout << "\nA nossa companhia nao realiza voos com partida/destino nest aeoroporto" << endl;

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

    for (Voo& v: companhia.getVoos()) {
        if (v.getNumeroVoo() == n) {
            for ( Passageiro& p: v.getPassageirosCheckedIn()) {
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

void Menu::menu26() {
    unsigned n=0, copyOption;
    cout << "1. Agendar servico" << endl;
    cout << "2. Realizar servico" << endl;
    cout << "3. Visualizar os servicos que um aviao necessita" << endl;
    cout << "4. Visualizar os servicos ja realizados num aviao" << endl;
    cout << "5. Visualizar plano de voo" << endl;
    cout << "0. Voltar"<< endl;
    cout << "ESCOLHA UMA OPCAO: " ;
    readOption(0, 5);
    copyOption = option;

    for (const auto& aviao: companhia.getAvioes()){
        cout << n+1 << "- " << aviao.getMatricula() << endl;
        n++;
    }

    cout << "\nSELECIONE A MATRICULA DO AVIAO: " << "(" << 1 << "-" << companhia.getAvioes().size() << ")";
    readOption(1,companhia.getAvioes().size());

    //Agendar servico
    if (copyOption == 1) {
        TipoServico tipo;
        string nomeFunc;
        unsigned idFunc, dia, mes, ano;
        cout << "1. Limpeza." << endl;
        cout << "2. Manutencao." << endl;
        cout << "\nESCOLHA O TIPO DE SERVICO: (0 para voltar a pagina anterior.)" << endl;
        readOption(0,2);
        tipo = (option == 1) ? Limpeza : Manutencao;

        cout << "Indique a data:" << endl;
        cout << "Dia: " ;
        cin >> dia;
        cout << "Mes: " ;
        cin >> mes;
        cout << "Ano: " ;
        cin >> ano;
        Data d(dia, mes, ano);

        cout << "Id:" << endl;
        cin >> idFunc;
        cout << "Nome do funcionario: " ;
        cin.ignore (1000, '\n');
        getline (cin, nomeFunc);
        Funcionario f(idFunc, nomeFunc);

        if (companhia.getAvioes().at(option -1).addServicoPorRealizar(Servico (tipo, d, f)))
            cout << "SERVICO AGENDADO COM SUCESSO." << endl;
        else
            cout << "NAO FOI POSSIVEL AGENDAR O SERVICO." << endl;
    }

    //Realizar servico
    else if (copyOption == 2) {
        if (companhia.getAvioes().at(option - 1).realizarServico())
            cout << "\nSERVICO REALIZADO COM SUCESSO!" << endl;
        else
            cout << "ESTE AVIAO NAO TEM NENHUM SERVICO AGENDADO!" << endl;
    }

    //Visualizar os servicos que um aviao necessita
    else if (copyOption == 3) {
        if (!companhia.getAvioes().at (option - 1).getServicosPorRealizar().empty()){
            queue<Servico> copyServicosPorRealizar = companhia.getAvioes().at(option - 1).getServicosPorRealizar();
            while (!copyServicosPorRealizar.empty()) {
                cout << copyServicosPorRealizar.front() << endl;
                cout << "---------------" << endl;
                copyServicosPorRealizar.pop();
            }
        }
        else
            cout << "ESTE AVIAO NAO TEM NENHUM SERVICO AGENDADO!" << endl;
    }

    //Visualizar os servicos já realizados num aviao
    else if (copyOption == 4){
        if (! companhia.getAvioes().at (option -1 ).getServicosRealizados().empty()) {
            queue <Servico> copyServicosRealizados =  companhia.getAvioes().at(option - 1).getServicosRealizados();
            while (!copyServicosRealizados.empty()) {
                cout << copyServicosRealizados.front() << endl;
                cout << "---------------" << endl;
                copyServicosRealizados.pop();
            }
        }

        else
            cout << "NENHUM SERVICO FOI REALIZADO !" << endl;
    }

    //Visualizar plano de voo
    else if (copyOption == 5) {
        if (!companhia.getAvioes().at (option -1 ).getPlanoDeVoo().empty()){
            for (auto & i : companhia.getAvioes().at (option -1 ).getPlanoDeVoo()){
                cout << i ;
                cout << "---------------" << endl;
            }
        }

        else
            cout << "ESTE AVIAO NAO POSSUI NENHUM VOO AGENDADO" << endl;
    }
    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

void Menu::menuCompra() {
    int numPessoas, id, idade, nrVoo, numBagagens;
    string nome, resposta;
    bool menorNaoAcompanhado =false, bagagemMao, compraRealizada;
    float peso;
    list <Passageiro> passageiros;
    list <list<Bagagem*>> malas;
    list <Bagagem*> b;

    cout << "\n1. Comprar um bilhete" << endl ;
    cout << "0. Voltar"<< endl;
    cout << "ESCOLHA UMA OPCAO: ";
    readOption(0 ,1);

    if ( option == 0){
        return;
    }

    cout << "\nINSIRA O NUMERO DO VOO PARA O QUAL DESEJA COMPRAR BILHETE: " ;
    cin >> nrVoo;

    for (Voo& v: companhia.getVoos() ){
        if (v.getNumeroVoo() == nrVoo){
            cout << "INSIRA O NUMERO DE PESSOAS: (0 para voltar): " ;
            cin >> numPessoas;

            if (numPessoas == 0)
                return;

            cout << "Deseja levar bagagem de mao? "<< endl;
            cout << "1. Sim" << endl;
            cout << "2. Nao" << endl;
            readOption(1,2);
            bagagemMao = (option == 1);

            while (numPessoas > 0) {
                b.clear();
                cin.ignore(10000, '\n');

                cout << "\nNome: " ;
                getline (cin, nome);
                cout << "No. de identificacao: " ;
                cin >> id;
                cout << "Idade: ";
                cin >> idade;

                if (idade < 18) {
                    cout << "Menor acompanhado por um adulto:" << endl;
                    cout << "1. Sim" << endl;
                    cout << "2. Nao" << endl;
                    readOption(1, 2);
                    menorNaoAcompanhado = (option == 2);
                }
                cout << "Quantas bagagens de porao deseja levar? " << endl;
                cin >> numBagagens;

                if (bagagemMao) {
                    cout << "Peso da bagagem de mao: ";
                    cin >> peso;
                    cout << "Pretende usar o nosso serviço de check-in automático de bagagem? [Escolha 'S'-Sim ou 'N'- Nao]" << endl;
                    do {
                        getline (cin, resposta);
                        if (resposta != "S" && resposta != "N")
                            cout << "ESCOLHA INVALIDA! TENTE NOVAMENTE." <<endl;
                    } while (resposta != "S" && resposta != "N");

                    Bagagem* bMao;
                    if (resposta == "S")
                        bMao = new Bagagem(peso, bagagemMao, true);
                    else
                        bMao = new Bagagem(peso, bagagemMao, false);
                    b.push_back(bMao);
                }

                while (numBagagens > 0){
                    cout << "Peso da bagagem de porao: ";
                    cin >> peso;
                    cout << "Pretende usar o nosso serviço de check-in automático de bagagem? [Escolha 'S'-Sim ou 'N'- Nao]" << endl;
                    do {
                        getline (cin, resposta);
                        if (resposta != "S" && resposta != "N")
                            cout << "ESCOLHA INVALIDA! TENTE NOVAMENTE." <<endl;
                    } while (resposta != "S" && resposta != "N");

                    Bagagem* bPorao;
                    if (resposta == "S")
                        bPorao = new Bagagem(peso, bagagemMao, true);
                    else
                        bPorao = new Bagagem(peso, bagagemMao, false);
                    b.push_back(bPorao);
                    numBagagens--;
                }

                Passageiro p (nome, id, idade,menorNaoAcompanhado);
                passageiros.push_back(p);
                malas.push_back(b);

                menorNaoAcompanhado = false;
                numPessoas--;
            }

            if (passageiros.size() > 1)
                compraRealizada = companhia.adquirirConjuntoBilhetes(passageiros, v, bagagemMao, malas);
            else
                compraRealizada = companhia.adquirirBilhete(*(passageiros.begin()), v, bagagemMao, malas.front());

            if (compraRealizada)
                cout << "COMPRA REALIZADA COM SUCESSO!" << endl;
            else
                cout << "NAO FOI POSSIVEL REALIZAR A COMPRA" << endl;
            return;
        }
    }
    cout << "NUMERO DE VOO INVALIDO!" << endl;
}



