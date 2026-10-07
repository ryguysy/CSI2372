/*Ex4.cpp : Ex4 a2 CSI2372A*/


#include <iostream>
using namespace std;

bool increasing(int a, int b) {
	//YOUR CODE
	return a < b;
}
bool decreasing(int a, int b) {
	//YOUR CODE
	return a > b;
}


void sorting(int tab[], int nb, bool (*compare)(int, int)) {
	//YOUR CODE
	int i, j, min, tmp;
	for (i = 0; i < nb; i++) {
		min = i;
		for (j = i + 1; j < nb; j++) {

			if (compare(tab[j], tab[min])) {
			min = j;
			}
		}

		tmp = tab[min];
		tab[min] = tab[i];
		tab[i] = tmp;
	}

}
 
int main()
{

	int a1[6] = { 12,234,-35,1234,0, 51 };
	int a2[10] = { 1,24,5,124, -14, 0, -55, 51, 10, 33 };

	cout << "My first array a1 sorted in ascending order:" << endl;
	//YOUR PIECE OF CODE
	sorting(a1, 6, increasing);
	for (int i = 0; i < 6; i++) {
		cout << a1[i] << " ";
	}
	cout << endl << endl;


	cout << "My second array a2 sorted in descending order:" << endl;
	//YOUR PIECE OF CODE
	sorting(a2, 10, decreasing);
	for (int i = 0; i < 10; i++) {
		cout << a2[i] << " ";
	}

	cout << endl << endl;

	return 0;
}