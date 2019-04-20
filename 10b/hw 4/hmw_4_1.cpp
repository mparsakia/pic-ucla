/*

		
Assignment Prompt: 
6. Use recursion to implement a function int index_of(string s,string t) 
that returns the starting position of the first substring of the string s that matches t. 
Return –1 if t is not a substring of s. 

Hint: This is a bit trickier than Exercise P10.5, because you need to keep track of
how far the match is from the beginning of the sentence. Make that value a parameter
of a helper function
*/

#include <iostream>		
#include <string>		
#include <cstring>		
#include <sstream>		
#include <fstream>		
#include <vector>		
#include <cstdlib>		
#include <cctype>		
#include <iomanip>		


using namespace std; 


int count1 = 0;


int indexof(string &s, string &t)
{
	int sublength = t.length();
	int stringlen = s.length();

	if (sublength>stringlen)
	{
		return -1;  
	}

	if (s.substr(0, sublength) == t)
	{
		return count1; 
	}
	
	count1++; 
					
	s.erase(0, 1); 

	return indexof(s, t); 
}


int main() {
		

	string yesno = "y";
	string s;
	string t;

	while (yesno == "y")
	{
		cout << "Enter a string:  ";
		getline(cin, s);
		cout << "Enter a string to search for: ";
		getline(cin, t);

		if (indexof(s,t) != -1)
		{
			cout << "The Position = " << indexof(s, t) << endl;
		}
		else
		{
			cout << "Not found!\n";
		}

		count1 = 0; 
		cout << "Continue (y/n)? ";
		getline(cin, yesno);
	
	}
		system("pause");
		return 0;
	
} 