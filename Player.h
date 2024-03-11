#pragma once
#include<iostream>
#include<stdlib.h>
#include "Statek.h"
#include "Plansza.h"
#include <vector>

using namespace std;

class Player {

protected:

	Plansza *strzaly;       
	Plansza *plOkrety;     
	Statek **okrety;
	static const unsigned int listaOkretow[5];
	int iloscStatkow;
	int wynik;
	int rozmiarPlanszy;


public:

	Player(int);
	~Player();
	virtual void RozstawOkrety() = 0;
	virtual void draw() = 0;
	virtual void target(int&, int&) = 0;
	void markShot(int, int, bool);
	const Plansza& GetPlOkrety();  // Metoda dostêpu do plOkrety
	const Plansza& GetStrzaly();   // Metoda dostêpu do strzaly
	int getDlugoscStatku(int);
	bool IsAlive();
	void hitPoints();
	void damageShip(int, int);
	bool Trafienie(int, int);
	bool ENDGAME();
	


};