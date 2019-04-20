/*

Assignment: Modify the selection sort algorithm given in the book to sort in descending order. Reads a list of ints from "data1.txt" into a vector
			then sorts it in descending order and displays the results. data1.txt only contains integers, and contains at least 1 number.

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

int max_pos(vector<int>&a, int from, int to)
{
	int maxpos = from; 
	int i = from + 1; 
	for (i; i <= to; i++) 
	{
		if (a[i] > a[maxpos]) 
		{
			maxpos = i;
		}
	}
	return maxpos; 

}

void desc_selection_sort(vector<int>& a)
{
	int next; 

	for (next = 0; next < a.size() - 1; next++) 
	{
		int maxim = max_pos(a, next, a.size() - 1); 

		if (maxim != next) 
		{
			swap(a[maxim], a[next]); 
		}
	}


}


int main() {
	
	ifstream filein;
	vector<int> intVec;
	int value = 0;
	
	filein.open("data1.txt"); 
	while (!filein.eof()) 
	{
		filein >> value; 
		intVec.push_back(value); 
	}
	filein.close(); 

	
	cout << "Before Sorting:" << endl;
		for (int i = 0; i < intVec.size(); i++) 
	{
		cout << intVec[i] << " ";
	}
	cout << endl;

	
	desc_selection_sort(intVec); 


	cout << "After Sorting (Descending Order):" << endl;
	for (int i = 0; i < intVec.size(); i++)
	{
		cout << intVec[i] << " "; 
	}
	cout << endl;
		

	system("pause");
	return 0;
	
} 