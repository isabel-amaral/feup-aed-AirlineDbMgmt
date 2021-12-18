#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <iostream>
#include "stack"
using namespace std;

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    std::cout << "Airline Database Management" << std::endl;
    return RUN_ALL_TESTS();
}

/*
stack <int> lastMenu;

void readOption(int &option, const int &minOption, const int &maxOption){
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
        else if (option<minOption || option>maxOption || !isspace(cin.peek()))
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



void menu1(){

}

void menu2(){

}
void menu3(){

}

void menu4(){

}

void menu5(){

}


int main(){

    int option;

    cout << "BEM-VINDO A COMPANHIA DE VIAGENS " << endl;
    cout << "1. Pesquisar Voos " << endl;
    cout << "2. Realizar Check-in" << endl;
    cout << "3. Adicionar Voo " << endl;
    cout << "4. Pesquisar locais de Transporte" << endl;
    cout << "0. Sair." << endl;
    cout << endl;
    cout << "Escolha uma opcao: ";
    readOption(option, 0, 5);

    switch (option){
        case 1:
            menu1();
            lastMenu.push(1);
            break;

        case 2:
            menu2();
            lastMenu.push(2);
            break;

        case 3:
            menu3();
            lastMenu.push(3);
            break;

        case 4:
            menu4();
            lastMenu.push(4);
            break;

        case 5:
            menu5();
            lastMenu.push(5);
            break;

        case 0:
            cout << "Volte Sempre.";
            break;
    }

    return 0;

}*/
