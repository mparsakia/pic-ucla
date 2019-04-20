/*

Assignment Prompt: Junk mail program.
*/

#include <iostream> 
#include <string> 
#include <cstring> 
#include <sstream> 
#include <fstream> 
#include <vector> 
#include <cstdlib> 
#include <cctype> 
#include <iomanip> 


using namespace std; 
void replace_in_string(string &string_in, string findthis, string putthis) 
{
	int position = 0;
	int find_length = findthis.length();
	int put_length = putthis.length();   

	while ((position = string_in.find(findthis, position)) != -1)	
	{
		string_in.replace(position, find_length, putthis); 
			position = position + put_length;  
	}
	return; 
}  



int main() {
		
	ifstream tf; 
	ifstream dbf;
	string template_path = "template.txt"; 
	string database_path = "database.txt"; 

	tf.open(template_path.c_str()); 
	dbf.open(database_path.c_str());

	dbf.seekg(0, ios::end); 
	long long dbsize = dbf.tellg(); 
	if (dbsize == 0) 
	{
		cout << "The database database.txt is empty. Exit!\n";
		tf.close(); 
		dbf.close();
		return 1; 
	}
	
	dbf.close(); 
	dbf.open(database_path.c_str());

	
	if (!dbf.fail()) 
	{
		if (dbf.is_open())
		{
			cout << "Database Content: \n";
			while (!dbf.eof())
			{
				string s; 
				getline(dbf, s);
				cout << s << endl;
			}
		}
	}
	dbf.close();							
	dbf.open(database_path.c_str());
	cout << endl;

	if (!tf.fail()) 
	{
		if (tf.is_open())
		{
			cout << "Template Content: \n";
			while (!tf.eof())
			{
				string s;
				getline(tf, s);
				cout << s << endl;
			}
		}
	}
	cout << endl;
	tf.close();
	tf.open(template_path.c_str()); 
	string empty;			
	int linecount = 0;
	while (getline(dbf, empty))
	{
		linecount++;
	} 
	dbf.close();
	dbf.open(database_path.c_str());
	
	string dbcontent;
	getline(dbf, dbcontent,'\0');  
	dbf.close();
	dbf.open(database_path.c_str());  
	
	for (int i = 0; i < dbcontent.length(); i++)
	{
		if (dbcontent[i] == '\n')
		{
			dbcontent[i] = '|';
		}
	}      
	string dbtxt_f; 
	stringstream dbss(dbcontent); 
	vector<string> dbwords; 
	bool pushempty = false; 
									
	
	while (!dbss.eof())						
	{		
		getline(dbss, dbtxt_f, '|'); 
		if (dbtxt_f == "")
		{
			if (pushempty) 
			{
				dbwords.push_back(dbtxt_f);
			}
		}
		else
		{
			dbwords.push_back(dbtxt_f);
		}
	}
	dbf.close();      


	string tlines;
	int tlinecount = 0;
	while (getline(tf, tlines))
	{
		tlinecount++;
	} 
	tf.close();
	tf.open(template_path.c_str());



	int offset_vector = 0;					
	for (int i = 0; i < linecount; i++)		
	{										
		cout << "\nJunk letter for Record " << i << "\n\n";
		string title_1 = dbwords[0 + offset_vector];
		string firstname_2 = dbwords[1 + offset_vector];
		string lastname_3 = dbwords[2 + offset_vector];
		string street_4 = dbwords[3 + offset_vector];
		string city_5 = dbwords[4 + offset_vector];
		string state_6 = dbwords[5 + offset_vector];
		string zip_7 = dbwords[6 + offset_vector];

		string tfcontent;
		getline(tf, tfcontent,'\0');
	
		replace_in_string(tfcontent, "|1|", title_1);
		replace_in_string(tfcontent, "|2|", firstname_2);
		replace_in_string(tfcontent, "|3|", lastname_3);
		replace_in_string(tfcontent, "|4|", street_4);
		replace_in_string(tfcontent, "|5|", city_5);
		replace_in_string(tfcontent, "|6|", state_6);
		replace_in_string(tfcontent, "|7|", zip_7);
		
		cout << tfcontent;
		tf.close();
		tf.open(template_path.c_str());
		cout << endl;
				
		offset_vector = offset_vector + 7; 
	}
	cout << endl;
	tf.close(); 
	system("pause");
	return 0;
} 