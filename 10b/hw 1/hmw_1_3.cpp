/*
Description: Pointers homework P7.7 ( QUESTION 3 )
Known bugs: Input must be exactly (number space number space... 'enter') OR youll get bad output
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std; 
double reverse(double *a, int ar_size) 
{
	if (ar_size == 0) {	return 0.0;	}		
	
	int size = ar_size;
	double *p_st = a; 
	double *p_end = (a + size - 1); 
	
	while (p_st<p_end) 
	{
		double temp = *p_st; 
		*p_st = *p_end; 
		*p_end = temp; 
		p_st++; 
		p_end--; 
	}

	for (int x = 0; x < size; x++) 
	{
		if (x < (size - 1)) 
		{
			cout << a[x] << ", ";
		}
		else 
		{
			cout << a[x] << " \n";
		}
	} 

}


int main() {
	string moredata = "y"; 
	string nums; 
	unsigned int spacecount = 0; 
	int newsize = 0; 

	do 
	{
		cout << "Enter a list of numbers: ";
		getline(cin, nums);


		for (int i = 0; i < nums.length(); i++)
		{
			if (' ' == nums[i])
			{ 
				spacecount++;
			}

		} 

		newsize = spacecount + 1; 

		double *p_dynarr = new double[newsize]; 

		istringstream input(nums); 
		for (int i = 0; i < newsize; i++)
		{
			input >> p_dynarr[i]; 
		}

		reverse(p_dynarr, newsize);

		p_dynarr = NULL; 
		delete p_dynarr; 
		nums = ""; 
		newsize = 0;
		spacecount = 0;

		cout << endl;
		cout << "Continue? (y/n)";
		getline(cin, moredata);
		cout << endl;

	} while (moredata == "y");

	system("pause");
	return 0;
}
