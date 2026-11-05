/* myFile1a.h - Course class: stores a course code and hours (Lab 4 Ex1a) */

#include <iostream>
using namespace std;

class Course {
    int num;
    int hours;
public:
    Course(int, int); 	//constructor
    int getNum();
    int getHours();
};

/* Course: creates a course. Inputs: int n = course code, int h = hours */
Course::Course(int n, int h) {
    num = n;
    hours = h;
}

/* getNum: returns the course code (int). Inputs: none */
int Course::getNum() {
    return num;
}

/* getHours: returns the number of course hours (int). Inputs: none */
int Course::getHours() {
    return hours;
}
