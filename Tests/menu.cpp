//
// Created by ASUS on 18/12/2021.
//

#include "menu.h"

void menu::readOption(const int &minOption, const int &maxOption) {
    bool validOption;
    do
    {
        cin >> option;
        if (cin.fail())
        {
            if (cin.eof())
            {
                cout << "Volte Sempre" << endl;
                exit (1);
            }
            else
            {
                validOption = false;
                cout << "OPCAO INVALIDA! TENTE NOVAMENTE" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
        else if (option<minOption || option>maxOption || option != 0 || !isspace(cin.peek()))
        {
            validOption = false;
            cout << "OPCAO INVALIDA! TENTE NOVAMENTE. " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else
        {
            validOption = true;
            cin.ignore(1000, '\n');
        }
    } while (!validOption);
}

menu::menu() {

    companhia.loadData("avioes.txt", "voos.txt", "bilhetes.txt"); //TODO: IMPLEMENTAR COMPANHIA.LOADFILE()
    lastMenu.push(0);   // '0' representa o menu inicial/principal

    cout << "BEM-VINDO A COMPANHIA DE VIAGENS " << endl;
    cout << "1. Pesquisar Voos " << endl;
    cout << "2. Realizar Check-in" << endl;
    cout << "3. As minhas Reservas" << endl;
    cout << "4. Transportes: Locais e Horários " << endl;
    cout << "5. Companhia: Informacoes Privadas  " << endl;
    cout << "0. Sair." << endl;
    cout << endl;
    cout << "Escolha uma opcao: ";
    readOption( 0, 5);

    if (option){
        lastMenu.push(0);
        processOption();
    }
    else
    {
        cout << "Volte Sempre.";
        exit (1);
    }
}

void menu::processOption() {
    switch (option){
        case 0: menu(); break;
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
        case 11: menu11(); break;
        case 12: menu12(); break;
        case 13: menu13(); break;
        case 14: menu14(); break;
        case 15: menu15(); break;
        case 16: menu16(); break;
        case 17: menu17(); break;
        case 18: menu18(); break;
        case 19: menu19(); break;
        case 20: menu20(); break;
        case 21: menu21(); break;
        case 22: menu22(); break;
        case 23: menu23(); break;
    }
}

void menu::menu1() {
    //TODO: ENCONTRAR UMA FORMA MELHOR DE ESCREVER ESTAS OPCOES
    cout << "6. Imprimir todos os voos" << endl;
    cout << "7. Visualizar voos com partida numa determinada cidade" << endl;
    cout << "8. Visualizar voos com chegada numa determinada cidade" << endl;
    cout << "9. Visualizar voos com entre duas cidades selecionadas" << endl;
    cout << "10. Visualizar voos realizados em determinadas datas" << endl;
    cout << "0. Voltar a pagina anterior" << endl;
    cout << endl;
    cout << "ESCOLHA UMA OPCAO : " << endl;
    readOption(6,10);

    if (option)
    {
        lastMenu.push(1);
    }
    else{
        option = lastMenu.top();
        lastMenu.pop();
    }
    processOption();
}

void menu::menu2() {
    unsigned numeroBilhete;
    cout << "Introduza o numero do seu bilhete de viagem:  (Clique 0 para voltar a pagina anterior)" << endl;
    cin >> numeroBilhete;
    if (numeroBilhete != 0){
        //companhia.realizarCheckIn(numeroBilhete);     // TODO: MUDAR CHECK-IN BILHETE PARA ESTE FORMATO
        cout << "Check-in feito com Sucesso!" << endl;
    }
    else{
        option = lastMenu.top();
        lastMenu.pop();
    }
    processOption();
}

void menu::menu3() {
    unsigned idPassageiro;

    cout << "Insira o seu número de identificação: " ;
    cin >> idPassageiro;

   // if (idPassageiro != 0)
   //companhia.showBilhetesFromPassageiro(idPassageiro); // TODO: Mudar showBilhetesFromPassageiro para este formato



}

void menu::menu4() {
    string nomeAeroporto;
    cout << "Insira o nome do aeroporto: " << endl;
    getline (cin, nomeAeroporto);
    cout << "11. Visualizar dados de todos os locais de transporte" << endl;
    cout << "12. Visualizar dados de todos os locais de Metro" << endl;
    cout << "13. Visualizar dados de todos os locais de Comboio" << endl;
    cout << "14. Visualizar dados de todos os locais de Autocarro" << endl;
    cout << "15. Visualizar dados do local de transporte mais proximo" << endl;
    cout << "16. Visualizar dados do local de transporte de Metro mais proximo" << endl;
    cout << "17. Visualizar dados do local de transporte de Comboio mais proximo" << endl;
    cout << "18. Visualizar dados do local de transporte de Autocarro mais proximo" << endl;
    cout << "0. Voltar a pagina anterior." << endl;
    cout << "\n Escolha uma opcao: ";
    readOption(11, 19);

    if (option){
        lastMenu.push(4);
    }
    else{
        option=lastMenu.top();
        lastMenu.pop();
    }
    processOption();

    //TODO

}

void menu::menu5() {

}

void menu::menu6() {
    companhia.showVoos();
}

void menu::menu7() {
    string cidade;
    unsigned dia, mes, ano;
    bool inserirData;

    cout << "Insira a ciade de partida: ";
    getline(cin, cidade);
    cout << "Insira o dia, o mes e o ano separados por espaço: " << endl;
    cout << "Nota: Pode colocar '0 0 0' caso nao queira indicar uma data em especifico " << endl;
    cin >> dia >> mes >> ano;
    Data d1 (dia, mes, ano);

    companhia.showVoosPartida(cidade, d1);
}

void menu::menu8() {
    string cidade;
    unsigned dia, mes, ano;

    cout << "Insira a ciade de chegada: ";
    getline(cin, cidade);
    cout << "Insira o dia, o mes e o ano separados por espaço: " << endl;
    cout << "Nota: Pode colocar '0 0 0' caso nao queira indicar uma data em especifico " << endl;
    cin >> dia >> mes >> ano;
    Data d1 (dia, mes, ano);

    companhia.showVoosChegada(cidade, d1);
}

void menu::menu9() {
    string origem, destino;
    unsigned dPartida, mPartida, aPartida, dRegresso, mRegresso, aRegresso;

    cout << "Origem: " << endl;
    getline(cin,origem);

    cout << "Destino: " << endl;
    getline (cin, destino);

    cout << "Data de ida: ";
    cin >> dPartida >> mPartida >> aPartida ;
    Data partida(dPartida, mPartida, aPartida);

    cout <<  "Data de regresso: ";
    cin >> dRegresso >> mRegresso >> aRegresso;
    Data regresso (dRegresso, mRegresso, aRegresso);

    companhia.showVoosCidades(origem, destino, partida, regresso);

}

void menu::menu10() {

}

void menu::menu11() {

}

void menu::menu12() {

}

void menu::menu13() {

}

void menu::menu14() {

}

void menu::menu15() {

}

void menu::menu16() {

}

void menu::menu17() {

}

void menu::menu18() {

}

void menu::menu19() {

}

void menu::menu20() {

}

void menu::menu21() {

}

void menu::menu22() {

}

void menu::menu23() {

}




