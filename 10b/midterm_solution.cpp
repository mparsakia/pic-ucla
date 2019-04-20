#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <sstream>


#define PROB 2

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


// PROBLEMS START HERE
//****************************************************************************

#if PROB==11

int main()
{
    int a[] = { 0, 0, 0, 0 };
    int * arr = a + 3;
    arr[-2] = -3; //*(arr-2)
    --arr;
    *(arr) = 2;
    //*(--arr) = 2;
    
    *(arr--) = 2;
    arr[1] = -1;
    *(arr - 2) = 4;
    
    /*for (int i = 0; i < 4; i++)
     cout << a[i] << endl;*/
    
    return 0;
}

// 4, -3, 2, -1

#endif // PROB==11


#if PROB==12

vector<int*> func(int* a, int a_size, int t)
{
    vector<int*> result;
    int* p;
    for (p = a; p < a + a_size; p++)
        if (*p <= t) result.push_back(p);
    return result;
}
int main() {
    const int a_size = 8;
    int a[a_size] = { 0, -2, 4, 3, 2, -1, 5, 0 };
    vector<int *> res = func(a, a_size, 1);
    for (int i = 0; i < res.size(); i++)
        cout << (res[i] - a) << "->" << *(res[i]) << "\n";
    return 0;
}

// Output:
//0->0
//1->-2
//5->-1
//7->0

#endif PROB==12


#if PROB==2

//21 protected is needed for the derived class to be able to access private
// datafields of the base class. virtual is a reserved word indicating that
// the dynamic binding will be used when one calls an overloaded method of
// the object of derived class when the object is accessed via a pointer.

// Base class
class Employee
{
public:
    Employee();
    Employee(string e_name, double e_salary)
    : name(e_name), salary(e_salary) { }
    void   set_salary(double new_salary) { salary = new_salary; }
    string get_name() const { return name; }
    double get_salary() const { return salary; }
    virtual void print() const
    {
        std::cout << "Employee: " << name
        << ", $" << salary << endl;
    }
    virtual ~Employee() { cout << "Employee: Bye Bye\n"; }
protected:
    string name;
    double salary;
};

//22
class Manager : public Employee
{
public:
    Manager(string e_name, string e_department, double e_salary) :
    Employee(e_name, e_salary), department(e_department) {
    }
    virtual void print() const
    {
        std::cout << "Manager: " << name
        << ", "
        << department
        << ", $" << salary << endl;
    }
    virtual ~Manager() { cout << "Manager: Bye Bye\n"; }
protected:
    string department;
};


int main()
{
    Employee* p1, *p2;
    
    p1 = new Employee("Alex Johnson", 60000);
    
    p2 = new Manager("Lisa Smith", "Transportation", 75000);
    
    p1->print(); p2->print();
    
    delete p1;    delete p2;
    
    cout << "\n";
    
}

//Output:
//Employee: Alex Johnson, $60000
//Manager:  Lisa Smith, Transportation, $75000
//Employee: Bye Bye
//Manager: Bye Bye
//Employee: Bye Bye

#endif //PROB==2



#if PROB == 31

unsigned int word_count(const string & s)
{
    stringstream ss(s);
    
    unsigned int counter = 0;
    
    while (!ss.fail()) //!ss.eof()
    {
        string input;

        ss >> input;

        counter++;

    }
//    string input;
//    while (ss>>input) counter++;
    return counter;
}
int main()
{
    string s = " aaa bbb cccs ";
    cout << word_count(s) << endl;
}
#endif // PROB 3


#if PROB == 32

void DataSum(string filename)
{
    ifstream ifs(filename);
    int sum = 0;
    int n = 0;
    ifs.seekg(0, ios::beg);
    while (ifs.good())
    {
        int x;
        ifs >> x;
        // check if input fails. If not sum up the value and increase the counter.
        if (!ifs.fail())
        {
            sum += x;
            n++;
        }
    }
    ifs.close();
    ofstream ofs("stat_"+filename, ofstream::trunc);
    ofs << n << "\n";
    ofs << sum;
    ofs.close();
    
}

int main()
{
    stringstream ss;
    
    ss << "2\n3\n4";
    
    string_to_file(ss.str(), string("data.txt"));
    
    int n, sum;
    
    DataSum("data.txt");
    
}
#endif // PROB 32
