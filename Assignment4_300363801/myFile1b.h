/* myFile1b.h - Student class: ID, courses, grades, average/hours helpers (Lab 4 Ex1b) */

#include <iostream>
using namespace std;

class Student {
	int numID;
	int nbCourses;
	int maxCourses;
	int* List_grades;
	Course** List_courses;
public:
	Student(int, int); 	//constructor
	~Student(); 		//destructor
	double average();
	int totalHours();
	bool addCourse(Course*, int);
};

/* Student: creates a student. Inputs: int id = registration number, int max = max courses */
Student::Student(int id, int max) {
	numID = id;
	maxCourses = max;
	nbCourses = 0;
	List_grades = new int[maxCourses];
	List_courses = new Course*[maxCourses];
}

/* ~Student: frees grade and course list arrays. Inputs: none */
Student::~Student() {
	delete[] List_grades;
	delete[] List_courses;
}

/* average: returns the student's average grade (double). Inputs: none */
double Student::average() {
	if (nbCourses == 0) return 0;
	double sum = 0;
	for (int i = 0; i < nbCourses; i++)
		sum += List_grades[i];
	return sum / nbCourses;
}

/* totalHours: returns total hours of courses taken (int). Inputs: none */
int Student::totalHours() {
	int sum = 0;
	for (int i = 0; i < nbCourses; i++)
		sum += List_courses[i]->getHours();
	return sum;
}

/* addCourse: adds a course and grade if space remains (bool). Inputs: Course* c = course, int grade = grade */
bool Student::addCourse(Course* c, int grade) {
	if (nbCourses >= maxCourses) return false;
	List_courses[nbCourses] = c;
	List_grades[nbCourses] = grade;
	nbCourses++;
	return true;
}
