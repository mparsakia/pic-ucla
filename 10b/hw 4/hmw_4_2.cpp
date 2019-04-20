/*

Assignment:
Implement a function: vector<string> generate_subsets(string s) that generates all subsets of characters of a string.
For example, the subsets of characters of the string "rum" are the eight strings "rum", "ru", "rm", "r", "um", "u", "m", "".
Note that the subsets don’t have to be substrings—for example, "rm" isn’t a substring of "rum".

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

vector<string> generate_substrings(string s) 
{
	vector<string> results; 
	if (s.length() == 0)
	{
		results.push_back("");
		return results;
	}
	if (s.length() == 1)
	{
		results.push_back(s);
		results.push_back("");
		return results;
	} 
	string firstletter = s.substr(0, 1); 
	string rest = s.substr(1, string::npos); 
	
	for (int i = 0; i < s.length(); i++)
	{
		results.push_back(firstletter + rest.substr(0,i)); 
	}
	
	vector<string>v2 = generate_substrings(rest); 

	for (int a = 0; a < v2.size(); a++) 
	{
		results.push_back(v2[a]); 
	}
	return results;
}


int main() {


	string yesno = "y";
	string s;

	while (yesno == "y")
	{
		cout << "Enter a string:  ";
		getline(cin, s);


		vector<string> results1 = generate_substrings(s); 

		for (int i = 0; i < results1.size(); i++)
		{
			cout << "\"" << results1[i] << "\"" << endl; 
		}

		cout << "Continue (y/n)? ";
		getline(cin, yesno);

	}
	system("pause");
	return 0;

} 