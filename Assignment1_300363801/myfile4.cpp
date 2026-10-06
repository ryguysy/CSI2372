#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;



int main(void){

    int number, cval;
    int sum = 0;
    cout <<"Please enter your number: ";
    cin >> number;

    //Conversion to grab individual digits
    string str = to_string(number);

    vector<char> digits(str.begin(), str.end());

    for (size_t i = 0; i < digits.size(); ++i) {

        cval = digits[i] - '0';
        sum += cval * cval * cval;

    }


    if (sum == number) {
        cout << "This is an Armstrong number" << endl;
    }
    else {
        cout << "This is not an Armstrong number" << endl;
    }


}