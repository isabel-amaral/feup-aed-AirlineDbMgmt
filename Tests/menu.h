#ifndef AIRLINEDATABASEMANAGEMENT_MENU_H
#define AIRLINEDATABASEMANAGEMENT_MENU_H
#include <iostream>
#include "CompanhiaAerea.h"
using namespace std;

class menu {
private:
    CompanhiaAerea companhia;
    stack <int> lastMenu;
    int option;
public:
    void readOption( const int &minOption, const int &maxOption);
    menu();
    void processOption();
    void menu1();
    void menu2();
    void menu3();
    void menu4();
    void menu5();
    void menu6();
    void menu7();
    void menu8();
    void menu9();
    void menu10();
    void menu11();
    void menu12();
    void menu13();
    void menu14();
    void menu15();
    void menu16();
    void menu17();
    void menu18();
    void menu19();
    void menu20();
    void menu21();
    void menu22();
    void menu23();
    void menu24();
    void menu25();
};



#endif //AIRLINEDATABASEMANAGEMENT_MENU_H
