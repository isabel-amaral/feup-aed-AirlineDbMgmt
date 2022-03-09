#ifndef _LOADDATA_H
#define _LOADDATA_H

#include "CompanhiaAerea.h"

class LoadData {
public:
    LoadData(CompanhiaAerea& ca);
    void loadAvioes(CompanhiaAerea& ca);
    void loadServicos(CompanhiaAerea& ca);
    void loadAeroportos(CompanhiaAerea& ca);
    void loadLocaisTransporte(CompanhiaAerea& ca);
    void loadVoosAndBilhetes(CompanhiaAerea& ca);
    void loadBagagens(CompanhiaAerea& ca);
    void loadTransportadorBagagem(CompanhiaAerea& ca);
    void loadExcessoPeso(CompanhiaAerea& ca);
};

#endif //_LOADDATA_H
