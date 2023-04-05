using namespace std;
#include <iostream>
#include <string>
#include "student.h"

Student::Student(string id, string fName, string lName, string eAddress, int age, int days1, int days2, int days3, DegreeProgram degree) {
	studentID = id;
	firstName = fName;
	lastName = lName;
	emailAddress = eAddress;
	this->age = age;
	daysPerCourse[0] = days1;
	daysPerCourse[1] = days2;
	daysPerCourse[2] = days3;
	this->degree = degree;
}

string Student::GetStudentID() {
	return studentID;
}

void Student::SetStudentID(string id) {
	studentID = id;
}

string Student::GetFirstName() {
	return firstName;
}
 
void Student::SetFirstName(string fName) {
	firstName = fName;
}   

string Student::GetLastName() {
	return lastName;
}

void Student::SetLastName(string lName) {
	lastName = lName;
}

string Student::GetEmailAddress() {
	return emailAddress;
}

void Student::SetEmailAddress(string eAddress) {
	emailAddress = eAddress;
}

int Student::GetAge() {
	return age;
}

void Student::SetAge(int age) {
	this->age = age;
}

int* Student::GetDaysPerCourse() {
	return daysPerCourse;
}

void Student::SetDaysPerCourse(int days1, int days2, int days3) {
	daysPerCourse[0] = days1;
	daysPerCourse[1] = days2;
	daysPerCourse[2] = days3;
}
DegreeProgram Student::GetDegree() {
	return degree;
}
void Student::SetDegree(DegreeProgram degree) {
	this->degree = degree;
}
void Student::print() {
	string strDegree;

	if (this->degree == SOFTWARE) {
		strDegree = "SOFTWARE";
	}
	else if (this->degree == SECURITY) {
		strDegree = "SECURITY";
	}
	else {
		strDegree = "NETWORK";
	}

	cout << this->studentID << "\t" 
		<< this->firstName << "\t"
		<< this->lastName << "\t"
		<< this->age << "\t"
		<< "{" << this->daysPerCourse[0] << ","
		<< this->daysPerCourse[1] << ","
		<< this->daysPerCourse[2] << "}\t"
		<< strDegree << endl;
}