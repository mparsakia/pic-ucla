/*


Known bugs: Prints out extra "->", need to fix later, problem is in line 34 and 32 for the range of the loop...

*/

#include <iostream>		
#include <string>		
#include <cstring>		
#include <sstream>		
#include <fstream>		
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
using namespace std;

template<typename Iterator>
void print_using_iterators(Iterator posi, Iterator end)
{
	while (posi != end) 
	{
		cout << *posi << "->";
		posi++;
	}
} 

void sortlist(list<int> &lst)
{
	lst.sort();
	return;
}


int main() {

	ifstream ifs;
	list<int> mylist;
		
	int pushint;
	ifs.open("data1.txt");
	while (!ifs.eof())
	{
		ifs >> pushint;
		mylist.push_back(pushint);
	}
	ifs.close();

	list<int>::iterator iterpos;
	iterpos = mylist.begin();

	
	cout << "Iterating through the data in data1.txt\n";
	print_using_iterators(mylist.begin(), mylist.end());
	cout << endl;
	
	sortlist(mylist);

	cout << "Sorted list:\n";
	print_using_iterators(mylist.begin(), mylist.end());
	cout << endl;

	system("pause");
	return 0;
} 