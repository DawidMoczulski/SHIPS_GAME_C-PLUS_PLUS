#pragma once
#include <stdio.h>
#include <string>
#include "Player.h"

class AI : public Player
{
public:
	AI(int);
	~AI();
	void draw();
	void RozstawOkrety();
	void target(int&, int&);
};

