/*

Assignment: Implement a function: vector<string> generate_subsets(string s) that generates all subsets of characters of a string.
For example, the subsets of characters of the string "rum" are the eight strings "rum", "ru", "rm", "r", "um", "u", "m", ""
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


vector<string> generate_subsets(string s) 
{
	vector <string> v1;  
	if (s.length() == 0)
	{
		v1.push_back("");
		return v1;		
	} 
	string firstletter = s.substr(0, 1); 
	string rest = s.substr(1,string::npos); 


	for (int i = 0; i < s.length(); i++)
	{
	
		string conc_subs = (firstletter)+rest.substr(i, 1); 

		v1.push_back(conc_subs);		
	}

	vector<string> v2 = generate_subsets(rest); 


	for (int j = 0; j < v2.size(); j++) 
	{
		v1.push_back(v2[j]);
	}

	return v1;

}

int main() 
{
	string yesno = "y";
	string s;

	while (yesno == "y")
	{
		cout << "Enter a string:  ";
		getline(cin, s);

		vector<string> results = generate_subsets(s);
		results.insert(results.begin(), s); 
		
		int subsetcount = results.size();
		cout << subsetcount << " subsets:\n";

		for (int i = 0; i < results.size(); i++)
		{
			cout << "\"" << results[i] << "\"" << endl; 
		}

		cout << "Continue (y/n)? ";
		getline(cin, yesno);
	}
	system("pause");
	return 0;

} 