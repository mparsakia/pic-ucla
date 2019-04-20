/*

Description: Pointers homework		( QUESTION 4 )
Known bugs: Unfinished...
*/

#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std; 


void newtonull(char a[], int size) 
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] == '\n')
		{ 
			a[i] = '\0';
			
		}
	}

}



int main() {
	string morechars = "y";
	string mytext = "";
	int counter = 0;
	char buffer[1000];
	char *lines = new char[100]; 
	int buffcount = 0;
	
	

	
		cout << "Enter a line: " << endl;
		getline(cin, mytext);
		strcpy_s(buffer, mytext.c_str());
		counter = counter + mytext.length();

		cout << "Add more lines? (y/n): " << endl;
		getline(cin, morechars);

		while (1000 >= (counter)+(mytext.length()) && morechars == "y")
		{
			cout << "Enter a line: " << endl;
			getline(cin, mytext);
			
			mytext += '\0'; 
			mytext += '\0'; 

			strcat_s(buffer, mytext.c_str());
			counter = counter + mytext.length();

			cout << "Add more lines? (y/n): " << endl;
			getline(cin, morechars);
		}  
		for (int i = 0; i < 1000; i++)
		{
			cout << buffer[i];
		} 
		cout << "\n\n DEBUG counter:" << counter; 
		for (int i = 0; i < 1000; i++)
		{
			if (buffer[i] == '\0')
			{
				cout << "\n DEBUG Null found at index: " << i << "\n";
			}
		}


		



	
	if (counter >= 1000)
	{
		cout << "Buffer is full!" << endl;
	}

	system("pause");
	return 0;
}         



