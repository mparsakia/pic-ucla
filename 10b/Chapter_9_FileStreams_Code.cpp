#include <vector> 
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

// creates a new file or discards the content and puts a string into it

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


int main()
{
	//***********************************************************
	//example 0 write to file a string discarding the old content
	//***********************************************************
	
	string_to_file("hello world\nhello world", "t0.txt");


	//***********************************************************
	// example 1: input stream. read the first word from the file
	//***********************************************************

	string fname = "t1.txt";

	// create a dummy file 
	string_to_file("hello world", fname); 

	// open input stream
	ifstream ifs;

	ifs.open(fname, ifstream::in);	//discards the content
	
	cout << "pos_get = " << ifs.tellg() << endl; // check get-position

	string s; ifs >> s;

	cout << s << "\n";

	ifs.close();



	//***********************************************************
	// example 2: input stream. read the last 5 characters 
	//***********************************************************

	string fname = "t2.txt";

	// create dummy file 
	string_to_file("hello world", fname);

	// open input stream
	
	ifstream ifs;

	ifs.open(fname, ifstream::in | ifstream::ate);

	long pos = ifs.tellg();

	cout << "pos_get = " << ifs.tellg() << endl;

	ifs.seekg(pos - 5, ios::beg);

	pos = ifs.tellg();

	cout << "pos_get = " << ifs.tellg() << endl;

	string s;

	ifs >> s;

	cout << s << "\n";

	ifs.close();

	

	//***********************************************************
	// example 3: output stream, default parameters
	//***********************************************************

	string fname = "t3.txt";

	// create a dummy file with some text
	string_to_file("class of 2018", fname);

	ofstream ofs;

	ofs.open(fname, ifstream::out | ifstream::trunc); 
	// truncate mode by default discards the content

	ofs << "hallo world"; // this stuff gets into the stream (buffer) 

	//oops we made a mistake, lets correct it
	ofs.seekp(1, ios::beg); // moves the put pointer to position 1

	ofs << "e"; // replaces 'a' with 'e'

	ofs.close();


	//***********************************************************
	// example 4: output stream: append
	//***********************************************************

	string fname = "t4.txt";

	// create a dummy file with some text
	string_to_file("hello world", fname);
	
	ofstream ofs;

	ofs.open(fname, ofstream::out | ofstream::app); // always append

	ofs.seekp(0, ios::beg); // moves the put pointer to 0

	long pos = ofs.tellp();

	cout << "pos_put = " << ofs.tellp() << endl;

	ofs << " again"; 
	// "append" option still puts the stuff at the end regardless of put being at 0
		
	ofs.close();
	


	//***********************************************************
	// example 5: output stream: writing into the existing file 
	//***********************************************************

	string fname = "t5.txt";

	// create a dummy file with some text
	string_to_file("hello world", fname);
	
	ofstream ofs;

	ofs.open(fname, ofstream::in | ofstream::out );

	ofs.seekp(0, ios::beg); // moves the put pointer to 0 from the end

	ofs << "again"; // adds stuff at the position

	ofs.close();



	//***********************************************************
	// example 6: count the number of characters in the file
	//***********************************************************

	string fname = "t6.txt";

	// create a dummy file with some text

	string_to_file("hello class\nhello class\nhello class", fname);
	
	ifstream ifs;

	ifs.open(fname, ifstream::in);

	ifs.seekg(0, ios::end); 

	//puts the pointer at the end

	cout << "numebr of characters = " << ifs.tellg() << endl;

	ifs.close();


	//***********************************************************
	// example 7: display the content of the file line by line
	//***********************************************************

	string fname = "t7.txt";

	// create a dummy file with some text

	ostringstream ss;

	ss << "hello class 1\n"
	  << "hello class 2\n"
	  << "hello class 3\n"
	  << "hello class 4\n";

	string_to_file(ss.str(), fname);
	

	// display the content of the file fname

	ifstream ifs;

	ifs.open(fname, ifstream::in);
	

	if (ifs.is_open())
	{
		cout << "the content of the file " << fname << endl;
		while (!ifs.eof())
		{
			string s;
			getline(ifs, s);
			cout << s << endl;
		}	
	}
	else
	{
		cout << "error opening file " << fname << "!\n";
	}

	ifs.close();

	return 0;
}

