#include <vector> 
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Employee
{
public:
	//	Employee();
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

// Utilities description

/**
Swaps two integers.
@param x the first integer to swap
@param y the second integer to swap
*/
void swap(int& x, int& y);

/**
Prints all elements in a vector.
@param a the vector to print
*/
	void print(vector<int> a);

/**
Sets the seed of the random number generator.
*/
void rand_seed();

/**
Computes a random integer in a range.
@param a the bottom of the range
@param b the top of the range
@return a random integer x, a <= x and x <= b
*/
	int rand_int(int a, int b);

/**
Swaps two integers.
@param x the first integer to swap
@param y the second integer to swap
*/
void swap(int& x, int& y)
{
int temp = x;
x = y;
y = temp;
}
	 
/**
	Prints all elements in a vector.
	@param a the vector to print
	*/
void print(vector<int> a)
{
for (int i = 0; i < a.size(); i++)
	cout << a[i] << " ";
cout << "\n";
}
	 
/**
Sets the seed of the random number generator.
	*/
void rand_seed()
{
int seed = static_cast<int>(time(0));
srand(seed);
}
	 
/**
	Computes a random integer in a range.
	@param a the bottom of the range
	@param b the top of the range
	@return a random integer x, a <= x and x <= b
	*/
int rand_int(int a, int b)
{
return a + rand() % (b - a + 1);
}

/**
 Merges two adjacent ranges in a vector.
 @param a the vector with the elements to merge
 @param from the start of the first range
 @param mid the end of the first range
 @param to the end of the second range
 */
 void merge(vector<int>& a, int from, int mid, int to)
 {
	 int n = to - from + 1; // Size of the range to be merged
	 // Merge both halves into a temporary vector b
		vector<int> b(n);
	
		int i1 = from;
	 // Next element to consider in the first half
		int i2 = mid + 1;
	 // Next element to consider in the second half
		int j = 0; // Next open position in b
	
	
		 // As long as neither i1 nor i2 is past the end, move the smaller
		 // element into b
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
	
		 // Note that only one of the two while loops below is executed
		
		 // Copy any remaining entries of the first half
		 while (i1 <= mid)
		 {
		 b[j] = a[i1];
		 i1++;
		 j++;
		 }
	 // Copy any remaining entries of the second half
		 while (i2 <= to)
		 {
		 b[j] = a[i2];
		 i2++;
		 j++;
		 }
	
		 // Copy back from the temporary vector
		 for (j = 0; j < n; j++)
		 a[from + j] = b[j];
	 }

 /**
    Sorts the elements in a range of a vector.
    @param a the vector with the elements to sort
    @param from start of the range to sort
    @param to end of the range to sort
    */
	void merge_sort(vector<int>& a, int from, int to)
	 {
	 if (from == to) return;
	 int mid = (from + to) / 2;
	 // Sort the first and the second half
		 merge_sort(a, from, mid);
	 merge_sort(a, mid + 1, to);
	 merge(a, from, mid, to);
		 }



/**
Gets the position of the smallest element in a vector range.
@param a the vector
@param from the beginning of the range
@param to the end of the range
@return the position of the smallest element in
the range a[from]...a[to]
*/
int min_position(vector<int>& a, int from, int to)
{
	int min_pos = from;
	int i;
	for (i = from + 1; i <= to; i++)
		if (a[i] < a[min_pos]) min_pos = i;
	return min_pos;
}


/**
Sorts a vector using the selection sort algorithm.
@param a the vector to sort
*/
void selection_sort(vector<int>& a)
{
	int next; // The next position to be set to the minimum

	for (next = 0; next < a.size() - 1; next++)
	{


		// Find the position of the minimum
		int min_pos = min_position(a, next, a.size() - 1);
		if (min_pos != next)
			swap(a[min_pos], a[next]);
	}
}

// allows to define a new rule for comparison instead of "<" relation
bool my_comparison_function_int(int i, int j) { return (i>j); }

// overload operator < for Employee class
bool operator<(const Employee& a, const
	Employee& b)
{
	return a.get_salary() < b.get_salary();
}

int main()
{
	rand_seed();


	//Example 1: merge sort (increasing order)
	{
		vector<int> v(20);

		for (int i = 0; i < v.size(); i++)
			v[i] = rand_int(1, 100);

		cout << "Before:\n";
		print(v);
		cout << "After merge sort:\n";
		merge_sort(v, 0, v.size() - 1);
		print(v);

	}

	//Example 2: selection sort (increasing order)
	{
		vector<int> v(20);

		for (int i = 0; i < v.size(); i++)
			v[i] = rand_int(1, 100);

		cout << "\nBefore:\n";
		print(v);
		cout << "After selection sort:\n";
		selection_sort(v);
		print(v);

	}

	cout << "\n";

	//Example 3: Applying STL sort() of <algorithm> (increasing order)
	{
		vector<int> v(20);

		for (int i = 0; i < v.size(); i++)
			v[i] = rand_int(1, 100);

		cout << "\nBefore:\n";
		print(v);
		cout << "After STL sort:\n";
		sort(v.begin(), v.end());
		print(v);
	}
	
	cout << "\n";

	//Example 4: Applying STL sort() of <algorithm> (decreasing order)
	{
		vector<int> v(20);

		for (int i = 0; i < v.size(); i++)
			v[i] = rand_int(1, 100);

		cout << "\nBefore:\n";
		print(v);
		cout << "After STL sort (decreasing order):\n";
		sort(v.begin(), v.end(), my_comparison_function_int);
		print(v);
	}

	//Example 5: Sorting Employees by their salary
	{
		vector<int> v(10);

		for (int i = 0; i < v.size(); i++)
			v[i] = rand_int(1, 100);
		
		vector<Employee> e;

		for (int i = 0; i<v.size(); i++ )
		{
			stringstream ss;
			ss << i;
			string name = "E_" + ss.str();
			e.push_back(Employee(name, v[i]));
		}

		cout << "\nEmployees before:\n";
		for (int i = 0; i<e.size(); i++)
		{
			cout << e[i].get_name() << " ";
		}

		sort(e.begin(), e.end());

		cout << "\nEmployees after STL sort (increasing salaries order):\n";

		for (int i = 0; i<e.size(); i++)
		{
			cout << e[i].get_name() << " ";
		}

	}

	cout << "\n";

	//Example 6: Binary search in a sorted array (decreasing order)
	{
		int myints[] = { 1,2,3,4,5,4,3,2,1 };
		std::vector<int> v(myints, myints + 9); 

		cout << "\nBefore:\n";
		print(v);
		cout << "\nAfter STL sort (decreasing order):\n";
		sort(v.begin(), v.end(), my_comparison_function_int);
		print(v);

		// using default comparison:
		sort(v.begin(), v.end());

		cout << "looking for a 3... ";
		if (binary_search(v.begin(), v.end(), 3))
			cout << "found!\n"; else std::cout << "not found.\n";

		// using myfunction as comp:
		sort(v.begin(), v.end(), my_comparison_function_int);

		cout << "looking for a 6... ";
		if (binary_search(v.begin(), v.end(), 6, my_comparison_function_int))
			cout << "found!\n"; else cout << "not found.\n";

	}

	return 0;
}
