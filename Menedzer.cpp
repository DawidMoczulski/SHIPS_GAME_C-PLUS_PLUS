#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Menedzer.h"
#include "Player.h"
#include "Human.h"
#include "AI.h"

Menedzer::Menedzer() {
	srand(time(NULL));
	cout << endl;
	cout << "             ----     GRA W STATKI     ----" << endl;
	cout << "Rozstaw swoje statki i zniszcz wszystkie piec okretow przeciwnika!" << endl;
	cout << endl;
	cout << "Minimalny rozmiar planszy: 7x7.";
	cout << endl;
	cout << "Maksymalny rozmiar planszy: 26x26.";
	cout << endl;

	cout << "Rozmiar planszy: ";
	int rozmiar;
	do {
		cin >> rozmiar;
		if (rozmiar < 7 || rozmiar > 26) {
			cout << "Wybierz rozmiar od 7 do 26." << endl;
		}
	} while (rozmiar < 7 || rozmiar > 26);

	this->players.push_back(new Human(rozmiar));
	this->players.push_back(new AI(rozmiar));
	
	try {
		this->players[0]->RozstawOkrety();
		this->players[1]->RozstawOkrety();
		return;

		/*do {
		} while ();*/

	}
	catch (MyExc& x) {
		cout << x.what() << endl;
	}
	catch (...) {
		cout << "Wystapil nieoczekiwany wyjatek." << endl;
	}
	exit(1);
}

void Menedzer::start() {

	int wygrany;
	int hitLoop = 0;
	bool gameProcess = true;
	while (gameProcess) {
		for (int i = 0; i < players.size(); i++) {
			
			this->players[i]->draw();

			int x, y;
			do {
				hitLoop = 0;
				this->players[i]->target(x, y);
				bool hit = this->players[(i + 1) % 2]->Trafienie(x, y);
				if (hit == true) {
					hitLoop = 1;
				}
				this->players[i]->markShot(x, y, hit);
				this->players[i]->draw();

			}while(hitLoop == 1);
			
			if (this->players[i]->ENDGAME() == false) {
				gameProcess = false;
				wygrany = (i + 1) % 2;
				break;
			}			
		}

	}
	end(wygrany);

}

void Menedzer::end(int winner) {
	cout << "==============================" << endl;
	cout << "KONIEC GRY" << endl;
	if (winner == 0)
		cout << "WYGRALES!" << endl;
	else
		cout << "Niestety przegrales:(" << endl;
}

