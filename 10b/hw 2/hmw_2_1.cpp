/*

Description: Homework 2				Question 1

*/

#include <iostream>
#include <string>   
using namespace std; 

class Person {
public:
	Person();
	Person(string pname, string pbirthday); 
	string getname();
	string getbirthday();
	void setname(string sname);
	void setbirthday(string sbirthday);
	void print();

private:
	string name;
	string birthday;
};

Person::Person() {
	name = "DEFAULT";
	birthday = "00/00/00";
}

Person::Person(string pname, string pbirthday) {
	name = pname;
	birthday = pbirthday;
}

void Person::setname(string sname) { name = sname; };
void Person::setbirthday(string sbirthday) { birthday = sbirthday; }

string Person::getname() { return name; }
string Person::getbirthday() { return birthday; }

void Person::print(){
	cout << "Name:      " << name << "\nBirthday:  " << birthday << "\n";
} 

class Instructor : public Person {
public:
	Instructor();
	Instructor(string isalary, string iname, string ibirth); 
	string getsalary();
	void print();

private:
	string salary; 

};

Instructor::Instructor() : Person() { salary = "00000"; } 

Instructor::Instructor(string isalary , string iname, string ibirth) : Person(iname,ibirth) { salary = isalary; } 

string Instructor::getsalary() { return salary; }

void Instructor::print() {
	Person::print();
	cout << "Salary:    " << salary;
} 

class Student : public Person {
public:
	Student();
	Student(string sname, string smajor, string sbirthday);
	string getmajor();
	void print();

private:
	string major;
};

Student::Student() : Person() { major = "DEFAULT"; }

Student::Student(string sname, string smajor, string sbirthday) : Person(sname, sbirthday) { major = smajor; }

string Student::getmajor() { return major; }

void Student::print() {
	Person::print();
	cout << "Major:     " << major;

} 


int main() {

	string prname;
	string prbirth;

	string insname;
	string insbirth;
	string insalary;

	string stuname;
	string stubirth;
	string stumajor;

	cout << "Person's full name: ";
	getline(cin, prname);
	cout << "Person's birthday <mm/dd/yyyy>: ";
	getline(cin, prbirth);
	cout << endl;
	Person p(prname, prbirth);
	
	cout << "Instructor's full name: ";
	getline(cin, insname);

	cout << "Instructor's birthday <mm/dd/yyyy>: ";
	getline(cin, insbirth);

	cout << "Instructor's salary: ";
	getline(cin, insalary);
	cout << endl;
	Instructor i(insalary, insname, insbirth);

	cout << "Student's full name: ";
	getline(cin, stuname);

	cout << "Student's birthday <mm/dd/yyyy>: ";
	getline(cin, stubirth);

	cout << "Student's major: ";
	getline(cin, stumajor);
	cout << endl;
	Student s(stuname, stumajor, stubirth);

	cout << "Person's Information:\n";
	p.print();
	cout << endl;

	cout << "Instructor's Information:\n";
	i.print();
	cout << endl;
	cout << endl;


	cout << "Student's information:\n";
	s.print();
	cout << endl;

	system("pause");
	return 0;
}