/*

Assignment Prompt:
Write a program that asks the user for a file name and displays the
number of characters, words, and lines in that file. Then have the program ask for
the name of the next file. When the user enters a file that doesn’t exist 
(such as the empty string), the program should exit.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <vector>
using namespace std;


int main() {
	
	ifstream filein;
	string fname;
	int nlines = 0;
	int nwords = 0;
		
	cout << "Enter a file name to open: ";
	getline(cin, fname);
	filein.open(fname.c_str()); 
	
	if (filein.fail()) 
	{
		cout << "File " << fname << "does not exist! Exit.\n";
	} 

	while(!filein.fail()) 
	{
		filein.seekg(0, filein.end); 
		long long charcount = filein.tellg(); 
		cout << "Number of Characters: " << charcount << "\n";
		filein.close(); 
	

		filein.open(fname.c_str());
		string words;
		stringstream sstr(words); 
		while (filein >> words)
		{
			nwords++;
		}
		cout << "Number of Words:      " << nwords << "\n";
		filein.close();
	

		filein.open(fname.c_str());
		string empty; 
		while (getline(filein, empty))  
		{
			nlines++;
		}
		cout << "Number of Newlines:   " << nlines << "\n\n";
		filein.close();
		

		fname = ""; 
		nlines = 0;
		nwords = 0;

		cout << "Enter a file name to open: ";
		getline(cin, fname);
		filein.open(fname.c_str());
		if (filein.fail())
		{
			cout << "File " << fname << "does not exist! Exit.\n";
			break;
		}
	}

	system("pause");
	return 0;
}      