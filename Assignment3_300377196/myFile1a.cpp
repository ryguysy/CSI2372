/*Ex1a - a3 CSI2372A*/
// builds a deck of 32 cards (4 colors x 8 faces) and prints it

#include <iostream>
using namespace std;

enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };

struct Card{
	Color color;
	Face face;
};

int main(){
	Card game[32];
	//YOUR CODE HERE
 
	// go through every color and face so each card is different
	int i = 0;
	for (int c = 0; c < 4; c++) {
		for (int f = 0; f < 8; f++) {
			game[i].color = (Color)c;
			game[i].face = (Face)f;
			i++;
		}
	}
 
	// print the deck to check it
	for (int k = 0; k < 32; k++) {
		cout << "Card " << k << ": color " << game[k].color << ", face " << game[k].face << endl;
	}
 
	return 0;
}

