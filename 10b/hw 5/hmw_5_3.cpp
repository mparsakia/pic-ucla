/*

Assignment: Binary search ints from a file.


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

bool compare_ints(int i, int j) { return (i < j); }

bool binarysearch(vector<int>&v, int value, int &m)
{
	int beg_ind = 0;
	int end_ind = v.size();
	
	while (beg_ind < end_ind)
	{
		int mid = beg_ind + ((end_ind - beg_ind) / 2);
				
		if (v[mid] == value)	
		{
			m = &v[mid] - &v[0]; 
			return true;
		}

		else if (v[mid] > value)
		{
			end_ind = mid;
		}

		else
		{
			beg_ind = mid + 1;
		}
	}
	
	m = end_ind; 
	return false; 

}


int main() {

	ifstream filein;
	filein.open("data3.txt");

	vector<int> intvec;

	while (!filein.eof()) 
	{
		int myints = 0;
		filein >> myints;
		intvec.push_back(myints);
	}

	cout << "Before Sorting: \n";
	for (size_t i = 0; i < intvec.size(); i++)
	{	cout << intvec[i] << endl;	}
	
	sort(intvec.begin(), intvec.end(), compare_ints); 
	
	cout << "After Sorting: \n";
	for (size_t i = 0; i < intvec.size(); i++)
	{	cout << intvec[i] << endl;	} 
	string moredata = "y";
	while (moredata == "y")
	{
		cout << "Enter a value: \n";
		int value = 0;
		cin >> value;

		int ref_m = 0; 
		
		if (binarysearch(intvec, value, ref_m) == true)
		{
			cout << "Found. m=" << ref_m;
		}
		else
		{
			cout << "Not found.  m=" << ref_m;
		}
		cout << endl;
		cout << "Continue: (y/n)? ";
		cin >> moredata;
	}
	

cout << endl;
system("pause");
return 0;
} 