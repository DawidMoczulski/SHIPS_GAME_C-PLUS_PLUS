#include <iostream>
#include <stdlib.h>
#include "Statek.h"

Statek::Statek(int rozmiar) {

    this->polozenieX = 0;
    this->polozenieY = 0;
    this->rozmiar = rozmiar;
    this->zycie = rozmiar;
    this->kierunek = false;
}

Statek::Statek(int x, int y, int size, bool vertical) {
    this->polozenieX = x;
    this->polozenieY = y;
    this->kierunek = vertical;
    this->rozmiar = size;
    this->zycie = size;
}


int Statek::getRozmiar() {
    return rozmiar;
}

int Statek::getPolozenieX() {
    return polozenieX;
}

int Statek::getPolozenieY() {
    return polozenieY;
}

int Statek::getZycie() {
    return zycie;
}

int Statek::getKierunek() {
    return kierunek;
}

void Statek::setRozmiar(int nowyRozmiar) {
    rozmiar = nowyRozmiar;
}

void Statek::setPosition(int x, int y) {
    this->polozenieX = x;
    this->polozenieY = y;
}

void Statek::setPolozenieX(int nowePolozenieX) {
    polozenieX = nowePolozenieX;
}

void Statek::setPolozenieY(int nowePolozenieY) {
    polozenieY = nowePolozenieY;
}

void Statek::setZycie(int noweZycie) {
    zycie = noweZycie;
}

void Statek::setKierunek(bool nowyKierunek) {
    kierunek = nowyKierunek;
}


bool Statek::damage() {
    this->zycie--;
    return this->zycie <= 0;
}


bool Statek::isAt(int x, int y) {
    if (this->polozenieX == x && this->polozenieY == y)
        return true;

    if (kierunek)
        if (this->polozenieX == x && y >= this->polozenieY && y < (this->polozenieY + this->rozmiar))
            return true;

        else
            if (this->polozenieY == y && x >= this->polozenieX && x < (this->polozenieX + this->rozmiar))
                return true;

    return false;
}


