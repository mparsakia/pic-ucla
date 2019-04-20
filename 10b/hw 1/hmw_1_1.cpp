/*
Description: Pointers homework 1.1 (P7.1).
Known bugs: Sometimes, unknowinlgly why, the program will crash if it tried to assign a best friend who wasn't in the list 
I think I solved it with an if statement in the print_info member funciton, but this happens inconsistently so I am not sure
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std; 
class Person {
public:
	Person(); 
	Person(string pname); 
	void set_best_friend(Person *bfr); 
	void incpop(); 
	int getpop(); 
	string getbf(); 
	string getname(); 
	void print_info(); 
	void incpop2(Person *bfr2); 

private:
	string name;
	Person *bestfr;
	int popcount;
}; 

Person::Person() 
{
	name = "default";
	popcount = 0;
	bestfr = NULL;
}

Person::Person(string pname) 
{
	name = pname;
	popcount = 0;
	bestfr = NULL;
}

void Person::incpop() 
{
	popcount++;
}


void Person::incpop2(Person *bfr2)
{
	bfr2->popcount++;
}

void Person::set_best_friend(Person *bfr) 
{
	bestfr = bfr;
	incpop2(bfr);
}

string Person::getname() { return name; } 

string Person::getbf() { return bestfr->getname(); } 

int Person::getpop() { return popcount; } 


void Person::print_info() 
{
	if (this->bestfr != NULL) 
	{
		cout << this->getname() << " : " << this->getbf() << " : " << this->getpop() << endl;
	}
	else 
	{
		cout << this->getname() << " : NONE : " << this->getpop() << endl;
	}
} 

int main() {

	string morepeople = "y";
	vector<Person*> people; 
	string names;
	string bestie;

	while (morepeople == "y") 
	{
		cout << "Name: ";
		getline(cin, names); 
		Person* h = new Person(names); 
		people.push_back(h); 
		cout << endl;
		cout << "Continue (y/n)? ";
		getline(cin, morepeople);
		cout << endl;
	}


	if (morepeople != "y") 
	{
		cout << "Enter the names of best friends:" << endl;
		cout << endl;

		for (int a = 0; a < people.size(); a++) 
		{
			cout << "Best friend of " << people[a]->getname() << ": "; 
			getline(cin, bestie);
			for (int j = 0; j<people.size(); j++) 
			{
				if (people[j]->getname() == bestie) 
				{
					people[a]->set_best_friend(people[j]); 
				}
			}
		}
	}

	cout << endl;
	cout << "Information:" << endl;
	for (int q = 0; q < people.size(); q++) 
	{
		people[q]->print_info(); 
	}


	system("pause"); 
	return 0; 
} 