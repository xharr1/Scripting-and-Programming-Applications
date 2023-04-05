#pragma once
#include "degree.h"

class Student {
public:
	Student(string id, string fName, string lName, string eAddress, int age, int days1, int days2, int days3, DegreeProgram degree);
	string GetStudentID();
	void SetStudentID(string id);
	string GetFirstName();
	void SetFirstName(string fName);
	string GetLastName();
	void SetLastName(string lName);
	string GetEmailAddress();
	void SetEmailAddress(string eAddress);
	int GetAge();
	void SetAge(int age);
	int* GetDaysPerCourse();
	void SetDaysPerCourse(int days1, int days2, int days3);
	DegreeProgram GetDegree();
	void SetDegree(DegreeProgram degree);
	void print();

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysPerCourse[3];
	DegreeProgram degree;
};
