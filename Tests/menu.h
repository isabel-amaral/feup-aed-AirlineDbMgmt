#ifndef _MENU_H
#define _MENU_H

#include <iostream>
#include "CompanhiaAerea.h"
using namespace std;

class Menu {
private:
    CompanhiaAerea companhia;
    stack<int> lastMenu;
    int option;
public:
    Menu();
    void readOption(const unsigned& minOption, const unsigned& maxOption);
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
    void menu19();
    void menu20();
    void menu21();
    void menu22();
    void menu23();
    void menu24();
    void menu25();
    void menuCompra();
};

#endif //_MENU_H