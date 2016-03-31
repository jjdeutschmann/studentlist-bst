//****************************************************************************************************
//
//     File: student.h
//
//     Author: Jennifer Deutschmann
//
//     The definition for the structure Student.
//			 
//****************************************************************************************************

#ifndef STUDENT_H
#define STUDEHT_H

//****************************************************************************************************

#include <iostream>
#include <iomanip>

using namespace std;

//****************************************************************************************************

struct Student
{
	int id;
	char name[50];
	char citystate[50];
	int phone;
	char gender;
	int year;
	int credits;
	float gpa;
	char major[6];

	Student();
	friend ostream & operator << (ostream & out, const Student & data);
	bool operator == (const Student & rhs) const;
	bool operator == (const int & id) const;
	bool operator != (const Student & rhs) const;
	bool operator != (const int & id) const;
	bool operator < (const Student & rhs) const;
	bool operator < (const int & value) const;
	bool operator > (const Student & rhs) const;
	bool operator > (const int & value) const;
	bool operator <= (const Student & rhs) const;
	bool operator <= (const int & value) const;
	bool operator >= (const Student & rhs) const;
	bool operator >= (const int & value) const;
	int operator % (const int & value) const;
	Student & operator = (const int & value);
};

//****************************************************************************************************

Student :: Student ()
{
	id = 0;
}

//****************************************************************************************************

ostream & operator << (ostream & out, const Student & data)
{
	out << left << setw(10) << data.id << setw(20) << data.name;
	
	return out;
}

//****************************************************************************************************

bool Student :: operator == (const Student & rhs) const
{
	return ( this -> id == rhs.id );
}

//****************************************************************************************************

bool Student :: operator == (const int & id) const
{
	return ( this -> id == id );
}

//****************************************************************************************************

bool Student :: operator != (const Student & rhs) const
{
	return ( this -> id != rhs.id );
}

//****************************************************************************************************

bool Student :: operator != (const int & id) const
{
	return ( this -> id != id );
}

//****************************************************************************************************

bool Student :: operator < (const Student & rhs) const
{
	return ( this -> id < rhs.id );
}

//****************************************************************************************************

bool Student :: operator < (const int & value) const
{
	return ( this -> id < value );
}

//****************************************************************************************************

bool Student :: operator > (const Student & rhs) const
{
	return ( this -> id > rhs.id );
}

//****************************************************************************************************

bool Student :: operator > (const int & value) const
{
	return ( this -> id > value );
}

//****************************************************************************************************

bool Student :: operator <= (const Student & rhs) const
{
	return ( this -> id <= rhs.id );
}

//****************************************************************************************************

bool Student :: operator <= (const int & value) const
{
	return ( this -> id <= value );
}

//****************************************************************************************************

bool Student :: operator >= (const Student & rhs) const
{
	return ( this -> id >= rhs.id );
}

//****************************************************************************************************

bool Student :: operator >= (const int & value) const
{
	return ( this -> id >= value );
}

//****************************************************************************************************


int Student :: operator % (const int & value) const
{
	return ( this -> id % value );
}

//****************************************************************************************************

Student & Student :: operator = (const int & value)
{
	this -> id = value;
	return *this;
}

//****************************************************************************************************

#endif

//****************************************************************************************************