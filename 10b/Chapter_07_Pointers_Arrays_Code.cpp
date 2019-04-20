
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

class Employee
{
public:
	Employee() {  }
	Employee(string employee_name, double initial_salary);
	void set_salary(double new_salary) { salary = new_salary; }
	string get_name() const { return name; }
	double get_salary() const { return salary; }
private:
	string name;
	double salary;
};


void print_employee_info(Employee* e); // prints information about the employee

int* maximum(const int* a, int a_size); // returns the pointer that points to the highest element

void print_array(const int* a, int a_size, string d = ","); // prints array with "," being a default delimititer

void print_matrix( int** a, int n_col, int n_row, string d = ","); // prints array with "," being a default delimititer

int* get_random_numbers_dynamically(unsigned int a_size);
// this function that allocates memory for an array of a given size
// then initializes the array with random numbers and returns the pointer
// note after the function is executed the memory in the heap stays "alive"
// it will not be reclaimed as in the case of a static array





int main()
{
	//********* Example 1: Pointers basics
	
	int i = 7, j = 8;
	int* ip = NULL;  // ip does not point to anything
	int* jp = &j;    // jp points to j
	ip = &i;         // now ip points to i
	cout << *ip << "\n" ; // dereferencing ip to print i value
	cout << (*jp)++ << "\n"; // dereferencing jp to print j value
	ip = jp; // ip now points to j as well
	++(*ip); // equivalent to ++j
	cout << j << ", " << ip << "\n"; // prints j and the address of j
	
//
	//********* Example 2: Classes and Pointers
	
	Employee harry("Harry Doe",55000); // harry lives on stack
	Employee* p = & harry; // p now points to harry
	print_employee_info(p); // print_employee_info uses a pointer parameter
	

	//********* Example 3: Dynamically allocating memory - 1 variable basics
	
	int * i = new int; *i = 5; // allocates memory for 1 int variable and then sets the value to 5.
	delete i;                  // free memory;
	cout << "\n We freed memory,"
	<< " but i still points to "
	<< i << endl;  // print the address i
	i = NULL; // set i to NULL after memory is reclaimed
	cout << "After we reclaim the space in the heap it is best to set i to NULL = " << i << endl;
	
	
	//*********  Example 4: Dynamically allocating memory - 1 class
	
	Employee *harry = new Employee("Harry Doe", 55000); // harry points to the class that lives in the heap
	Employee *boss = new Employee("Lisa Doe", 155000);  // boss also a pointer that points to the class in the heap
	print_employee_info(harry); // print info about harry
	print_employee_info(boss); // print info about harry
	delete harry; harry = NULL; // reclaim memory and set harry to NULL
	delete boss; boss = NULL; // reclaim memory and set harry to NULL
	

	//********* Example 5: Static Arrays, pointers and basic pointer arithmetics
	
	int a[5] = { 0, 10, 20, 30, 40 }; // a lives in stack
	for (int i = 0; i < 5; i++)
	{
		cout << "a[" << i << "]=" 
			 << *(a + i) << ", its address is " 
			<< (a + i) << endl;
	}

	int* p1 = (a + 1); // points to a[1]
	int* p2 = (a + 3); // points to a[3]

	cout << "\n*(p1-1) is " << *(p1-1) << endl; // prints a[0]	
	cout << "*(p1+1) is " << *(p1+1) << endl; // prints a[2]
	cout << "*p1 is " << *p1 << endl; // prints a[1]
	cout << "*p2 is " << *p2 << endl; // prints a[3]
	cout << "(p2-p1) is " << (p2 - p1) << endl; // returns the number of elements in between
	p1++;
	cout << "(++p1) modifies p1, it now points to " << *p1 << endl; // returns a[2]
	


	//********* Example 6: Arrays and functions
	
	int b[5] = { 10, 20, 40, 50, 15 };
	int * mp;

	print_array(b, 5); // prints values of b

	cout << "\n";

	mp = (maximum(b, 5));
	cout << "\n maximum element in {b[0]...b[4]} is "
	<< *mp << "= b[" << (mp - b) << "]" << endl;

	mp = (maximum(b, 3));
	cout << "\n maximum element in {b[0]...b[2]}  is "
	<< *mp << "= b[" << (mp - b) << "]" << endl;

	mp = (maximum((b+2), 3));
	cout << "\n maximum element in {b[2]...b[4]}  is "
	<< *mp << "= b[" << (mp - b) << "]" << endl;
	

	//********* Example 7: new[] operator, dynamic arrays

	int b_size = 5;

	int *b = new int[b_size];

	for (int i=0; i < b_size; i++) b[i] = i*i;

//	suppose now we want to resize b

	int b_new_size = 2 * b_size;

//	We have to create new array. 
	{
		int* b_new = new int[b_new_size];

		//copy the old stuff to the memory allocated to b_new

		for (int i=0; i < b_size; b++) b_new[i]=b[i];

		//we now can delete the memory to which b points
		
		delete[] b; b = b_new; // reclaim the memory and set b to b_new
	}
	//Note the presence of { } that indicate the scope for the existence of b_new.
	//After "{", the pointer b_new will not exists. 
	

	********* Example 8: Functions and arrays. How to "return an array"?
	
	//We cannot return an actual array, but we can return a pointer to
	//an array created dynamically inside of a function. Here is how to do it.
	
	int a_size = 5;	
	
	//The following function returns an array with a_size random numbers, the array is created dynamically
	int *a = get_random_numbers_dynamically(a_size); 
	
	print_array(a, a_size);

	//don't forget to reclaim the memory allocated by the get_random_numbers

	delete[] a;

	//********* Example 9: 2-dimensional dynamic arrays and arrays of pointers
	
	//Suppose we want to allocate memory for a matrix of integer numbers.
	//One of course can use vector< vector<int> > class
	//but it can be done efficiently with pointers

	int n_row = 4; // number of rows
	int n_col = 6; // number of columns

	//first allocate the array of pointers which will point out to the beginning
	//of each row. We have n_rows so we will need a dynamic array of pointers
	//and hence the pointer to the array of pointers must be of the type int**

	int** a = new int*[n_row]; // a[0],a[1],...a[n_row-1] are pointers of type int*
	
	//next step to allocate the memory for actual matrix.
	//we allocate memory not for each pointer but for the whole matrix at once
	//and assign a[0] to point to the begginning of the array

	a[0] = new int[n_row * n_col]; // a[0] points to the array containing all elements of the matrix

	//finally set remaining pointers to point to the beginning of each row

	for (int i = 1; i < n_row; i++)
	{
		a[i] = (a[0] + n_col*i); // equivalent to writing a[i] = & ( a[0][n_col*i] )
	}

	//now set the values in the matrix:

	for (int i = 0; i < n_row; i++)
		for (int j = 0; j < n_col; j++)
			a[i][j] = i*j+i+j+1;
	
	//print out the matrix

	print_matrix(a, n_row, n_col);

	delete[] (a[0]); // deleting the memory to which a[0] points. Note the parenthesis around it.
	delete[] a; // delete the memory for the array of pointers.
	*/

	return 0;	

}


Employee::Employee(string employee_name, double initial_salary)
{
	this->name = employee_name;
	this->salary = initial_salary;
}

void print_employee_info(Employee* e)
{
	cout << "\nEmployee Name: "   << e->get_name();
	cout << "\nEmployee Salary: " << e->get_salary() << endl;

}


int* maximum(const int* a, int a_size) // returns the pointer tp the highest element
{
	if (a_size == 0) return 0;
	const int* highest = a; // set the pointer that will be pointing to the maximum element
							// observe that highest also is (const int *)
	const int* p = a + 1;   // p points to a[1]
	int count = a_size - 1;
	while (count > 0)
	{
		if (*p > *highest)
			highest = p;
		p++; // points to the next element
		count--;
	}
	return (int *)highest; // casting (const int*) to (int *)

}

void print_array(const int* a, int a_size, string d)
{
	cout << "\nArray values are: ";

	for (int i = 0; i < a_size; i++)
	{
		cout << a[i];

		if (i< (a_size - 1))	cout << d << " ";
	}

}


// prints a matrix with "," being a default delimititer
void print_matrix(int** a, int n_row, int n_col, string d)
{

	cout << "\Matrix values are:\n";

	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
		{
			cout << setw(5) << a[i][j];

			if (j != (n_col - 1)) cout << d;
		}
		cout << endl;
	}
}



// This function that allocates memory for an array of a given size
// then initializes the array with random numbers and returns the pointer
// note after the function is executed the memory in the heap stays "alive"
// it will not be reclaimed as in the case of a static array

int* get_random_numbers_dynamically(unsigned int a_size)
{
	if (a_size == 0) return NULL;

	int * a = new int[a_size];

	for (int i = 0; i < a_size; i++) a[i] = rand();

	return a;
}
