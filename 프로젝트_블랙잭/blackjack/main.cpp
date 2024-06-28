#include <iostream>
#include "player.h"
using namespace std;
int main() {
	Dealer dealer = Dealer(10000, 8, 8);
	dealer.playGame();
	dealer.printResult();
	return 0;
}