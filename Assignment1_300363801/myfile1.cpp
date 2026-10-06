#include "myfile1.h"


int main(void){

    cout << "Size in bytes of a character: " << sizeof(char) << endl;
    cout << "Size in bytes of an integer: " << sizeof(int) << endl;
    cout << "Size in bytes of a float: " << sizeof(float) << endl;
    cout << "Size in bytes of a double: " << sizeof(double) << endl;
    cout << "Size in bytes of a short Integer: " << sizeof(short) << endl;
    cout << "Size in bytes of an unsigned Integer: " << sizeof(unsigned int) << endl;
    
    cout << "Enter an integer: ";
    int userInput;
    cin >> userInput;

    cout << "Number in decimal: " << userInput << endl;
    cout << "Number in octal: " << oct << userInput << endl;
    cout << "Number in hexadecimal: " << hex << userInput << endl;

    cout << "Enter a real number: ";
    float userInput2;
    cin >> userInput2;
    cout << userInput2 << endl;
    cout << scientific << userInput2 << endl;

    cout << "Enter a character: ";
    char userInput3;
    cin >> userInput3;
    cout << userInput3 << endl;
    cout << static_cast<int>(userInput3) << endl;

}
