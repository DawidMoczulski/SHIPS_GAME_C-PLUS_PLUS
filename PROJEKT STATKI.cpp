#include<iostream>
#include<stdlib.h>
#include "Statek.h"
#include "Plansza.h"
#include "Menedzer.h"
#include "Player.h"
#include "Human.h"
#include "AI.h"
#include "MyExc.h"
#include <vector>

using namespace std;


int main() {

    Menedzer GAME = Menedzer();
    GAME.start();

    return 0;
}



