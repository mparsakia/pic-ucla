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




vector<string> generate_permutations(string word)
 {
	vector<string> result;

	//special cases

	if (word.length() <= 1)
	{	result.push_back(word);
		return result;	}
	
	//general case
	for (int i = 0; i < word.length(); i++)
	{
		string shorter_word = word.substr(0, i)	+ word.substr(i + 1);

		vector<string> shorter_permutations = generate_permutations(shorter_word);

		for (int j = 0; j < shorter_permutations.size(); j++)
		{
			string longer_word = word[i] + shorter_permutations[j];
			result.push_back(longer_word);
		}

	}
	return result;
}


bool substring_is_palindrome(string s, int start, int end)
{
	// Separate case for substrings of length 0 and 1
	if (start >= end) return true;

	if (s[start] == s[end])
		// Test substring that doesn’t contain the first and last letters
		return substring_is_palindrome(s, start + 1, end - 1);
	else
		return false;
}

bool is_palindrome(string s)
{
	return substring_is_palindrome(s, 0, s.length() - 1);
}

void print_int(int n)
{
	if (n > -1)
	{
		print_int(n - 1);
		cout << n << "\n";
	}
}


/**
6 Computes a Fibonacci number.
7 @param n an integer
8 @return the nth Fibonacci number
9 */

int fib(int n)
{
	if (n <= 2) return 1;
	else return fib(n - 1) + fib(n - 2);
}


/**
A class that describes triangle shapes like this:
[]
[][]
[][][]
 . . .
 */
	class Triangle
{
public:
	Triangle(int w);
	int get_area() const;
private:
	int width;
};

 /**
    Constructs a triangle with a given width.
    @param w the width of the triangle base
   */

	 Triangle::Triangle(int w)
	 {
		width = w;
	 }

 /**
    Computes the area of the triangle shape.
    @return the area
    */
	 int Triangle::get_area() const
	 {
	 if (width <= 0) return 0;
	 if (width == 1) return 1;
	 Triangle smaller_triangle(width - 1);
	 int smaller_area = smaller_triangle.get_area();
	 return smaller_area + width;
	 }


int main()
{

	////************************************
	////Example 0: Printing numbers 0,1,..n
	////************************************

	/*int n;
	cout << "Enter any nonnegative integer: "; cin >> n;
	print_int(n);*/


	////************************************
	////Example 1: Computing the area of a "Triangle"
	////************************************

	//Triangle t(4);
	//cout << "Area: " << t.get_area() << "\n";

	////************************************
	////Example 2: Permutations of a string:
	////************************************


	//string input = "world";

	//vector<string> v = generate_permutations(input);

	//for (int i = 0; i < v.size(); i++)
	//	cout << v[i] << "\n";


	////************************************
	////Example 3: Checking if a string is a palindrome
	////************************************

	//string str;
	//cout << "Enter a string: "; getline(cin, str);
	//
	//if (is_palindrome(str)) cout << str << " is a palindrome";
	//else				    cout << str << " is not a palindrome";



	////************************************
	////Example 4: Computing Fibonacci sequence
	////************************************

	//cout << "Enter n: ";
	//int n;
	//cin >> n;
	//int f = fib(n);
	//cout << "fib(" << n << ") = " << f << "\n";
	//return 0;

	return 0;
}





