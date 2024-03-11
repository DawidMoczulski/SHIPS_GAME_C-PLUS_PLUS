#pragma once
#include <stdio.h>
#include <string>
#include "Player.h"

class Human : public Player
{
public:
	Human(int);
	~Human();
	void draw();
	void RozstawOkrety();
	void target(int&, int&);
};

