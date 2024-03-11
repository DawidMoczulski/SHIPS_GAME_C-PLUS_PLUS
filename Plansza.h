#pragma once

#include<iostream>
#include <vector>
#include<stdlib.h>


enum pole {

    PUSTY = '.',
    ZAJETE = '#',
    TRAFIONY = 'X',
    PUDLO = 'o'
};


class Plansza {

protected:
    pole** pl;
    int MapSize;

public:
    Plansza();
    Plansza(int);
    ~Plansza();
    int getMapSize();
    void Wyswietl();
    void WyczyszPlansze();
    void UmiescStatek(int, int, int, bool);
    bool KoniecGry();
    bool Strzal(int, int);
    bool CheckPosition(int,int,int,bool);
    bool validateTarget(int, int);
    bool Trafienie(int, int);
    void zaznaczStrzal(int, int, bool);
    bool isAlive();

    pole** GetPl() const {
        return pl;
    }


};