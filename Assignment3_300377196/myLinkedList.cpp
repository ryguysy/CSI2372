/*Ex2 - a3 CSI2372A*/
// linked list of students and grades with a menu to display, add, remove and average

#include "myLinkedList.h"

int main()
{
	int choice;
	int number = 0;
	Evaluation* first = NULL;
	
	do
	{
		cout << endl << endl << "1) Display  of the complete linked list.\n";
		cout << "2) Insert an element\n";
		cout << "3) Remove an element.\n";
		cout << "4) Calculation of the class average.\n";
		cout << "5) Exit the program.\n" << endl << endl;
		cout << "Your choice ??:";
		cin >> choice;

		switch (choice)
		{
		case 1: display(first);
			break;
		case 2: first = add(first, number);
			break;
		case 3: first = remove(first, number);
			break;
		case 4: average(first, number);
			break;
		case 5: exit(0);
		default:
			break;
		}
	} while (1);
	return 0;
}



/*
*add() Function*
**/
// takes the first element and the number of elements, adds a new student
// after the position the user picks, returns the first element
Evaluation* add(Evaluation* p, int& number)
{
	//YOUR CODE COMES HERE
	int pos;
	cout << "After which element you want to insert ? (0 for start): ";
	cin >> pos;
	while (pos < 0 || pos > number) {
		cout << "Invalid number, try again: ";
		cin >> pos;
	}
 
	Evaluation* e = new Evaluation;
	cout << " Entering the item from the chained list." << endl;
	cout << "Enter the student: ";
	cin.ignore(); // get rid of the leftover newline before getline
	cin.getline(e->student, capacity);
	cout << "Enter the grade: ";
	cin >> e->grade;
 
	if (pos == 0) {
		e->next = p;
		p = e;
	}
	else {
		// move to the element we insert after
		Evaluation* cur = p;
		for (int i = 1; i < pos; i++)
			cur = cur->next;
		e->next = cur->next;
		cur->next = e;
	}
 
	number++;
	return p;
}


/**
*remove() Function*
**/
// takes the first element and the number of elements, deletes the element
// number the user picks, returns the first element

Evaluation* remove(Evaluation* p, int& number)
{
	//YOUR CODE COMES HERE
	if (p == NULL) {
		cout << "The list is empty." << endl;
		return p;
	}
 
	int pos;
	cout << "what is the number of the element to delete ?: ";
	cin >> pos;
	while (pos < 1 || pos > number) {
		cout << "Invalid number, try again: ";
		cin >> pos;
	}
 
	Evaluation* temp;
	if (pos == 1) {
		temp = p;
		p = p->next;
	}
	else {
		Evaluation* prev = p;
		for (int i = 1; i < pos - 1; i++)
			prev = prev->next;
		temp = prev->next;
		prev->next = temp->next;
	}
	delete temp;
 
	number--;
	return p;
}



/**
*display() Function *
**/
// takes the first element and prints every student and grade
void display(Evaluation* p)
{
	//YOUR CODE COMES HERE

	if (p == NULL) {
		cout << "The list is empty." << endl;
		return;
	}
 
	while (p != NULL) {
		cout << "Student :" << p->student << endl;
		cout << "The grade is :" << p->grade << endl;
		p = p->next;
	}
}



/**
*average() Function *
***/
// takes the first element and the number of elements, prints the class average
// returns 1 if it worked, 0 if the list is empty
int average(Evaluation* p, int const& nbre)
{
	//YOUR CODE COMES HERE
	if (p == NULL || nbre == 0) {
		cout << "The list is empty, no average." << endl;
		return 0;
	}
 
	int sum = 0;
	while (p != NULL) {
		sum += p->grade;
		p = p->next;
	}
 
	cout << "The average of the class is: " << (double)sum / nbre << endl;
	return 1;
}






