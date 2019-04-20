/*
Description: Pointers homework P7.6
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int g_indx = 0;
double maximum(double* a, int a_size)
{
	g_indx = 0;
	int asize = a_size;
	double *b = a;

	if (asize == 0)
	{
		cout << "Array size is 0, returning null..." << endl;
		return NULL;
	}

	else
	{

		double* maxi = b;
		for (int j = 0; j < asize; j++) 
		{
			if (*maxi < b[j]) 
			{
				*maxi = b[j]; 
				g_indx = j;
			}
		}
		return *maxi; 
	}
}
int main() {
	string nums; 
	string moredata = "y"; 
	unsigned int spacecount = 0; 
	double* arp = NULL; 
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

		double* array2 = new double[newsize]; 

		istringstream input(nums); 
		for (int i = 0; i < newsize; i++)
		{
			input >> array2[i]; 
		}

		cout << "maximal element: " << maximum(array2, newsize) << endl;
		cout << "index of the maximal element: " << g_indx << endl;  


		spacecount = 0; 
		cout << "Continue? (y/n)";
		getline(cin, moredata);
		cout << endl;

	} while (moredata == "y"); 

	system("pause");
	return 0;
}
