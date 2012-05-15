#include "stdafx.h"
#include "calendar.h"

using namespace std;
int main()
{
	int choice;
	while(1)  {
		cout <<  "1. Add meeting."		<< endl ;            
		cout <<  "2. Remove meeting." 	<< endl ;           
		cout <<  "3. Clean Calendar."	<< endl ;         
		cout <<  "4. Find meeting."		<< endl ;       
		cout <<  "5. Print Calendar."	<< endl ;           
		cout <<  "6. Quit." 			<< endl ;      
		cout <<  "Enter your choice:"	<< endl ;      
		
		cin >> choice;

		switch (choice)
		{
		case 1:		 
			//addMeeting ());
			break; 			
		case 2:		
			//rmvMeeting();
			break;
		case 3:
			//cleanCalendar();
			break;
		case 4:
			//findMeeting();
			break;
		case 5:
			//printCalendar();
			break;
		case 6:
			exit(0);
		}		
	}
}

std::time_t getTime(int day, std::string time)
{
	int h, m;
	sscanf_s(time.c_str(), "%d:%d", &h, &m);
	struct tm timeinfo;
	timeinfo.tm_hour = h;
	timeinfo.tm_min = m;
	timeinfo.tm_year = 2012;
	timeinfo.tm_mday = 12 + day;
	timeinfo.tm_sec = 0;
	timeinfo.tm_year = 112;
	timeinfo.tm_mon = 4;
	
	return std::mktime(&timeinfo);
}

meeting * createMeeting(int day, std::string time)
{
	time_t t = getTime(day, time);
	return NULL;
}