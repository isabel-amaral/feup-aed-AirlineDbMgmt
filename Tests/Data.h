#ifndef _DATA_H
#define _DATA_H

class Data {
private:
    unsigned dia;
    unsigned mes;
    unsigned ano;
public:
    Data(unsigned d, unsigned m, unsigned a);
    unsigned getDia() const;
    unsigned getMes() const;
    unsigned getAno() const;
    void setDia(unsigned d);
    void setMes(unsigned m);
    void setAno(unsigned a);
    bool operator < (const Data &d2) const;
};

#endif //_DATA_H
