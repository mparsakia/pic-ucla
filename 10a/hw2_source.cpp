/*
Description: Read in and calculate the ratio between two things. Input an integer and then a string, for two different things, the program outputs the information ratios.
*/


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	
	double quant1 = 0.0;
	double quant2 = 0.0;
	string string1;
	string string2;

	
	cout << fixed;
	cout << setprecision(2);

	
	cout << "How many in the first category?: " ;
	cin >> quant1 >> string1;
	cout << "How many in the second category?: " ;
	cin >> quant2 >> string2;
	cout <<	endl;

	
	int leftcolumn_setw = string1.length() + string2.length();
	
	
	cout << setw(leftcolumn_setw+8) << string1 << setw(10) << quant1 << endl;
	cout << setw(leftcolumn_setw+8) << string2 << setw(10) << quant2 << endl;

	
	double ratio_q1_to_q2 = quant1 / quant2;
	double ratio_q2_to_q1 = quant2 / quant1;
	
	
	string ratio_cout_string1;
	string ratio_cout_string2;

	

	int a = string1.length() - 1;
	ratio_cout_string1 = string1.erase(a, 1);
	int b = string2.length() - 1;	
	ratio_cout_string2 = string2.erase(b, 1);

	
	cout << setw(leftcolumn_setw) << ratio_cout_string1 + "-to-" + ratio_cout_string2 + " ratio" << setw(10) << ratio_q1_to_q2 << endl;
	cout << setw(leftcolumn_setw) << ratio_cout_string2 + "-to-" + ratio_cout_string1 + " ratio" << setw(10) << ratio_q2_to_q1 << endl;
	
	
	system("pause");
	return 0;
}