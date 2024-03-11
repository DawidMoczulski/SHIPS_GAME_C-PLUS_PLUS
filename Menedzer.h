#pragma once
#include<iostream>
#include<stdlib.h>
#include <vector>
#include "Player.h"
#include "MyExc.h"


using namespace std;

class Menedzer {

	vector<Player*> players;
	void end(int);

public:
	Menedzer();
	void start();

};
