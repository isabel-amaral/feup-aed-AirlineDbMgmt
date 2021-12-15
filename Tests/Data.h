#ifndef _DATA_H
#define _DATA_H

#include <string>
using namespace std;

class Data {
private:
    unsigned dia;
    unsigned mes;
    unsigned ano;
    string data;
    void getStringRepresentation();
public:
    Data();
    Data(unsigned d, unsigned m, unsigned a);
    unsigned getDia() const;
    unsigned getMes() const;
    unsigned getAno() const;
    string getData() const;
    void setDia(unsigned d);
    void setMes(unsigned m);
    void setAno(unsigned a);
    bool operator< (const Data &d) const;
    bool operator== (const Data& d) const;
};

#endif //_DATA_H
