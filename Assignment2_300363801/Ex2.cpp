/*Ex2.cpp : Ex2 a2 CSI2372A*/

#include "Ex2.h"

int main() {
	int myArray[sizeArray] = { 2,4,88,20,3,55,87,134,2,5 };

	cout << "Displaying the unsorted array :" << endl;
	for (int i = 0; i < sizeArray; i++) {
		cout << myArray[i] << " ";
	}
	cout <<  endl << endl;
	sort(myArray, sizeArray);
	cout << "Displaying the sorted array :" << endl;
	for (int i = 0; i < sizeArray; i++) {
		cout << myArray[i] << " ";
	}
	cout << endl;
}

void sort(int a[], int size)
{
	//YOUR CODE HERE
    for (int i = 0; i < size - 1; i++){

        for (int j = i + 1; j < size; j++){

            if (a[i] > a[j]) {

                //hold a[j],
                //shift every element at and after a[i] back
                //place a[j] at a[i]
                int temp = a[j];
                for (int k = j; k > i; k--){
                    a[k] = a[k - 1];
                }
                a[i] = temp;
                

            }

        }

    }
}