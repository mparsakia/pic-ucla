/*

Assignment: Merge sort employee objects by salary and print to console. 

*/

#include <iostream>		
#include <string>		
#include <cstring>		
#include <sstream>		
#include <fstream>		
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Employee
{
public:
	Employee() { name = "test";  salary = 9.09; }
	Employee(string e_name, double e_salary)
		: name(e_name), salary(e_salary) { }
	void   set_salary(double new_salary) { salary = new_salary; }
	string get_name() const { return name; }
	double get_salary() const { return salary; }
	virtual void print() const
	{
		std::cout << "Employee: " << name
			<< ", $" << salary << endl;
	}
	virtual ~Employee() {}
protected:
	string name;
	double salary;
}; 
bool operator<(const Employee& a, const	Employee& b)
{
	return a.get_salary() < b.get_salary();
} 

void employ_merge(vector<Employee>& a, int from, int mid, int to)
{
	int n = to - from + 1; 

	vector<Employee> b(n); 

	int i1 = from; 
	int i2 = mid + 1; 
	int j = 0; 

	while (i1 <= mid && i2 <= to) 
	{
		if (a[i1] < a[i2])
		{
			b[j] = a[i1];
			i1++;
		}
		else
		{
			b[j] = a[i2];
			i2++;
		}
		j++;
	} 
	while (i1 <= mid) 
	{
		b[j] = a[i1];
		i1++;
		j++;
	}

	while (i2 <= to) 
	{
		b[j] = a[i2];
		i2++;
		j++;
	}

	for (j = 0; j < n; j++) 
	{
		a[from + j] = b[j];
	}
} 

void emp_merge_sort(vector<Employee>& a, int from, int to)
{
	if (from == to) return;
	int mid = (from + to) / 2; 
	emp_merge_sort(a, from, mid);
	emp_merge_sort(a, mid + 1, to);
	employ_merge(a, from, mid, to);
}

int main() {

	ifstream filein;
	vector<Employee> employees;

	filein.open("data2.txt");
	vector<string> names;
	vector<double> salaries;

	while (!filein.eof()) 
	{
		string n = "n_init"; 
		string sal = "sal_init";

		getline(filein, n, '|'); 
		names.push_back(n); 

		getline(filein, sal, '\n'); 
		double salary_stod = stod(sal); 
		salaries.push_back(salary_stod); 
	}  
	for (size_t i = 0; i < names.size(); i++)
	{
		employees.push_back(Employee(names[i], salaries[i]));
	}

	cout << "Employees, before sorting: \n";
	for (size_t i = 0; i < employees.size(); i++)
	{
		employees[i].print();
	} 
	emp_merge_sort(employees, 0, employees.size() - 1); 

	cout << endl;

	cout << "Employees, after merge sorting: \n";
	for (size_t i = 0; i < employees.size(); i++)
	{
		employees[i].print();
	}

	cout << endl;
	system("pause");
	return 0;
} 