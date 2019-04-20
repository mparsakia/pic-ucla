#include <vector> 
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;



void string_to_file(string data, string fname)
{
	ofstream ofs;

	ofs.open(fname, ofstream::out | ofstream::trunc);

	if (ofs.is_open())
		ofs << data;
	else
		std::cout << "Error opening file";

	ofs.close();
}

void Celsius2Fahrenheit(ifstream& celsius_data)
{
	//define output file
	ofstream data_in_fahrenheit;
	data_in_fahrenheit.open("TemperaturesF.txt");

	//extract file from input
	double temperature;
	while (celsius_data >> temperature)
	{
		//convert from celsius to fahrenheit 
		temperature = temperature*9.0 / 5.0 + 32;

		//output the data in fahrenheit
		data_in_fahrenheit << temperature << endl;
	}
	//close output file
	data_in_fahrenheit.close();

}



// This function parses a string into words with a given separator. 

// const string & s - string to parse
// vector<string> & words - vector of words
// char sep - separator
// bool push_empty - whether an empty word between two separators is added
// Note that '\n' is not considered a separator in this algorithm
// To ignore \n one needs to modify the algorithm slightly

void parse_string( const string & s, vector<string> & words, char sep=' ', bool push_empty=false)
{
	words.resize(0);

	if (!s.empty()) 	
	{
		stringstream ss(s);
		
		while (!ss.eof())
		{			
			string data;

			// Comment: if one needs to ignore '\n' read a line
			// until \n is met and then parse the line into words
			
			getline(ss, data, sep);

			if (data == "")	
			{	
				if (push_empty) words.push_back(data);	
			}
			else
			{
				words.push_back(data);
			}
				
		}
	}	
}



int main()
{
	
	//********************************************************
	// Example 1: Parsing a string with a separator
	//********************************************************

	string s1 = "word1*word2*word3";

	vector<string> w;

	parse_string(s1, w, '*', false);
	
	string s2 = "word1***word2***word3";

	parse_string(s2, w, '*', false);

	string s3 = "word1***word2***word3";

	parse_string(s3, w, '*', true);

	string s4 = "word1    word2   word3";

	parse_string(s4, w, ' ', false);

	string s5 = "word1**\nword2**\nword3";

	parse_string(s5, w, '*', false);

	//********************************************************
	//Example 2: Converting Celcius into Fahrenheit example
	//********************************************************

	// create a file with Celcius temperatures

	string input_filename = "TemperaturesC.txt"; 

	string_to_file("20\n30\n40\n50\n60", input_filename);

	//input data stream 
	ifstream celsius_data;
	celsius_data.open(input_filename);

	//always test for fail state
	if (celsius_data.fail())
	{
		cout << "Failed to open file" << endl;
		return 1; 
	}

	//call temperature conversion function
	Celsius2Fahrenheit(celsius_data);

	//close files
	celsius_data.close();

	cout << endl;

	return 0;
}
