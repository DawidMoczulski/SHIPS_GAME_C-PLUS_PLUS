#include <iostream>
#include "Statek.h"
#include "Plansza.h"
#include "Menedzer.h"
#include "Player.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

const unsigned int Player::listaOkretow[5] = { 5, 4, 3, 3, 2 };

Player::Player(int rozmiarPlanszy) {


    this->wynik = 0;
    this->rozmiarPlanszy = rozmiarPlanszy;
    this->iloscStatkow = 5;
    this->okrety = new Statek * [5];
    this->strzaly = new Plansza(rozmiarPlanszy);
    this->plOkrety = new Plansza(rozmiarPlanszy);
}

Player::~Player() {

    delete[] okrety;
}

const Plansza& Player::GetPlOkrety() {
    return *plOkrety;
}

const Plansza& Player::GetStrzaly() {
    return *strzaly;
}

int Player::getDlugoscStatku(int s) {
    return listaOkretow[s];
}

void Player::RozstawOkrety() {}


bool Player::IsAlive() {
    return this->iloscStatkow > 0;
}

void Player::hitPoints() {
    cout << "Pozostalo Statkow: " << this->iloscStatkow << endl;
}

bool Player::Trafienie(int x, int y) {
    bool hit = this->plOkrety->Trafienie(x, y);
    if (hit)
        //cout << "ZATOPILES WROGI OKRET!" << endl;
        this->damageShip(x, y);
    return hit;
}

void Player::markShot(int x, int y, bool hit) {

    this->strzaly->zaznaczStrzal(x, y, hit);
}

void Player::damageShip(int x, int y) {
    for (int i = 0; i < 5; i++) {
        bool hit = this->okrety[i]->isAt(x, y);
        if (hit && this->okrety[i]->damage()) {
            this->iloscStatkow--;
            break;
        }
    }
}

bool Player::ENDGAME() {
    bool shipExist = this->plOkrety->isAlive();
    if (shipExist == true) {
        return true;
    }
    return false;
}







