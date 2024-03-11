#include <iostream>
#include <string>
#include "Player.h"
#include "AI.h"
#include "MyExc.h"

AI::AI(int rozmiarPlanszy) : Player(rozmiarPlanszy) {}

AI::~AI()  {}



void AI::target(int& x, int& y) {
    bool valid = false;
    do {
        x = rand() % this->rozmiarPlanszy;
        y = rand() % this->rozmiarPlanszy;
        valid = this->strzaly->validateTarget(x, y);
    } while (!valid);
}


void AI::RozstawOkrety() {
	int x, y, s;
	bool v, valid = false;
	for (int t = 0; t < 5; t++) {
		for (int i = 0; i < iloscStatkow; i++) {
			s = this->listaOkretow[i];
			for (int j = 0; j < 5; j++) {
				y = rand() % this->plOkrety->getMapSize();
				x = rand() % this->plOkrety->getMapSize();
				v = rand() % 2;
				valid = this->plOkrety->CheckPosition(x, y, s, v);
				if (!valid) continue;
				this->plOkrety->UmiescStatek(x, y, s, v);
				this->okrety[i] = new Statek(x,y,s,v);
				break;
			}
			if (!valid) break;
		}
		if (valid) return;
		this->plOkrety->WyczyszPlansze();
	}
	throw MyExc("Failed to randomly fill the board!");
}




//void AI::RozstawOkrety() {
//    srand(time(NULL));
//    int MainrandomX,MainrandomY;
//    int licznik1 = 0, licznik2 = 0;
//    this->plOkrety->WyczyszPlansze();
//
//    
//
//    for (int i = 0; i < iloscStatkow; i++) {
//        this->okrety[i].setRozmiar(this->listaOkretow[i]);
//        this->okrety[i].setKierunek(rand() % 2);
//        if (this->plOkrety->getMapSize() < 6) {
//            cout << "Minimalny rozmiar planszy to 6!" << endl;
//            throw MyExc("Nie udalo sie rozmiescic statkow");
//        }
//        if (licznik1 > 4) {
//            throw MyExc("Nie udalo sie rozmiescic statkow");
//        }
//
//        if (licznik2 > 25) {
//            licznik1++;
//            licznik2 = 0;
//            break;
//        }
//
//        bool zajete = false;
//        do {
//            zajete = false;
//            
//
//            // Wybieramy losowe wspó³rzêdne startowe X i Y
//            this->okrety[i].setPolozenieX(rand() % (this->plOkrety->getMapSize() - this->okrety[i].getRozmiar()));
//            this->okrety[i].setPolozenieY(rand() % (this->plOkrety->getMapSize() - this->okrety[i].getRozmiar()));
//
//            // Zapamiêtujemy g³ówn¹ wspó³rzêdn¹ X
//            int randomX = this->okrety[i].getPolozenieX(); 
//            MainrandomX = randomX;
//            int randomY = this->okrety[i].getPolozenieY();
//            MainrandomY = randomY;
//
//                      
//            for (int j = 0; j < this->okrety[i].getRozmiar(); j++) {
//                if (this->okrety[i].getKierunek() == 0) {  // poziomo
//                    if (this->plOkrety->GetPl()[randomX][this->okrety[i].getPolozenieY()] == ZAJETE) { zajete = true; licznik2++; break; }
//                    if (randomY == 0) {
//                        if (randomX == 0) {
//                            if (this->plOkrety->GetPl()[randomX + 1][this->okrety[i].getPolozenieY()] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX + 1][this->okrety[i].getPolozenieY() + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX][this->okrety[i].getPolozenieY() + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                        }else if (randomX == (this->plOkrety->getMapSize() - 1)) {
//                            if (this->plOkrety->GetPl()[randomX][this->okrety[i].getPolozenieY() + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX - 1][this->okrety[i].getPolozenieY()] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX - 1][this->okrety[i].getPolozenieY() + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                        }
//                        else {
//                            if (this->plOkrety->GetPl()[randomX + 1][this->okrety[i].getPolozenieY()] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX + 1][this->okrety[i].getPolozenieY() + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX][this->okrety[i].getPolozenieY() + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX - 1][this->okrety[i].getPolozenieY()] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX - 1][this->okrety[i].getPolozenieY() + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                        } 
//                    }
//                    else if (randomY == (this->plOkrety->getMapSize() - 1)) {
//                        if (randomX == 0) {
//                            if (this->plOkrety->GetPl()[randomX + 1][this->okrety[i].getPolozenieY()] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX + 1][this->okrety[i].getPolozenieY() - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX][this->okrety[i].getPolozenieY() - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                             
//                        }
//                        else if (randomX == (this->plOkrety->getMapSize() - 1)) {
//                            if (this->plOkrety->GetPl()[randomX][this->okrety[i].getPolozenieY() - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX - 1][this->okrety[i].getPolozenieY()] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX - 1][this->okrety[i].getPolozenieY() - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                        }
//                        else {
//                            if (this->plOkrety->GetPl()[randomX][this->okrety[i].getPolozenieY() - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX - 1][this->okrety[i].getPolozenieY()] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX - 1][this->okrety[i].getPolozenieY() - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX + 1][this->okrety[i].getPolozenieY()] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX + 1][this->okrety[i].getPolozenieY() - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                        }
//                    }
//                    else {
//                        if (randomX == 0) {                          
//                            if (this->plOkrety->GetPl()[randomX + 1][this->okrety[i].getPolozenieY()] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX + 1][this->okrety[i].getPolozenieY() + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX + 1][this->okrety[i].getPolozenieY() - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX][this->okrety[i].getPolozenieY() + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX][this->okrety[i].getPolozenieY() - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                        }
//                        else if (randomX == (this->plOkrety->getMapSize() - 1)) {
//                            if (this->plOkrety->GetPl()[randomX - 1][this->okrety[i].getPolozenieY()] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX - 1][this->okrety[i].getPolozenieY() + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX - 1][this->okrety[i].getPolozenieY() - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX][this->okrety[i].getPolozenieY() + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX][this->okrety[i].getPolozenieY() - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                        }
//                        else {
//                            if (this->plOkrety->GetPl()[randomX - 1][this->okrety[i].getPolozenieY()] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX + 1][this->okrety[i].getPolozenieY()] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX - 1][this->okrety[i].getPolozenieY() + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX - 1][this->okrety[i].getPolozenieY() - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX + 1][this->okrety[i].getPolozenieY() + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX + 1][this->okrety[i].getPolozenieY() - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX][this->okrety[i].getPolozenieY() + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[randomX][this->okrety[i].getPolozenieY() - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//
//                        }
//                        randomX++;
//                    }
//                       
//                }
//                else {  // pionowo
//                    if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX()][randomY] == ZAJETE) { zajete = true; break; }
//
//                    if (randomY == 0) {
//                        if (randomX == 0) {
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() + 1][randomY] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() + 1][randomY + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX()][randomY + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                        }
//                        else if (randomX == (this->plOkrety->getMapSize() - 1)) {
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX()][randomY + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() - 1][randomY] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() - 1][randomY + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                        }
//                        else {
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() + 1][randomY] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() + 1][randomY] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX()][randomY + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() - 1][randomY] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() - 1][randomY + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                        }
//                    }
//                    else if (randomY == (this->plOkrety->getMapSize() - 1)) {
//                        if (randomX == 0) {
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() + 1][randomY] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() + 1][randomY - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX()][randomY - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//
//                        }
//                        else if (randomX == (this->plOkrety->getMapSize() - 1)) {
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX()][randomY - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() - 1][randomY] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() - 1][randomY - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                        }
//                        else {
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX()][randomY - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() - 1][randomY] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() - 1][randomY - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() + 1][randomY] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() + 1][randomY - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                        }
//                    }
//                    else {
//                        if (randomX == 0) {
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() + 1][randomY] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() + 1][randomY + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() + 1][randomY - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX()][randomY + 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX()][randomY - 1] == ZAJETE) { zajete = true; licznik2++; break; }
//                        }
//                        else if (randomX == (this->plOkrety->getMapSize() - 1)) {
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() - 1][randomY] == ZAJETE) { zajete = true; licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() - 1][randomY + 1] == ZAJETE) { zajete = true;  licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() - 1][randomY - 1] == ZAJETE) { zajete = true;  licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX()][randomY + 1] == ZAJETE) { zajete = true;  licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX()][randomY - 1] == ZAJETE) { zajete = true;  licznik2++; break; }
//                        }
//                        else {
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() - 1][randomY] == ZAJETE) { zajete = true;  licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() + 1][randomY] == ZAJETE) { zajete = true;  licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() - 1][randomY + 1] == ZAJETE) { zajete = true;  licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() - 1][randomY - 1] == ZAJETE) { zajete = true;  licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() + 1][randomY + 1] == ZAJETE) { zajete = true;  licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX() + 1][randomY - 1] == ZAJETE) { zajete = true;  licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX()][randomY + 1] == ZAJETE) { zajete = true;  licznik2++; break; }
//                            if (this->plOkrety->GetPl()[this->okrety[i].getPolozenieX()][randomY - 1] == ZAJETE) { zajete = true;  licznik2++; break; }
//
//                        }
//                        randomY++;
//                    }
//
//                }
//
//            }
//            if( (zajete == false) && (licznik2 < 25)){
//                // Wypisujemy informacje do debugowania
//                //cout << "Wspolrzedna X: " << this->okrety[i].getPolozenieX() << " Wspolrzedna Y: " << this->okrety[i].getPolozenieY() << endl;
//
//                // Umieszczamy statek na planszy
//                for (int k = 0; k < this->okrety[i].getRozmiar(); k++) {
//                    if (this->okrety[i].getKierunek() == 0) {  // poziomo
//                        //cout << "Debug: i=" << i << ", Mainrandom= " << MainrandomX << endl;
//                        this->plOkrety->GetPl()[MainrandomX][this->okrety[i].getPolozenieY()] = ZAJETE;
//                    }
//                    else {  // pionowo
//                        //cout << "Debug: i=" << i << ", Mainrandom= " << MainrandomY << endl;
//                        this->plOkrety->GetPl()[this->okrety[i].getPolozenieX()][MainrandomY] = ZAJETE;
//                    }
//                    MainrandomX++;
//                    MainrandomY++;
//                }
//            }
//
//        } while( (zajete) && (licznik2 <= 25));
//
//        
//    }
//}


void AI::draw() {}




