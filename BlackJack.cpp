/*Daniel Novotny
# Step by step

1) Cards are valued at 1 - 10.
2) The computer gives 2 random cards to you and 1 random cards to a "dealer"
3) The player can take another card(Hit) or keep with the cards they have(Stick).

## Hit
1) If another card is selected, the computer deals that random card.The players hand is then evaluated and it the total value of their hand is OVER 21 they loose immately.
2) If not over 21, the player can take another card of stay with the cards they have

## Stick
1) The dealer than gets a second random card.
2) If the total value of the dealers hand is 16 or less, the dealer HAS Hit.
3) If the total value of the dealers hand is 17 or greater, the dealer has to stay.

## Finish
1) When both the player and the dealer have Sticked... the hand of the player is compared to the dealer.Whomever has the larger hand wins.
2) Ties go to the dealer.
3) The game asks the player if they would like to play again.*/

#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//blackjack in c++ console

int main() {
	srand(time(NULL));
	bool contin = true;
	char exit = 'n';
	//hold cards for player and dealer. total is stored in 2, one is temp to generate new card
	int deal1 = 0;
	int deal2 = 0;
	int play1 = 0;
	int play2 = 0;

	//loops game 
	while (contin) {
		deal1 = rand() % 10 + 1;
		play1 = rand() % 10 + 1;
		play2 = rand() % 10 + 1;
		char playerin = 'r';
		cout << "shuffling!" << endl;
		deal2 = deal1;
		play2 = play1;

		
		
		cout << "Player has " << play1 << " and " << play2 << endl << "Dealer has " << deal1 << endl << "Would you like to (h)it or (s)tay?" << endl;
		play2 = play1 + play2;
		
		//playerin used to ask hit or stay
		while (playerin == 'r') {
			cin >> playerin;
			//hit - generates card, adds and outputs
			if ((playerin == 'h') || (playerin == 'H')) {
				play1 = rand() % 10 + 1;
				play2 = play2 + play1;
				cout << "player got a " << play1 << endl << "Player has " << play2 << endl;
				//player busts over 21
				if (play2 > 21) {
					cout << "You busted! Sorry, you lose.";
					break;
				}
				playerin = 'r';
			}
			//player stays 
			else if ((playerin == 's') || (playerin == 'S')) {
				cout << "Player stays" << endl << endl;
				//dealer must draw if less than or equal to 16
				while (deal2 <= 16) {
					deal1 = rand() % 10 + 1;
					deal2 = deal2 + deal1;
					cout << "Dealer draws another card, a " << deal1 << endl << "Dealer has " << deal2 << endl;
				}
				//dealer busts over 21
				if (deal2 > 21) {
					cout << "Dealer busts, Player wins. ";
					break;
				}
				cout << "Dealer stays at " << deal2 << endl;
				//tie
				if (deal2 == play2) {
					cout << "Tie, the house wins. ";
					break;
				}
				//dealer wins
				else if (deal2 > play2) {
					cout << "The dealer wins";
					break;
				}
				//player wins
				else if (deal2 < play2) {
					cout << "player wins!";
					break;
				}
				//debug code 
				else {
					cout << "error code 1. Please restart.";
				}
			}
			//player inputs anthing other than h or s
			else {
				cout << "Enter 'h' to hit, or 's' to stay" << endl;
				playerin = 'r';
			}

		}
		
		
		
		//asks user if they want to continue and quits if not
		cout <<endl << endl << "Press 'y' to play again?" << endl;
		cin >> exit;
		if ((exit != 'y') && (exit != 'Y')) {
			contin = false;
		}

	}

}

