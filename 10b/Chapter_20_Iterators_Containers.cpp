#include<string>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<functional>
#include<ctime>
#include<algorithm>
#include<functional>
#include<set>
#include<map>
#include<cmath>
#include<vector>
#include<iostream>

using namespace std;

template<typename Type>
void print(Type & v, const string & sep = ", ")
{
    typename Type::iterator it;
    for (it = v.begin(); it != v.end(); ++it)
    {
        cout << *it;

        typename Type::iterator it_next = it;
        it_next++;

        if (it_next != v.end())  cout << sep;
    }
    cout << endl;
}

template<typename Type, typename IntType = int>
void print(Type * v, IntType v_size, const string & sep = ", ")
{

    for (auto i = 0; i<v_size; ++i)
    {
        cout << *(v + i);

        if (i != (v_size - 1))  cout << sep;
    }

    cout << endl;
}



int main()
{
    //example 1 declaration
    {
        cout << "Example 1----------------------\n\n";
        list<int> lst(10, 1.0);
        vector<int> vec(20, 2.0);
        print<list<int>>(lst);   // or print(lst)
        print<vector<int>>(vec); // or print(vec)


    }

    //example 2 iterators
    {
        cout << "\nExample 2----------------------\n\n";
        using vint_iterator = vector<int>::iterator;

        //copying elements using iterators
        int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
        vector<int> v(a, a + 10); //constructor that copies the range
        vector<int> z(v.begin(), v.end()); //constructor that copies the range

                                           //iterating through the elements
        vector<int>::iterator start = v.begin();
        vector<int>::iterator end = v.end();
        vector<int>::iterator pos;

        for (pos = start; pos != end; ++pos)
        {
            cout << *pos << endl;
        }

        pos--;
        pos--;
        pos--;
        pos--;
        pos += 3;
    }

    //example 3: fundamental containers list,vector,deque
    {
        cout << "\nExample 3----------------------\n\n";

        int a[10] = { 0,1,2,3,4,5,6,7,8,9 };

        list<int>   lst(a, a + 10);
        vector<int> vec(a, a + 10);
        deque<int>  deq(a, a + 10);

        list<int>::iterator   lst_it = lst.begin();
        vector<int>::iterator vec_it = vec.begin();
        deque<int>::iterator  dq_it = deq.begin();

        //generic (template) print function
        print<list<int>>(lst);
        print<vector<int>>(vec);
        print<deque<int>>(deq);
    }

    //example 4: stack, priority queue, queue

    {
        cout << "\nExample 4----------------------\n";


        cout << "stack:\n";
        stack<int> st; //stack
        st.push(2);
        st.push(3);
        st.push(1);

        while (!st.empty())
        {
            cout << st.top() << endl; //print the top
            st.pop();
        }

        cout << "queue:\n";
        queue<int> qu; //stack
        qu.push(2);
        qu.push(3);
        qu.push(1);

        while (!qu.empty())
        {
            cout << qu.front() << endl; // print the top
            qu.pop();
        }

        cout << "priority queue, < priority:\n";
        priority_queue<int> pq; //priority queue, by default priority is chosen using "<" operator
        pq.push(2);
        pq.push(3);
        pq.push(1);

        while (!pq.empty())
        {
            cout << pq.top() << endl; // print the top
            pq.pop();
        }

        {
            cout << "priority queue, > priority:\n";
            //non-default priority is chosen using ">" operator
            //underlying container used for priority case is vector<int>

            priority_queue<int, vector<int>, greater<int>> pq;
            pq.push(2);
            pq.push(3);
            pq.push(1);

            while (!pq.empty()) {
                cout << pq.top() << endl; // print the top
                pq.pop();
            }
        }


    }

    //example 5: sets
    {
        cout << "\nExample 5----------------------\n";

        set<int> a; // empty set
        set<int>::iterator it; //iterator

        a.insert(1);
        a.insert(2);
        a.insert(2);
        a.insert(3);
        a.insert(4);
        a.erase(3);
        a.erase(3); //if not found it will not be erase


        for (it = a.begin(); it != a.end(); it++)
        {
            cout << *it << " ";
        }

        cout << endl;

    }

    //example 5: sets
    {
        cout << "\nExample 6----------------------\n\n";

        pair<string, int> pr;

        //pr = make_pair<string, int>("aaa", 12);
        //cout << pr.first;
        //cout << pr.second;

        map<string, int> grades;
        grades["Joe"] = 90;
        grades["Julia"] = 86;
        grades["Romeo"] = 100;

        map<string, int>::iterator it;

        for (it = grades.begin(); it != grades.end(); it++)
        {
            cout << (*it).first << " -> " << (*it).second << endl;
        }

        string s;

        cout << "Enter a key to be erased: "; getline(cin, s);

        it = grades.find(s);

        if (it == grades.end()) // if not found
        {
            cout << "No such name in the list";
        }
        else
        {
            cout << "The pair " << (*it).first << " -> " << (*it).second
                << " is erased" << endl;

            it = grades.erase(it);

        }

        cout << endl;

    }
}