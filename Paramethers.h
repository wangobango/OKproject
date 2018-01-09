//
// Created by ramon on 1/8/18.
//

#ifndef OKPROJECT_PARAMETHERS_H
#define OKPROJECT_PARAMETHERS_H

//TODO : zrobic klase z parametrami zeby mozna bylo latwo manipulowac kodem
class Paramethers {
public:
    const static int ilosc_iteracji = 500;
    const static int rozmiar_populacji = 50;
    const static int ilosc_zadan = 50;
    const static int ilosc_maintancow = 10;
    const static int maxczas_operacji = 150;
    const static int maxczas_startu = ilosc_zadan*maxczas_operacji;
    const static int p_mutacji = 6; // ex . 6= 6%
    const static int procent_krzyzowania = 10;// ex. 6 = 6%
    const static int zakres_mutacji = maxczas_startu;
    Paramethers() = default;

};


#endif //OKPROJECT_PARAMETHERS_H
