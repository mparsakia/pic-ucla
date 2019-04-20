/*

Homework: 6							Problem: 2




*/

#include <iostream>	
#include <cassert> 
#include <string>		
#include <cstring>		
#include <sstream>		
#include <fstream>		
#include <vector>
#include <algorithm>     
using namespace std;


class List;
class Iterator;

class Node
{
public:
	Node(string s); 
	~Node() {} 
private:
	string data;
	Node* previous;
	Node* next;
	friend class List;
	friend class Iterator;
};

class List
{
public:
	
	List(); 
	~List(); 
	void push_back(string data); 

	void push_front(string data); 

	void insert(Iterator iter, string s); 
	Iterator erase(Iterator iter); 
	Iterator begin(); 
	Iterator end(); 
	bool empty();

private:
	Node * first;
	Node* last;
	friend class Iterator;
};

class Iterator
{
public:

	Iterator(); 
	Iterator(const Iterator & pos); 
	string get() const; 
	void next(); 
	void previous(); 
	bool equals(Iterator b) const;  
	bool operator==(const Iterator& b) const;
	bool operator!=(const Iterator& b) const;
	Iterator operator++(int unused); 
	Iterator& operator++(); 
	Iterator operator--(int unused); 
	Iterator& operator--(); 
	string operator*() const;


private:
	Node * position;
	List* container;		
	friend class List;
};

Node::Node(string s)
{
	data = s;
	previous = NULL;
	next = NULL;
}

List::List()
{
	first = NULL;
	last = NULL;
}

List::~List()
{

	if (!empty()) 
	{

		Node* node = this->first;

		while (node->next != NULL)
		{
			node = node->next; 

			delete node->previous; 
		}

		if (node->next == NULL) 
		{
			delete node;
		}
	}

}

bool List::empty()
{
	return (last == NULL);
}

void List::push_back(string data)
{
	Node* new_node = new Node(data);
	if (last == NULL) 
	{
		first = new_node;
		last = new_node;
	}
	else
	{
		new_node->previous = last;
		last->next = new_node;
		last = new_node;
	}
}

void List::push_front(string data)
{
	Node* new_node = new Node(data);
	if (last == NULL) 
	{	
		first = new_node; 
		last = new_node;
	}
	else 
	{		
		last->next = new_node; 
		last = new_node; 
	} 
	
}

void List::insert(Iterator iter, string s)
{
	if (iter.position == NULL)
	{
		push_back(s);
		return;
	}

	Node* after = iter.position;
	Node* before = after->previous;
	Node* new_node = new Node(s);
	new_node->previous = before;
	new_node->next = after;
	after->previous = new_node;
	if (before == NULL) 
		first = new_node;
	else
		before->next = new_node;
}

Iterator List::erase(Iterator iter)
{
	assert(iter.position != NULL);
	Node* remove = iter.position;
	Node* before = remove->previous;
	Node* after = remove->next;
	if (remove == first)
		first = after;
	else
		before->next = after;
	if (remove == last)
		last = before;
	else
		after->previous = before;
	delete remove;
	Iterator r;
	r.position = after;
	r.container = this;
	return r;
}

Iterator List::begin()
{
	Iterator iter;
	iter.position = first;
	iter.container = this;
	return iter;
}

Iterator List::end()
{
	Iterator iter;
	iter.position = NULL;
	iter.container = this;
	return iter;
}


Iterator::Iterator()
{
	position = NULL;
	container = NULL;
}

Iterator::Iterator(const Iterator & pos)
{
	(*this) = pos;
}

string Iterator::get() const
{
	assert(position != NULL); 
	return position->data;
}

void Iterator::next()
{
	assert(position != NULL);
	position = position->next;
}

void Iterator::previous()
{
	assert(position != container->first);
	if (position == NULL)
		position = container->last;
	else
		position = position->previous;
}

bool Iterator::equals(Iterator b) const
{
	return position == b.position;
}

bool Iterator::operator==(const Iterator& b) const
{
	return position == b.position;
}

bool Iterator::operator!=(const Iterator& b) const
{
	return position != b.position;
}

Iterator & Iterator::operator++() 
{
	assert(position != NULL);
	position = position->next;
	return *this;
}

Iterator Iterator::operator++(int unused) 
{
	assert(position != NULL);

	Iterator clone(*this);

	position = position->next;

	return clone;
}


Iterator & Iterator::operator--() 
{

	assert(position != container->first);
	if (position == NULL)
		position = container->last;
	else
		position = position->previous;

	return *this;
}

Iterator Iterator::operator--(int unused)
{

	assert(position != container->first);

	Iterator clone(*this);

	if (position == NULL)
		position = container->last;
	else
		position = position->previous;

	return clone;
}

string Iterator::operator*() const
{
	assert(position != NULL);
	return position->data;
} 



int main() {

	ifstream ifs;
	List mylist;
		
	string pushstr;
	ifs.open("data2.txt");
	while (!ifs.eof())
	{
		ifs >> pushstr;
		mylist.push_back(pushstr);
	}
	ifs.close();

	
	Iterator pos; 
	pos = mylist.begin(); 

	
	cout << "Iterating through the list in data2.txt:\n\n"; 
	for (pos = mylist.begin(); !pos.equals(mylist.end()); pos.next()) 
	{
		cout << pos.get() << "->";
	}
	

	string domore = "y";
	while (domore == "y")
	{
	
		cout << "\n\nTesting removal, enter the element to remove: ";
		string removethis;
		cin >> removethis;
		bool is_in_list = false; 

		for (pos = mylist.begin(); !pos.equals(mylist.end()); pos.next())
		{
			if (pos.get() == removethis)		
			{
				is_in_list = true;
				mylist.erase(pos); 
				break; 
			} 

		}

		if (is_in_list == false)
		{
			cout << "\nThere is no such element in the list.\n";
			
		}
		else
		{
			cout << "\nPrinting updated list:\n";
			for (pos = mylist.begin(); !pos.equals(mylist.end()); pos.next()) 
			{
				cout << pos.get() << "->";
			}
		}	
	

		cout << "\n\nContinue erasing? (y/n): ";
		cin >> domore;

	}


	system("pause");
	return 0;
} 