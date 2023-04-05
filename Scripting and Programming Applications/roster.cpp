using namespace std;
#include <iostream>
#include <string>
#include "roster.h"

Roster::Roster() {
	int i;
	for (i = 0; i < 5; ++i) {
		classRosterArray[i] = nullptr;
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int i;

	for (i = 0; i < 5; ++i) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
			break;
		}
	}
}

void Roster::parse(string row) {
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse1;
	int daysInCourse2;
	int daysInCourse3;
	DegreeProgram degreeProgram;
	//temp string degree to change to enum degree
	string tmpDegree;
	//left hand side, right hand side, and length for sting find and substring
	int lhs = 0;
	int rhs = 0;
	int len = 0;
	
	//find studentID
	rhs = row.find(',', lhs);
	len = rhs - lhs;
	studentID = row.substr(lhs, len);
	lhs = rhs + 1;

	//find firstName
	rhs = row.find(',', lhs);
	len = rhs - lhs;
	firstName = row.substr(lhs, len);
	lhs = rhs + 1;

	//find lastName
	rhs = row.find(',', lhs);
	len = rhs - lhs;
	lastName = row.substr(lhs, len);
	lhs = rhs + 1;

	//find emailAddress
	rhs = row.find(',', lhs);
	len = rhs - lhs;
	emailAddress = row.substr(lhs, len);
	lhs = rhs + 1;

	//find age
	rhs = row.find(',', lhs);
	len = rhs - lhs;
	age = stoi(row.substr(lhs, len));
	lhs = rhs + 1;

	//find daysInCourse1
	rhs = row.find(',', lhs);
	len = rhs - lhs;
	daysInCourse1 = stoi(row.substr(lhs, len));
	lhs = rhs + 1;

	//find daysInCourse2
	rhs = row.find(',', lhs);
	len = rhs - lhs;
	daysInCourse2 = stoi(row.substr(lhs, len));
	lhs = rhs + 1;

	//find daysInCourse3
	rhs = row.find(',', lhs);
	len = rhs - lhs;
	daysInCourse3 = stoi(row.substr(lhs, len));
	lhs = rhs + 1;

	//find degreeProgram
	rhs = row.find(',', lhs);
	len = rhs - lhs;
	tmpDegree = row.substr(lhs, len);
	if (tmpDegree == "SECURITY") {
		degreeProgram = SECURITY;
	}
	else if (tmpDegree == "NETWORK") {
		degreeProgram = NETWORK;
	}
	else if (tmpDegree == "SOFTWARE") {
		degreeProgram = SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::remove(string studentID) {
	int i;
	bool idFound = false;

	for (i = 0; i < 5; ++i) {
		if (this->classRosterArray[i] == nullptr) {
			continue;
		}
		else if (this->classRosterArray[i]->GetStudentID() == studentID) {
			this->classRosterArray[i] = nullptr;
			cout << endl << "Removing " << studentID << endl << endl;
			idFound = true;
			break;
		}

	}

	if (idFound == false) {
		cout << endl << "The student with the ID " << studentID << " was not found." << endl;
	}
}

void Roster::printAll() {
	int i;

	for (i = 0; i < 5; ++i) {
		if (this->classRosterArray[i] != nullptr) {
			this->classRosterArray[i]->print();  
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	int i;
	int avgDays;

	for (i = 0; i < 5; ++i) {
		if (this->classRosterArray[i] == nullptr) {
			continue;
		}
		else if (this->classRosterArray[i]->GetStudentID() == studentID) {
			avgDays = (this->classRosterArray[i]->GetDaysPerCourse()[0]
				+ this->classRosterArray[i]->GetDaysPerCourse()[1]
				+ this->classRosterArray[i]->GetDaysPerCourse()[2])
				/ 3;
			cout << "Student ID: " << this->classRosterArray[i]->GetStudentID()
				<< ", average days in course: " << avgDays << endl;
			break;
		}
	}
}

void Roster::printInvalidEmails() {
	int i;

	for (i = 0; i < 5; ++i) {
		if (this->classRosterArray[i] == nullptr) {
			continue;
		}
		else if (this->classRosterArray[i]->GetEmailAddress().find(' ') != string::npos
			|| this->classRosterArray[i]->GetEmailAddress().find('@') == string::npos
			|| this->classRosterArray[i]->GetEmailAddress().find('.') == string::npos) {
			
			cout << this->classRosterArray[i]->GetEmailAddress() << " - is invalid." << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	int i;

	for (i = 0; i < 5; ++i) {
		if (this->classRosterArray[i] == nullptr) {
			continue;
		}
		else if (this->classRosterArray[i]->GetDegree() == degreeProgram) {
			this->classRosterArray[i]->print();
		}
	}
}

Student* Roster::GetRosterItem(int index) {
	return this->classRosterArray[index];
}

Roster::~Roster() {
	cout << endl << "Destructor executed" << endl;
}