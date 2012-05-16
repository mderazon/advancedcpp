#include "stdafx.h"
#include "calendar.h"

using namespace std;

// converts a time in the format hh:mm into a time_t object. day is 1-7
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

// return day of the week from time_t type
int getDay(meeting* m)
{
	std::time_t t = m->getStartHour();
	struct tm *tm = std::localtime(&t);
	return tm->tm_wday + 1;
}

int runCalendarExample()
{
	// create a base calendar
	calendar* cal = new calendar();	
	try
	{
		//create couple of base meetings
		meeting* m1 = new meeting("Subject 1", getTime(1, "10:00"),getTime(1, "12:00"));	// good meeting
		meeting* m2 = new meeting("Subject 2", getTime(1, "14:00"),getTime(1, "16:00"));	// good meeting
//		meeting* m3 = new meeting("Subject 3", getTime(1, "12:00"),getTime(1, "10:00"));	// bad meeting - end time < start time
		meeting* m4 = new meeting("Subject 4", getTime(1, "11:00"),getTime(1, "13:00"));	// bad meeting - conflicts with meeting 1
		meeting* m5 = new meeting("Subject 5", getTime(3, "10:00"),getTime(3, "12:00"));	// good meeting
		// add meetings to calendar
		cal->addMeeting(getDay(m1),m1);
		cal->addMeeting(getDay(m2),m2);
		//		cal->addMeeting(getDay(m3),m3);	// should raise INCORRECT_MEETING_VALUES_ERROR
		//		cal->addMeeting(getDay(m4),m4);	// should raise CONFLICTING_MEETINGS_ERROR
		cal->addMeeting(getDay(m5),m5);
		cout << cal->printCalendar();
		// remove meetings from calendar
		cal->removeMeeting(getDay(m1),m1);



	}
	catch (int exception)
	{
		if (exception == CONFLICTING_MEETINGS_ERROR)
		{
			cout << "Error: Conflicting meetings";
			exit(CONFLICTING_MEETINGS_ERROR);
		}
		else if (exception == INCORRECT_MEETING_VALUES_ERROR)
		{
			cout << "Error: Incorrect meeting info";
			exit(INCORRECT_MEETING_VALUES_ERROR);
		}
	}
	return 0;
}

void extendedCalendarExample()
{

}

int main()
{
	runCalendarExample();
	

	// Main menu
	int choice;
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

