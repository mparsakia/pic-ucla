/*

Known bugs: 
		There is a strange problem when reversing a "forwards" file, the reversed text does not display the tab.
		however, if you reverse that file again (reversed file to forwards) the tab displays! I assume this works properly
		as the tab character is not being modified I believe, and I think its just a problem with my console displaying properly.


Assignment Prompt: Reverse a file.
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


string reverse_string(string reversethis)		
{
	string temp = reversethis;
	string tempcopy;

	for (int i = temp.length() - 1; i >= 0; i--) 
	{
		tempcopy.push_back(temp[i]); 
	}

	return tempcopy; 
}


int main() {
		
	ifstream filein;
	string fname; 
	cout << "Enter a file name to open: ";
	getline(cin, fname);
	filein.open(fname.c_str()); 
	if (filein.fail())	
	{
		cout << "File " << fname << "does not exist! Exit.\n";
		filein.close();
		return 1;
	}
	filein.close();
	filein.open(fname.c_str()); 
	if (filein.is_open())
	{
		cout << "Original file " << fname << " content:\n";
		while (!filein.eof())
		{
			string s;		
			getline(filein, s);
			cout << s << endl;
		}
	}
	filein.close();
	filein.open(fname.c_str()); 
	string filestring;
	getline(filein, filestring, '\0');

	string reversed = reverse_string(filestring);  
	filein.close(); 
	ofstream fileout;
	fileout.open(fname.c_str());
	fileout << reversed; 
	fileout.close(); 
	filein.open(fname.c_str()); 
	cout << endl;
	if (filein.is_open())
	{
		cout << "Reversed file " << fname << " content:\n";
		while (!filein.eof())
		{
			string s;
			getline(filein, s);
			cout << s << endl;
		}
	}
	filein.close(); 

	cout << endl;

	
	system("pause");
	return 0;
} 