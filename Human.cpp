#include <iostream>
#include <string>
#include "Player.h"
#include "Human.h"
#include "Menedzer.h"

Human::Human(int rozmiarPlanszy) : Player(rozmiarPlanszy) {}

Human::~Human() {}

void Human::target(int& x, int& y) {
	bool valid = false;
	cout << "Wybierz koordynaty celu [row,col] (D4): ";
	do {
		string input;
		
		cin >> input;

		if (input.size() >= 2) {
			y = toupper(input[0]) - 'A';
			string numPart = input.substr(1);			
			x = stoi(numPart) - 1; 				
			valid = this->strzaly->validateTarget(x, y);						
		}
	} while (!valid);
}


void Human::RozstawOkrety() {
	this->plOkrety->WyczyszPlansze();
	for (int i = 0; i < Player::iloscStatkow; i++) {
		int x, y;
		int p = Player::listaOkretow[i];
		bool v, taken = false;
		string input = "";
		system("CLS");
		cout << "Umiesc swoje statki:" << endl;
		cout << "PAMIETAJ ZE STATKI NIE MOGA SIE DOTYKAC!" << endl;
		this->plOkrety->Wyswietl();
		cout << endl;
		cout << "Aktualny rozmiar statku: " << p << endl;
		cout << "Wybierz lokalizacje statku [wiersz,kolumna,pionowo?] (np.: A1v | B2): ";		
		do {
			cin >> input;
			if (input.size() >= 2) {
				v = tolower(input[input.size() - 1]) == 'v';
				y = toupper(input[0]) - 'A';
				x = stoi(input.substr(1)) - 1;
				taken = this->plOkrety->CheckPosition(x, y, p, v);
			}
			if (!taken) {
				cout << "Niewlasciwa pozycja! Podaj inna: ";
				continue;
			}		
		} while (!taken);

		this->plOkrety->UmiescStatek(x, y, p, v);
		this->okrety[i] = new Statek(p);
		this->okrety[i]->setPosition(x, y);
		this->okrety[i]->setKierunek(v);
	}
}


void Human::draw() {
	system("CLS");
	//this->hitPoints();
	cout << "Plansza twoich statkow:" << endl;
	this->plOkrety->Wyswietl();
	cout << "Plansza twoich strzalow:" << endl;
	this->strzaly->Wyswietl();
}

