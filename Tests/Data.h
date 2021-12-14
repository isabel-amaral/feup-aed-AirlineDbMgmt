#ifndef _DATA_H
#define _DATA_H

class Data {
private:
    int dia;
    int mes;
    int ano;
public:
    int getDia() const;
    int getMes() const;
    int getAno() const;
    void setDia(const int &d);
    void setMes(const int &m);
    void setAno(const int &a);
    bool operator < (const Data &d2) const;
};

#endif //_DATA_H
