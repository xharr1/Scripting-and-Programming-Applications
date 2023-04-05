using namespace std;
#include <iostream>
#include <string>
#include "roster.h"


int main() {
	int i;
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Harrison,Plummer,hplumm6@wgu.edu,28,51,48,25,SOFTWARE" };

	cout << "C867-Scripting & Programming - Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 010186537" << endl;
	cout << "Name: Harrison Plummer" << endl << endl;

	Roster classRoster;

	for (i = 0; i < 5; ++i) {
		classRoster.parse(studentData[i]);
	}
	
	cout << "Displaying all students:" << endl;
	classRoster.printAll();

	cout << endl << "Displaying invalid emails:" << endl;
	classRoster.printInvalidEmails();

	cout << endl;

	for (i = 0; i < 5; ++i) {
		if (classRoster.GetRosterItem(i) != nullptr) {
			classRoster.printAverageDaysInCourse(classRoster.GetRosterItem(i)->GetStudentID());
		}
	}

	cout << endl << "Showing students in degree program: SOFTWARE" << endl;
	classRoster.printByDegreeProgram(SOFTWARE);

	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");

	classRoster.~Roster();

	return 0;
}