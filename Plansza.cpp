#include<iostream>
#include "Statek.h"
#include "Plansza.h"
#include "Menedzer.h"
#include "Player.h"
#include <vector>
#include<stdlib.h>

Plansza::Plansza() {

	/*pl = new pole * [MapSize];
	for (int i = 0; i < MapSize; i++) {
		pl[i] = new pole[MapSize];
	}*/
    this->MapSize = 0;
    this->pl = 0;
}


Plansza::Plansza(int s)
{
	MapSize = s;
	pl = new pole * [s];
	for (int i = 0; i < s; i++) {
		pl[i] = new pole[s];
	}
}

Plansza::~Plansza() {

	for (int i = 0; i < MapSize; i++) {
		delete[] pl[i];
	}
	delete[] pl;
}

int Plansza::getMapSize() {
	return MapSize;
}

void Plansza::Wyswietl() {
	cout << "  ";
    for (int i = 0; i < MapSize; i++) {
        cout << (i + 1);
        if (i < 9) cout << " ";
    }
	cout << endl;

	for (int i = 0; i < MapSize; i++) {
		cout << (char)(i + 'A') << " ";
		for (int j = 0; j < MapSize; j++)
			cout << (char)(pl[j][i]) << " ";
		cout << endl;
	}
	cout << endl;

}


void Plansza::WyczyszPlansze() {

	for (int i = 0; i < MapSize; i++) {
		for (int j = 0; j < MapSize; j++) {
			pl[i][j] = PUSTY;
		}
	}
}

void Plansza::UmiescStatek(int x, int y, int s, bool v) {
	for (int i = 0; i < s; i++) {
		this->pl[x][y] = ZAJETE;
		v ? y++ : x++;
	}
}


bool Plansza::KoniecGry() {

	for (int i = 0; i < MapSize; i++) {
		for (int j = 0; j < MapSize; j++) {
			if (pl[i][j] == ZAJETE) {
				return false;
			}
		}
	}
	return true;
}

bool Plansza::Strzal(int x, int y) {

	if (pl[x][y] == PUSTY) { return true; }
	return false;
}


bool Plansza::validateTarget(int x, int y) {
    return !(
        // out of bounds
        x < 0
        || y < 0
        || x >= this->MapSize
        || y >= this->MapSize
        // move repetition
        || this->pl[x][y] == TRAFIONY
        || this->pl[x][y] == PUDLO
        );
}

bool Plansza::Trafienie(int x, int y) {
    bool hit = pl[x][y] == ZAJETE;
    pl[x][y] = hit ? TRAFIONY : PUDLO;
    return hit;
}

void Plansza::zaznaczStrzal(int x, int y, bool hit) {
    pl[x][y] = hit ? TRAFIONY : PUDLO;
}

bool Plansza::isAlive() {
    for (int i = 0; i < MapSize; i++) {
        for (int j = 0; j < MapSize; j++) {
            if ( pl[i][j] == ZAJETE) {
                return true;
            }
        }
    }
    return false;
}

bool Plansza::CheckPosition(int x, int y, int s, bool v) {
	if (x < 0 || y < 0)
		return false;

    if (v == false) { // jesli ustawiamy statek poziomo
        if ((x + s - 1) > (MapSize - 1) || y > (MapSize - 1) ){
            cout << "Statek wychodzi poza plansze!" << endl;
            return false;
        }
    }
    else {  // jesli ustawiamy statek pionowo
        if ((y + s - 1) > (MapSize - 1) || x > (MapSize - 1)) {
            cout << "Statek wychodzi poza plansze!" << endl;
            return false;
        }
    }

            for (int j = 0; j < s; j++) {
                if (v == false) {  // poziomo
                    if (pl[x][y] == ZAJETE) { return false; }
                    if (y == 0) {
                        if (x== 0) {
                            if (pl[x + 1][y] == ZAJETE) { return false; }
                            if (pl[x + 1][y + 1] == ZAJETE) { return false; }
                            if (pl[x][y + 1] == ZAJETE) { return false; }
                        }
                        else if (x == (MapSize - 1)) {
                            if (pl[x][y + 1] == ZAJETE) { return false; }
                            if (pl[x - 1][y] == ZAJETE) { return false; }
                            if (pl[x - 1][y + 1] == ZAJETE) { return false; }
                        }
                        else {
                            if (pl[x + 1][y] == ZAJETE) { return false; }
                            if (pl[x + 1][y + 1] == ZAJETE) { return false; }
                            if (pl[x][y + 1] == ZAJETE) { return false; }
                            if (pl[x - 1][y] == ZAJETE) { return false; }
                            if (pl[x - 1][y + 1] == ZAJETE) { return false; }
                        }
                    }
                    else if (y == (MapSize - 1)) {
                        if (x == 0) {
                            if (pl[x + 1][y] == ZAJETE) { return false; }
                            if (pl[x + 1][y - 1] == ZAJETE) { return false; }
                            if (pl[x][y - 1] == ZAJETE) { return false; }

                        }
                        else if (x == (MapSize - 1)) {
                            if (pl[x][y - 1] == ZAJETE) { return false; }
                            if (pl[x - 1][y] == ZAJETE) { return false; }
                            if (pl[x - 1][y - 1] == ZAJETE) { return false; }
                        }
                        else {
                            if (pl[x][y - 1] == ZAJETE) { return false; }
                            if (pl[x - 1][y] == ZAJETE) { return false; }
                            if (pl[x - 1][y - 1] == ZAJETE) { return false; }
                            if (pl[x + 1][y] == ZAJETE) { return false; }
                            if (pl[x + 1][y - 1] == ZAJETE) { return false; }
                        }
                    }
                    else {
                        if (x == 0) {
                            if (pl[x + 1][y] == ZAJETE) { return false; }
                            if (pl[x + 1][y + 1] == ZAJETE) { return false; }
                            if (pl[x + 1][y - 1] == ZAJETE) { return false; }
                            if (pl[x][y + 1] == ZAJETE) { return false; }
                            if (pl[x][y - 1] == ZAJETE) { return false; }
                        }
                        else if (x == (MapSize - 1)) {
                            if (pl[x - 1][y] == ZAJETE) { return false; }
                            if (pl[x - 1][y + 1] == ZAJETE) { return false; }
                            if (pl[x - 1][y - 1] == ZAJETE) { return false; }
                            if (pl[x][y + 1] == ZAJETE) { return false; }
                            if (pl[x][y - 1] == ZAJETE) { return false; }
                        }
                        else {
                            if (pl[x - 1][y] == ZAJETE) { return false; }
                            if (pl[x + 1][y] == ZAJETE) { return false; }
                            if (pl[x - 1][y + 1] == ZAJETE) { return false; }
                            if (pl[x - 1][y - 1] == ZAJETE) { return false; }
                            if (pl[x + 1][y + 1] == ZAJETE) { return false; }
                            if (pl[x + 1][y - 1] == ZAJETE) { return false; }
                            if (pl[x][y + 1] == ZAJETE) { return false; }
                            if (pl[x][y - 1] == ZAJETE) { return false; }

                        }
                        x++;
                    }

                }
                else {  // pionowo
                    if (pl[x][y] == ZAJETE) { return false; }

                    if (y == 0) {
                        if (x == 0) {
                            if (pl[x + 1][y] == ZAJETE) { return false; }
                            if (pl[x + 1][y + 1] == ZAJETE) { return false; }
                            if (pl[x][y + 1] == ZAJETE) { return false; }
                        }
                        else if (x == (MapSize - 1)) {
                            if (pl[x][y + 1] == ZAJETE) { return false; }
                            if (pl[x - 1][y] == ZAJETE) { return false; }
                            if (pl[x - 1][y + 1] == ZAJETE) { return false; }
                        }
                        else {
                            if (pl[x + 1][y] == ZAJETE) { return false; }
                            if (pl[x + 1][y] == ZAJETE) { return false; }
                            if (pl[x][y + 1] == ZAJETE) { return false; }
                            if (pl[x - 1][y] == ZAJETE) { return false; }
                            if (pl[x - 1][y + 1] == ZAJETE) { return false; }
                        }
                    }
                    else if (y == (MapSize - 1)) {
                        if (x == 0) {
                            if (pl[x + 1][y] == ZAJETE) { return false; }
                            if (pl[x + 1][y - 1] == ZAJETE) { return false; }
                            if (pl[x][y - 1] == ZAJETE) { return false; }

                        }
                        else if (x == (MapSize - 1)) {
                            if (pl[x][y - 1] == ZAJETE) { return false; }
                            if (pl[x - 1][y] == ZAJETE) { return false; }
                            if (pl[x - 1][y - 1] == ZAJETE) { return false; }
                        }
                        else {
                            if (pl[x][y - 1] == ZAJETE) { return false; }
                            if (pl[x - 1][y] == ZAJETE) { return false; }
                            if (pl[x - 1][y - 1] == ZAJETE) { return false; }
                            if (pl[x + 1][y] == ZAJETE) { return false; }
                            if (pl[x + 1][y - 1] == ZAJETE) { return false; }
                        }
                    }
                    else {
                        if (x == 0) {
                            if (pl[x + 1][y] == ZAJETE) { return false; }
                            if (pl[x + 1][y + 1] == ZAJETE) { return false; }
                            if (pl[x + 1][y - 1] == ZAJETE) { return false; }
                            if (pl[x][y + 1] == ZAJETE) { return false; }
                            if (pl[x][y - 1] == ZAJETE) { return false; }
                        }
                        else if (x == (MapSize - 1)) {
                            if (pl[x - 1][y] == ZAJETE) { return false; }
                            if (pl[x - 1][y + 1] == ZAJETE) { return false; }
                            if (pl[x - 1][y - 1] == ZAJETE) { return false; }
                            if (pl[x][y + 1] == ZAJETE) { return false; }
                            if (pl[x][y - 1] == ZAJETE) { return false; }
                        }
                        else {
                            if (pl[x - 1][y] == ZAJETE) { return false; }
                            if (pl[x + 1][y] == ZAJETE) { return false; }
                            if (pl[x - 1][y + 1] == ZAJETE) { return false; }
                            if (pl[x - 1][y - 1] == ZAJETE) { return false; }
                            if (pl[x + 1][y + 1] == ZAJETE) { return false; }
                            if (pl[x + 1][y - 1] == ZAJETE) { return false; }
                            if (pl[x][y + 1] == ZAJETE) { return false; }
                            if (pl[x][y - 1] == ZAJETE) { return false; }

                        }
                        y++;
                    }

                }

            }
            

	return true;
}


//bool Plansza::CheckPosition(int x, int y, int s, bool v) {
//	if (x < 0 || y < 0)
//		return false;
//
//	for (int i = 0; i < s; i++) {
//		if (x >= this->MapSize || y >= this->MapSize || this->pl[x][y] == ZAJETE)
//			return false;
//		v ? y++ : x++;
//	}
//
//	return true;
//}
