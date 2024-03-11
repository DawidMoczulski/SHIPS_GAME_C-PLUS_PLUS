#pragma once
#include<iostream>
#include <vector>
#include<stdlib.h>

class Statek {

protected:

    int rozmiar;
    int polozenieX;
    int polozenieY; 
    int zycie;
    bool kierunek;

public:

    Statek(int);
    Statek(int, int, int, bool);
    int getRozmiar();
    int getPolozenieX();
    int getPolozenieY();
    int getZycie();
    int getKierunek();
    void setPosition(int, int);
    void setRozmiar(int);
    void setPolozenieX(int);
    void setPolozenieY(int);
    void setZycie(int);
    void setKierunek(bool);
    bool isAt(int, int);
    bool damage();

};