/*

Assignment Prompt:
Implement a base class Appointment and derived classes Onetime, Daily,
Weekly, and Monthly. An appointment has a description (for example, “see the dentist”)
and a date and time. Write a virtual function occurs_on(int year, int month,
int day) that checks whether the appointment occurs on that date. For example, for
a monthly appointment, you must check whether the day of the month matches.
Then fill a vector of Appointment* with a mixture of appointments. Have the user
enter a date and print out all appointments that happen on that date.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

const int daysinyear = 365; 
const int daysinleap = 366; 
const int leap_start_year = 1582;
const int daysnoleap[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 


class Appointment {
public:
	Appointment();
	Appointment(int mon, int day, int year, int hour, int minute, string descrip);
	int getmonth(); 
	int getday(); 
	int getyear(); 
	virtual bool occurs_on(int mo, int dy, int yr); 
	virtual void print();


protected: 
	string desc;
	int mm;
	int dd;
	int yyyy;
	int hr;
	int min;
};

bool Appointment::occurs_on(int mo, int dy, int yr) { return 0; } 
int Appointment::getmonth() { return mm; }
int Appointment::getday() { return dd; }
int Appointment::getyear() { return yyyy; }

Appointment::Appointment() 
{
	this->desc = "APPOINTMENT";
	this->min = 01;
	this->hr = 01;
	this->yyyy = 0001;
	this->dd = 01;
	this->mm = 01;
}

Appointment::Appointment(int mon, int day, int year, int hour, int minute, string descrip)
{
	this->desc = descrip;
	this->min = minute;
	this->hr = hour;
	this->yyyy = year;
	this->dd = day;
	this->mm = mon;
} 
void Appointment::print()
{ 
	if ((hr <= 9) && (min <= 9))
	{
		cout << desc << ", " << "0" << hr << ":" << "0" << min << "\n";

	}
	else if (hr <= 9 && min > 9)
	{
		cout << desc << ", " << "0" << hr << ":" << min << "\n";
	}
	else if (hr > 9 && min <= 9)
	{
		cout << desc << ", " << hr << ":" << "0" << min << "\n";
	}
	else
	{
		cout << desc << ", " << hr << ":" << min << "\n";

	}
}


class Daily : public Appointment {
public:
	Daily();
	Daily(int mon, int day, int year, int hour, int minute, string descrip);
	bool occurs_on(int mo, int dy, int yr); 
	void print();
}; 
Daily::Daily() : Appointment() { 
	this->desc = "DAILY";
	this->min = 01;
	this->hr = 01;
	this->yyyy = 0001;
	this->dd = 01;
	this->mm = 01;
}

Daily::Daily(int mon, int day, int year, int hour, int minute, string descrip):Appointment(mon,day,year,hour,minute,descrip)
{ 
	this->desc = descrip;
	this->min = minute;
	this->hr = hour;
	this->yyyy = year;
	this->dd = day;
	this->mm = mon;
}

bool Daily::occurs_on(int mo, int dy, int yr) { return true; }  
void Daily::print()
{
	if ((hr <= 9) && (min <= 9))
	{
		cout << desc << ", " << "0" << hr << ":" << "0" << min << "\n";

	}
	else if (hr <= 9 && min > 9)
	{
		cout << desc << ", " << "0" << hr << ":" << min << "\n";
	}
	else if (hr > 9 && min <= 9)
	{
		cout << desc << ", " << hr << ":" << "0" << min << "\n";
	}
	else
	{
		cout << desc << ", " << hr << ":" << min << "\n";

	}
}


class Onetime : public Appointment {
public:
	Onetime();
	Onetime(int mon, int day, int yer, int hour, int minute, string descrip);
	bool occurs_on(int mo, int dy, int yr);
	void print();
};


Onetime::Onetime() : Appointment() { 
	this->desc = "ONETIME";
	this->min = 01;
	this->hr = 01;
	this->yyyy = 0001;
	this->dd = 01;
	this->mm = 01;
}

Onetime::Onetime(int mon, int day, int year, int hour, int minute, string descrip):Appointment(mon, day, year, hour, minute, descrip)
{
	this->desc = descrip;
	this->min = minute;
	this->hr = hour;
	this->yyyy = year;
	this->dd = day;
	this->mm = mon;
}

void Onetime::print()
{
	if ((hr <= 9) && (min <= 9))
	{
		cout << desc << ", " << "0" << hr << ":" << "0" << min << "\n";

	}
	else if (hr <= 9 && min > 9)
	{
		cout << desc << ", " << "0" << hr << ":" << min << "\n";
	}
	else if (hr > 9 && min <= 9)
	{
		cout << desc << ", " << hr << ":" << "0" << min << "\n";
	}
	else
	{
		cout << desc << ", " << hr << ":" << min << "\n";

	}
}


bool Onetime::occurs_on(int mo, int dy, int yr) 
{
	if (this->getmonth() == mo){
		if (this->getday() == dy) {
			if (this->getyear() == yr) {
				return true;
			}
		}
	}
	
 return false;

}

class Monthly : public Appointment {
public:
	Monthly();
	Monthly(int mon, int day, int yer, int hour, int minute, string descrip);
	bool occurs_on(int mo, int dy, int yr);
	void print();
};



Monthly::Monthly() : Appointment() { 
	this->desc = "MONTHLY";
	this->min = 01;
	this->hr = 01;
	this->yyyy = 0001;
	this->dd = 01;
	this->mm = 01;
}

Monthly::Monthly(int mon, int day, int year, int hour, int minute, string descrip) :Appointment(mon, day, year, hour, minute, descrip)
{
	this->desc = descrip;
	this->min = minute;
	this->hr = hour;
	this->yyyy = year;
	this->dd = day;
	this->mm = mon;
}

bool Monthly::occurs_on(int mo, int dy, int yr) {
	if (this->getday() == dy) { 
		return true;
	}
	else { 
		return false;
	}

}

void Monthly::print()
{
	if ((hr <= 9) && (min <= 9))
	{
		cout << desc << ", " << "0" << hr << ":" << "0" << min << "\n";

	}
	else if (hr <= 9 && min > 9)
	{
		cout << desc << ", " << "0" << hr << ":" << min << "\n";
	}
	else if (hr > 9 && min <= 9)
	{
		cout << desc << ", " << hr << ":" << "0" << min << "\n";
	}
	else
	{
		cout << desc << ", " << hr << ":" << min << "\n";

	}
}

class Weekly : public Appointment {
public:
	Weekly();
	Weekly(int mon, int day, int yer, int hour, int minute, string descrip);
	bool occurs_on(int mo, int dy, int yr);
	void print();
};


Weekly::Weekly() : Appointment() { 
	this->desc = "WEEKLY";
	this->min = 01;
	this->hr = 01;
	this->yyyy = 0001;
	this->dd = 01;
	this->mm = 01;
}

Weekly::Weekly (int mon, int day, int year, int hour, int minute, string descrip) : Appointment(mon, day, year, hour, minute, descrip)
{
	this->desc = descrip;
	this->min = minute;
	this->hr = hour;
	this->yyyy = year;
	this->dd = day;
	this->mm = mon;
}  

bool Weekly::occurs_on(int mo, int dy, int yr)
{

	int tmo = mo; 
	int tdy = dy; 
	int tyr = yr; 

	if (tmo == 1)
	{
		tmo = 13;
		tyr--;
	}
	if (tmo == 2)
	{
		tmo = 14;
		tyr--;
	}
	int day = tdy; 
	int month = tmo; 
	int modyear = tyr % 100; 
	int divyear = tyr / 100; 
	int formulas = day + 13 * (month + 1) / 5 + modyear + modyear / 4 + divyear / 4 + 5 * divyear; 
	formulas = formulas % 7;

	int obj_mo = this->getmonth(); 
	int obj_yr = this->getyear(); 
	int obj_dy = this->getday(); 

	if (obj_mo == 1)
	{
		obj_mo = 13;
		obj_yr--;
	}
	if (obj_mo == 2)
	{
		obj_mo = 14;
		obj_yr--;
	}
	int day2 = tdy; 
	int month2 = tmo; 
	int modyear2 = tyr % 100; 
	int divyear2 = tyr / 100; 
	int formulas2 = day2 + 13 * (month2 + 1) / 5 + modyear2 + modyear2 / 4 + divyear2 / 4 + 5 * divyear2; 
	formulas2 = formulas2 % 7;


	if (formulas == formulas2) 
	{
		return true; 
	}
	else
	{
		return false; 
	}
}


void Weekly::print()
{
	if ((hr <= 9) && (min <= 9))
	{
		cout << desc << ", " << "0" << hr << ":" << "0" << min << "\n";

	}
	else if (hr <= 9 && min > 9)
	{
		cout << desc << ", " << "0" << hr << ":" << min << "\n";
	}
	else if (hr > 9 && min <= 9)
	{
		cout << desc << ", " << hr << ":" << "0" << min << "\n";
	}
	else
	{
		cout << desc << ", " << hr << ":" << min << "\n";

	}
}



int main() {
	
	string more = "y";
	vector<Appointment*> appsvect;
	
	cout << "Please include the zero for hours & minutes between 00 to 09 (ex: 02:09)\n\n";
	cout << "Enter the list of appointments.\n";

	while (more == "y")
	{
		string description;
		string subclass;
		string date;
		string time;
		
		cout << "Appointment's description: ";
		getline(cin, description);
		cout << "Appointment's type (Daily, Weekly, Onetime, Monthly): ";
		getline(cin, subclass);
		cout << "Appointment's starting date (mm/dd/yyyy): ";
		getline(cin, date); 
		cout << "Appointment's time [24hr, include 0s](hh:mm): ";
		getline(cin, time);    
		string subyear = date.substr(6, 10); 
		string submonth = date.substr(0, 2); 
		string subday = date.substr(3, 2); 
		int year_stoi = stoi(subyear); 
		int month_stoi = stoi(submonth);
		int day_stoi = stoi(subday);  
		string subhours = time.substr(0, 2);
		string subminutes = time.substr(3, 2);
		int hours_stoi = stoi(subhours);
		int minutes_stoi = stoi(subminutes); 
		if (subclass == "Monthly")
		{
			appsvect.push_back(new Monthly(month_stoi, day_stoi, year_stoi, hours_stoi, minutes_stoi, description));
		}
		else if (subclass == "Weekly")
		{
			appsvect.push_back(new Weekly(month_stoi, day_stoi, year_stoi, hours_stoi, minutes_stoi, description));
		}
		else if (subclass == "Daily")
		{
			appsvect.push_back(new Daily(month_stoi, day_stoi, year_stoi, hours_stoi, minutes_stoi, description));
		}
		else if (subclass == "Onetime")
		{
			appsvect.push_back(new Onetime(month_stoi, day_stoi, year_stoi, hours_stoi, minutes_stoi, description));
		}
		else
		{
			cout << "There was an error, please try again, appointment type is case sensitive.\n";
		}
				
		cout << "\nAnother appointment (y/n)?  ";
		getline(cin, more);
		cout << endl;
	}

	cout << "---------------------------------------------\n";
	string date2;
	cout << "Enter a date to check appointments: ";
	getline(cin, date2);
	cout << endl;

	string subyear2 = date2.substr(6, 10); 
	string submonth2 = date2.substr(0, 2); 
	string subday2 = date2.substr(3, 2); 
	int year_stoi2 = stoi(subyear2); 
	int month_stoi2 = stoi(submonth2);
	int day_stoi2 = stoi(subday2);

	int vectsize = appsvect.size();
	int pos = 0;
	int lineout = 0; 
	while (pos < vectsize)
	{
		if ((appsvect[pos]->occurs_on(month_stoi2, day_stoi2, year_stoi2)))
		{
			cout << lineout << " ";
			appsvect[pos]->print();
			lineout++;
		}
		pos++;
	}
	cout << endl; 
	for (int i = 0; i < vectsize; i++) 
	{
		delete appsvect[i];
	} 

	

	system("pause");
	return 0;
}