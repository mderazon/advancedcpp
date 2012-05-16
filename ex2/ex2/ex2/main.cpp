#include "stdafx.h"
#include "calendar.h"

using namespace std;

// converts a time in the format hh:mm into a time_t object
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


int main()
{
	// create a base calendar
	calendar* cal = new calendar();	
	try
	{
		//create couple of base meetings
		meeting* m1 = new meeting("Subject 1", getTime(1, "10:00"),getTime(1, "12:00")); // good meeting
		//meeting* m2 = new meeting("Subject 2", getTime(1, "12:00"),getTime(1, "10:00")); // bad meeting - end time < start time
		meeting* m3 = new meeting("Subject 3", getTime(1, "11:00"),getTime(1, "13:00")); // bad meeting - conflicts with meeting 1
		meeting* m4 = new meeting("Subject 4", getTime(3, "10:00"),getTime(3, "12:00")); // good meeting
		// add meetings to calendar
		cal->addMeeting(1,m1);
		//cal->addMeeting(1,m2);
		cal->addMeeting(1,m3);
		cal->addMeeting(3,m4);
	}
	catch (int exception)
	{
		if (exception == conflicting_meetings_error)
		{
			cout << "Error: Conflicting meetings";
			exit(conflicting_meetings_error);
		}
		else if (exception == incorrect_meeting_error)
		{
			cout << "Error: Incorrect meeting info";
			exit(incorrect_meeting_error);
		}
	}
	

	// Main menu
	//int choice;
	//while(1)  {
	//	cout <<  "1. Add meeting."		<< endl ;            
	//	cout <<  "2. Remove meeting." 	<< endl ;           
	//	cout <<  "3. Clean Calendar."	<< endl ;         
	//	cout <<  "4. Find meeting."		<< endl ;       
	//	cout <<  "5. Print Calendar."	<< endl ;           
	//	cout <<  "6. Quit." 			<< endl ;      
	//	cout <<  "Enter your choice:"	<< endl ;      
	//	
	//	cin >> choice;

	//	switch (choice)
	//	{
	//	case 1:		 
	//		//addMeeting ());
	//		break; 			
	//	case 2:		
	//		//rmvMeeting();
	//		break;
	//	case 3:
	//		//cleanCalendar();
	//		break;
	//	case 4:
	//		//findMeeting();
	//		break;
	//	case 5:
	//		//printCalendar();
	//		break;
	//	case 6:
	//		exit(0);
	//	}		
	//}
}

