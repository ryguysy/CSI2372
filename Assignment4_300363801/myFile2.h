/* myFile2.h - SetInt class: dynamic set of unique integers (Lab 4 Ex2) */

#include <cstdlib> 
using namespace std;

class SetInt
{
public:
	SetInt() : elem(NULL), size(0) {}; // empty set; Inputs: none
	SetInt(int[], int);
	~SetInt();
	SetInt(const SetInt&);  // copy constructor
	void add(int);
	void remove(int);
	bool contains(int);
	int nbElem();
	int* tabElem();
private:
	int* elem;
	int size;
	bool containsIn(int n, int&);
};

/* SetInt: creates a set from an array. Inputs: int t[] = array, int n = size */
SetInt::SetInt(int t[], int n) {
	elem = NULL;
	size = 0;
	for (int i = 0; i < n; i++)
		add(t[i]);
}

/* ~SetInt: frees the element array. Inputs: none */
SetInt::~SetInt() {
	delete[] elem;
}

/* SetInt (copy): deep-copies another set. Inputs: const SetInt& s = set to copy */
SetInt::SetInt(const SetInt& s) {
	size = s.size;
	if (size == 0) {
		elem = NULL;
	} else {
		elem = new int[size];
		for (int i = 0; i < size; i++)
			elem[i] = s.elem[i];
	}
}

/* containsIn: checks if n is in the set; sets pos to its index (bool). Inputs: int n = value, int& pos = index out */
bool SetInt::containsIn(int n, int& pos) {
	for (int i = 0; i < size; i++) {
		if (elem[i] == n) {
			pos = i;
			return true;
		}
	}
	return false;
}

/* add: inserts n if not already present. Inputs: int n = value to add */
void SetInt::add(int n) {
	int pos;
	if (containsIn(n, pos)) return;
	int* tmp = new int[size + 1];
	for (int i = 0; i < size; i++)
		tmp[i] = elem[i];
	tmp[size] = n;
	delete[] elem;
	elem = tmp;
	size++;
}

/* remove: deletes n from the set if present. Inputs: int n = value to remove */
void SetInt::remove(int n) {
	int pos;
	if (!containsIn(n, pos)) return;
	if (size == 1) {
		delete[] elem;
		elem = NULL;
		size = 0;
		return;
	}
	int* tmp = new int[size - 1];
	for (int i = 0; i < pos; i++)
		tmp[i] = elem[i];
	for (int i = pos + 1; i < size; i++)
		tmp[i - 1] = elem[i];
	delete[] elem;
	elem = tmp;
	size--;
}

/* contains: returns true if n belongs to the set (bool). Inputs: int n = value */
bool SetInt::contains(int n) {
	int pos = 0;
	return containsIn(n, pos);
}

/* nbElem: returns the number of elements (int). Inputs: none */
int SetInt::nbElem() {
	return size;
}

/* tabElem: returns a new array of the set elements, or NULL if empty (int*). Inputs: none */
int* SetInt::tabElem() {
	if (size == 0) return NULL;
	int* t = new int[size];
	for (int i = 0; i < size; i++)
		t[i] = elem[i];
	return t;
}
