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

vector<string> globalresult; 

vector<string> generate_substrings(string s) 
{ 

	if (s.length() == 0)
	{
		globalresult.push_back("");
		return globalresult;
	}


	if (s.length() == 1)
	{
		globalresult.push_back(s);
		globalresult.push_back("");
		return globalresult;
	} 
	string strcopy = s; 
	string firstletter = s.substr(0, 1); 
	strcopy.erase(0, 1); 

	for (int i = 0; i < s.length(); i++)
	{

		globalresult.push_back(firstletter + strcopy.substr(0, i)); 

	}
		
	return generate_substrings(strcopy);

} 



int main() {
		

	string yesno = "y";
	string s;

	while (yesno == "y")
	{
		cout << "Enter a string:  ";
		getline(cin, s);

	
		vector<string> results = generate_substrings(s); 

		for (int i = 0; i < results.size(); i++)
		{
			cout << "\"" << results[i] << "\"" << endl; 
		}

		globalresult.clear(); 


		cout << "Continue (y/n)? ";
		getline(cin, yesno);
	
	}
		system("pause");
		return 0;
	
} 