/*

Homework: 6							Problem: 3
Crunch some prime numbers and test how long the algorithm takes


*/

#include <iostream>	
#include <cassert>		
#include <string>		
#include <cstring>		
#include <sstream>		
#include <fstream>		
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iterator>
#include <deque>
#include <ctime>
using namespace std;


int main() {

	string more = "y";
	while (more == "y")
	{
		set<int> myset; 
		set<int>::iterator pos; 
		int givenum; 

		cout << "Enter any positive int: ";
		cin >> givenum;
		cout << endl;
		int sqrtnum = sqrt(givenum); 


		for (size_t i = 1; i <= givenum; i++)
		{
			myset.insert(i); 
		}


		int counter = 0;
		int cutoff = sqrtnum; 

		for (int i = 2; i <= cutoff; i++)
		{
			cout << "Removing the elements divisible by " << i << ":\n";

			for (auto pos = myset.begin(); pos != myset.end();) 
			{
				if (((*pos)%i == 0) && ((*pos) != i)) 
				{
					pos	= myset.erase(pos);  
				}
				else
				{
					pos++; 
				}

			} 
			for (pos = myset.begin(); pos != myset.end(); pos++)
			{
				if (next(pos, 1) != myset.end()) 
				{
					cout << *pos << ", ";
				}
				else
				{
					cout << *pos;
				}
			}
			cout << endl;
		}

		
			

		cout << "Prime numbers not exceeding " << givenum << ": \n";
		for (pos = myset.begin(); pos != myset.end(); pos++)
		{
			if (next(pos, 1) != myset.end()) 
			{
				cout << *pos << ", ";
			}
			else
			{
				cout << *pos;
			}
		}

		cout << "\n\nContinue (y/n)? ";
		cin >> more;
	}

	cout << "\nComplexity check for n = 10^4, 10^5, 10^6:\n"; 
	{
		time_t starttime; 
		time_t stoptime;
		time(&starttime); 
		set<int> myset;
		set<int>::iterator pos;
		int givenum = 10000;
		int sqrtnum = sqrt(givenum);
					
		for (size_t i = 1; i <= givenum; i++)
		{
			myset.insert(i);		
		}

		int cutoff = sqrtnum;

		for (int i = 2; i <= cutoff; i++)
		{

			for (auto pos = myset.begin(); pos != myset.end();)		
			{
				if (((*pos) % i == 0) && ((*pos) != i))					
				{
					pos = myset.erase(pos);								
																		
				}
				else
				{
					pos++;							
				}

			}
			
		}
		
		time(&stoptime); 

		double seconds = difftime(stoptime,starttime);
		cout << "Time (sec) for computing primes not exceeding 10000: " << seconds;
		cout << endl;
	} 
	{
		time_t starttime; 
		time_t stoptime;
		time(&starttime); 
		set<int> myset;
		set<int>::iterator pos;
		int givenum = 100000;
		int sqrtnum = sqrt(givenum);

		for (size_t i = 1; i <= givenum; i++)
		{
			myset.insert(i);
		}

		int cutoff = sqrtnum;

		for (int i = 2; i <= cutoff; i++)
		{

			for (auto pos = myset.begin(); pos != myset.end();)
			{
				if (((*pos) % i == 0) && ((*pos) != i))
				{
					pos = myset.erase(pos);

				}
				else
				{
					pos++;
				}

			}

		}

		time(&stoptime); 

		double seconds = difftime(stoptime, starttime);
		cout << "Time (sec) for computing primes not exceeding 100000: " << seconds;
		cout << endl;



	} 
	{
		time_t starttime; 
		time_t stoptime;
		time(&starttime); 
		set<int> myset;
		set<int>::iterator pos;
		int givenum = 1000000;
		int sqrtnum = sqrt(givenum);

		for (size_t i = 1; i <= givenum; i++)
		{
			myset.insert(i);
		}

		int cutoff = sqrtnum;

		for (int i = 2; i <= cutoff; i++)
		{

			for (auto pos = myset.begin(); pos != myset.end();)
			{
				if (((*pos) % i == 0) && ((*pos) != i))
				{
					pos = myset.erase(pos);

				}
				else
				{
					pos++;
				}

			}

		}

		time(&stoptime); 

		double seconds = difftime(stoptime, starttime);
		cout << "Time (sec) for computing primes not exceeding 1000000: " << seconds;
		cout << endl;
	}


	system("pause");
	return 0;
} 