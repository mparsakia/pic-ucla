/*
	Description: Blackjack terminal game.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

string suitString(int suit) 
{
	if (suit == 1)
	{
		return "Hearts";
	}
	if (suit == 2)
	{
		return "Diamonds";
	}
	if (suit == 3)
	{
		return "Spades";
	}
	if (suit == 4)
	{
		return "Clubs";
	}
}

string cardString(int rank) 
{
	if (rank == 1)
	{
		return "Ace";
	}
	if (rank == 2)
	{
		return "Two";
	}
	if (rank == 3)
	{
		return "Three";
	}
	if (rank == 4)
	{
		return "Four";
	}
	if (rank == 5)
	{
		return "Five";
	}
	if (rank == 6)
	{
		return "Six";
	}
	if (rank == 7)
	{
		return "Seven";
	}
	if (rank == 8)
	{
		return "Eight";
	}
	if (rank == 9)
	{
		return "Nine";
	}
	if (rank == 10)
	{
		return "Ten";
	}
	if (rank == 11)
	{
		return "Jack";
	}
	if (rank == 12)
	{
		return "Queen";
	}
	if (rank == 13)
	{
		return "King";
	}
}

int draw_card (string &card , int psum)
{
	int value;
	int rank = rand() % (13 - 1 + 1) + 1; 
	value = rank; 
		if (rank == 1) 
		{ 
			if (psum >= 10) { value = 1; } else { value = 11; }
		}
		if (rank == 11) { value = 10; }
		if (rank == 12) { value = 10; }
		if (rank == 13) { value = 10; }

	int suit = rand() % (4 - 1 + 1) + 1; 

	card = cardString(rank) + " of " + suitString(suit);

	return value; 
}

int draw_card_dealer(string &card, int dsum)
{
	int value;
	int rank = rand() % (13 - 1 + 1) + 1; 
	value = rank; 
	if (rank == 1) 
	{
		if (dsum >= 10) { value = 1; } else { value = 11; }
	}
	if (rank == 11) { value = 10; }
	if (rank == 12) { value = 10; }
	if (rank == 13) { value = 10; }

	int suit = rand() % (4 - 1 + 1) + 1; 

	card = cardString(rank) + " of " + suitString(suit);

	return value;
}


int main()
{	
	srand((int)(time(0)));		
	string card;				
	string hitme;				
	int money = 100;			
	int bet = 0;				
	int psum = 0;				
	int dsum = 0;				
	int rank = 0;				
	int suit = 0;
	bool game = true;			

	while (game) 
	{
		cout << "You have $" << money << ", enter your bet: ";
		cin >> bet;			
		cout << endl;		
		while (bet > money) 
		{
			cout << "You only have $" << money <<", please enter a valid bet amount: ";
			cin >> bet;
			cout << endl;
		}
		cout << "--- Your Turn ---" << endl; 
		cout << "You draw two cards:" << endl;
		for (int d = 0; d < 2; d++) 
		{
			psum = draw_card(card, psum) + psum; 
			cout << "\t" << card << endl; 
			
		}
		if (psum == 21)
		{
			cout << ">>> YOU GOT BLACKJACK! (21) <<<" << endl; 
			hitme = "n";
		}
		if(psum < 21)	
		{
			cout << "Your total is: " << psum << endl;
			cout << "Do you want another card? (y/n): ";
			cin >> hitme;
			while (hitme == "y" || hitme == "y") 
			{
				cout << endl;
				psum = draw_card(card, psum) + psum;
				cout << "You draw:" << endl;
				cout << "\t" << card << endl;
				cout << "Your new total is: " << psum << endl;
				if (psum == 21)
				{
					cout << ">>> YOU GOT BLACKJACK! (21) <<<" << endl; 
					hitme = "n";
				}
				if (psum > 21) 
				{
					cout << "YOU BUSTED!" << endl;
					hitme = "n";
				}
				if(psum<21)
				{
				cout << "Do you want another card? (y/n): ";
				cin >> hitme;
				cout << endl;
				}
			}
		
		}

		cout << endl; 
		cout << "--- Dealers Turn ---" << endl;	
		
		cout << "The dealer draws two cards:" << endl; 
		for (int d = 0; d < 2; d++)		
		{
			dsum = draw_card_dealer(card, dsum) + dsum;
			cout << "\t" << card << endl;
		}
		cout << "Dealers total is: " << dsum << endl << endl;
		while (dsum < 16)
		{
			cout << "The dealer draws another card: " << endl;
			dsum = draw_card_dealer(card, dsum) + dsum;
			cout << "\t" << card << endl;
			cout << "Dealers updated total is: " << dsum << endl << endl;
		}
		
		
		cout << "----- Results -----" << endl;
		if (psum<=21 && dsum<=21)
		{
			if (psum == dsum) 
			{
				cout << "Tie! No money is exchanged." << endl << endl;
				cout << "------------New Round------------" << endl;
				dsum = 0; 
				psum = 0;
			}
			if (psum > dsum) 
			{
				money = bet + money;
				cout << "You win! You now have $" << money << "." << endl << endl;
				cout << "------------New Round------------" << endl;
				dsum = 0; 
				psum = 0;
			}
			if (dsum > psum)
			{
				money = money - bet;
				cout << "You lose! You now have $" << money << "." << endl << endl;
				cout << "------------New Round------------" << endl;
				dsum = 0; 
				psum = 0;
			}
		}
		if (dsum>21 && psum>21) 
		{
			money = money - bet;
			cout << "You lose! You now have $" << money << "." << endl << endl;
			cout << "------------New Round------------" << endl;
			dsum = 0; 
			psum = 0;
		}
		if (psum<=21) 
		{
			if(dsum>=21) 
			{
			money = bet + money;
			cout << "You win! You now have $" << money << "." << endl << endl;
			cout << "------------New Round------------" << endl;
			dsum = 0; 
			psum = 0;
			}
		}
		if (psum >= 21) 
		{
			if (dsum <= 21)
			{
				money = money - bet;
				cout << "You lose! You now have $" << money << "." << endl << endl;
				cout << "------------New Round------------" << endl;
				dsum = 0;
				psum = 0;
			}
		}

		
		if (money <= 0)
		{
			game = false;
			cout << "You lost all your money! Game over!" << endl;
		}
		if (money >= 1000)
		{
			game = false;
			cout << "You're very lucky. It's time to leave with your money. Game over." << endl;
		}
	}

	system("pause");
	return 0;
}