/*
Description: User inputs travel time in seconds & miles per hour, program outputs distance travelled and the total time of travel in years, days, hours, minutes, and seconds.
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main()
{

	long const int secondsinyear = 31536000;
	const int secondsinhour = 3600;
	const int secondsinminute = 60;
	const int minutesinhour = 60;
	const int hoursinday = 24;

	
	long int travelseconds;
	long double mph;


	cout << "Please give me your total time of travel in seconds: ";
	cin >> travelseconds;
	cout << "Please give me your speed in miles per hour: ";
	cin >> mph;

	double sectohrs = (double)travelseconds / secondsinhour; 


	cout << "--- Distance ---" << endl;
	cout << "Your distance traveled is: " << sectohrs * mph << " miles." << endl; 


	int year = travelseconds / secondsinyear;						
	travelseconds = travelseconds % secondsinyear;					
	int day = travelseconds / (hoursinday * secondsinhour);			
	travelseconds = travelseconds % (hoursinday * secondsinhour);	
	int hour = travelseconds / secondsinhour;						
	travelseconds = travelseconds % secondsinhour;					
	int minutes = travelseconds / minutesinhour;					
	travelseconds = travelseconds % secondsinminute;
	int seconds = travelseconds;

	
	cout << "--- Time ---" << endl;
	cout << "Years:" << year << "  Days:" << day << "  Hours:" << hour << "  Minutes:" << minutes << "  Seconds:" << seconds << endl;

	system("pause");
	return 0;

}
