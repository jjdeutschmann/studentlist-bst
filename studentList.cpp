//****************************************************************************************************
//
//     File: studentList.cpp
//
//     Author: Jennifer Deutschmann
//
//     This program stores Students in a doubly linked list and uses a menu to do different
//	   operations to the student list.	 
//
//     Other files needed:
//	   1. student.h
//	   2. node.h
//	   3. BST.h
//
//****************************************************************************************************

#include <iostream>
#include <fstream>

using namespace std;

#include "student.h"
#include "BST.h"

//****************************************************************************************************

char getChoice ();
void process ( BST<Student> & studentList );
void buildList ( BST<Student> & studentList );

void addNewStudent ( BST<Student> & studentList );
void removeStudent ( BST<Student> & studentList );
void findStudent ( BST<Student> & studentList );
void updateStudent ( BST<Student> & studentList );
void displayStudents ( BST<Student> & studentList );
void display1Student ( Student student );
void displayListInformation ( BST<Student> & studentList );

//****************************************************************************************************

int main ()
{
	BST<Student> studentList;

	process ( studentList );

	return 0;
}

//****************************************************************************************************

char getChoice ()
{
	char choice;
	bool valid;

	cout << "======== MENU ========\n"
		<< " A:    Add a new Student \n"
		<< " R:    Remove a Student \n"
		<< " F:    Find a Student Record \n"
		<< " U:    Update a Student Record \n"
		<< " D:    Display all Students \n"
		<< " L:    Display list information \n"
		<< " Q:    Quit \n\n";

	do
	{
		cin >> choice;
		choice = toupper (choice);

		switch ( choice )
		{
			case 'A': 
			case 'R':
			case 'F':
			case 'U':
			case 'D':
			case 'L':
			case 'Q':	valid = true;
						break;
			default:	valid = false;
						cout << "\aInvalid choice\n"
							<< "Please try again: ";
						break;
		}
	}
	while ( !valid );

	return choice;
}

//****************************************************************************************************

void process ( BST<Student> & studentList )
{
	char choice;

	do
	{
		choice = getChoice();

		switch ( choice )
		{
			case 'A': 	addNewStudent (studentList);
						break;
			case 'R': 	removeStudent (studentList);
						break;
			case 'F': 	findStudent (studentList);
						break;
			case 'U':   updateStudent (studentList);
						break;
			case 'D': 	displayStudents (studentList);
						break;
			case 'L':   displayListInformation (studentList);
						break;
			case 'Q': 	break;
		}
	}
	while (choice != 'Q');
}

//****************************************************************************************************

void addNewStudent ( BST<Student> & studentList )
{
	Student newStudent;

	cin.ignore();
	cout << "Enter valid information for a new Student.\nEnter ID: ";
	cin >> newStudent.id;
	cin.ignore();

	cout << "Enter the name: ";
	cin.getline(newStudent.name, 80);

	cout << "Enter the city and state: ";
	cin.getline(newStudent.citystate, 80);

	cout << "Enter the phone number (formatted as 1234567890): ";
	cin >> newStudent.phone;

	cout << "Enter the gender (formatted as M or F): ";
	cin >> newStudent.gender;

	cout << "Enter the year: ";
	cin >> newStudent.year;

	cout << "Enter the credits: ";
	cin >> newStudent.credits;

	cout << "Enter the GPA: ";
	cin >> newStudent.gpa;
	cin.ignore();

	cout << "Enter the major: ";
	cin.getline(newStudent.major, 80);

	studentList.insert ( newStudent );
	cout << "Student Added.\n"
		<< "--- Student's Info ---\n" << newStudent << endl;

}

//****************************************************************************************************

void removeStudent ( BST<Student> & studentList )
{
	if ( studentList.isEmpty() )
		cout << "No student information has been entered." << endl;
	else
	{
		Student delStudent;
	
		cout << "Enter the ID of the student you want to remove: ";
		cin >> delStudent.id;

		if ( studentList.remove(delStudent) )
		{
			cout << "Student Removed.\n"
				<< "--- Student's Info ---\n" << delStudent << endl;
		}
		else
			cout << "No Student with that ID was found.\n\n";
	}
}

//****************************************************************************************************

void findStudent ( BST<Student> & studentList )
{
	if ( studentList.isEmpty() )
		cout << "No student information has been entered." << endl;
	else
	{
		Student searchStudent;

		cout << "Enter the ID of the Student you want to find: ";
		cin >> searchStudent.id;

		if ( studentList.search(searchStudent) )
		{
			cout << "Student Found.\n"
				<< "--- Student's Info ---\n" << searchStudent << endl;
		}
		else
			cout << "No student with that ID was found.\n\n";
	}
}

//****************************************************************************************************

void updateStudent ( BST<Student> & studentList )
{
	Student updateStudent;

	cout << "Enter the ID of the Student you want to update: ";
	cin >> updateStudent.id;

	if ( studentList.search(updateStudent) )
	{
		cin.ignore();
		cout << "Enter Student's updated Name: ";
		cin.getline (updateStudent.name, 80);
		cout << "Enter Student's updated City: ";
		cin.getline (updateStudent.citystate, 80);
		cout << "Enter Student's updated Phone Number: ";
		cin >> updateStudent.phone;
		cout << "Enter Student's updated Gender: ";
		cin >> updateStudent.gender;
		cout << "Enter Student's updated Graduation Year: ";
		cin >> updateStudent.year;
		cout << "Enter Student's updated Credits: ";
		cin >> updateStudent.credits;
		cout << "Enter Student's updated GPA: ";
		cin >> updateStudent.gpa;
		cin.ignore();
		cout << "Enter Student's updated Major: ";
		cin.getline (updateStudent.major, 80);

		studentList.update(updateStudent);

		cout << "Student Updated.\n"
			<< "Student's Info: " << updateStudent << "\n\n";
	}
	else
		cout << "No student with that ID was found.\n\n";
}

//****************************************************************************************************

void displayStudents ( BST<Student> & studentList )
{
	studentList.traverse(display1Student);
}

//****************************************************************************************************

void display1Student ( Student student )
{
	cout << student << endl;
}

//****************************************************************************************************

void displayListInformation ( BST<Student> & studentList )
{
	cout << "Number of Students: " << studentList.getCount() << endl
		<< "Height of the tree: " << studentList.getHt() << endl;

	if ( studentList.isEmpty() )
		cout << "The list is empty. \n";
	else
		cout << "The list is not empty. \n";

	if ( studentList.isFull() )
		cout << "The list is full. \n";
	else
		cout << "The list is not full. \n";

	if ( studentList.isBalanced() )
		cout << "The tree is balanced. \n\n";
	else
		cout << "The tree is not balanced. \n\n";
}

//****************************************************************************************************